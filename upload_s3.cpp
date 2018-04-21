##git having trouble forking/starring a profile
##not taking credit, but didn't want to lose this code..just in case
##copied the raw from: https://gist.github.com/toneill818/d90c85a453d935e7e9aed6eab1d75f8a


#include <aws/core/Aws.h> 			// Needed for InitAPI, SDKOptions, Logging, and ShutdownAPI
#include <aws/transfer/TransferClient.h> 	// Needed for the TransferClient
#include <aws/transfer/UploadFileRequest.h> 	// Needed to get the status of UploadFile
#include <aws/transfer/DownloadFileRequest.h> 	// Needed to get the status of DownloadFile
#include <iostream>

using namespace Aws::Transfer;

/*
 * Example of how to download and upload using the Transfer Client
*/
int main(){
	// Initialize the API
	Aws::SDKOptions options;
	options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
	Aws::InitAPI(options);

	// Create a Transfer Client Configuration
	TransferClientConfiguration tcc;

	// Create the transfer client giving
	TransferClient tc(std::make_shared<Aws::S3::S3Client>(), tcc);


	const Aws::String bucket_name 	= "ni-file-server-backup";
	const Aws::String content_type 	= "";
	const Aws::String file_name 	= "main.cpp";
	const Aws::String key_name 	= "main.cpp";

	// Upload main.cpp to S3, the two false parameters at the end are optional (createbucket and doConsistencyChecks)
	auto uploadRequest = tc.UploadFile(file_name, bucket_name, key_name, content_type, false, false);
	// Wait until the upload is finished
	uploadRequest->WaitUntilDone();
	// Check for success
	if(!uploadRequest->CompletedSuccessfully()){
		std::cerr << uploadRequest->GetFailure();
	}

	const Aws::String download_file_name = "s3.cpp";
	// Download the file from S3 and save it to disk
	auto downloadRequest = tc.DownloadFile(download_file_name, bucket_name, key_name);
	// Wait until the download is complete
	downloadRequest->WaitUntilDone();
	// Check for a successful download
	if(!downloadRequest->CompletedSuccessfully()){
		std::cerr << downloadRequest->GetFailure();
	}

	// Shutdown the API before the program ends
	Aws::ShutdownAPI(options);
	return 0;
}
