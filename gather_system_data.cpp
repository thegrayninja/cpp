//to compile:
//g++ -W -Wall -o TestLinux -p test_linux.cpp
//to run:
//chmod +x TestLinux; ./TestLinux
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;


string GetStdoutFromCommand(string cmd) 
{
  std::string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
    }
  return data;
}


string RemoveNewLines(string Text)
{

int n=0;

for(unsigned int i=0;i<Text.length();i++){
    std::cout<<Text[i]<<endl;
    if(Text[i]=='.'){
        n++;//we increase the number of newlines we have found so far
        std::cout<<Text[i]<<endl;
    }else{
        Text[i-n]=Text[i];
        
    }
  }
  return Text;
}


void SendCurlAddComputer(string JsonData)
{
  string CurlString;
  CurlString = "curl -H \"Authorization: api-key: 7dcbd3b4-20f4-4f61-a914-34342fcabf9f\" -H \"content-Type: application/json\" --request POST --data '" + JsonData + "' 178.128.128.238/api/computers";
  GetStdoutFromCommand(CurlString);
  //cout<<CurlString<<endl;
}

int main()
{
  std::string PrivateIP;
  std::string PublicIP;
  std::string SystemInfo;
  std::string JsonPrivateIP;
  std::string JsonPublicIP;
  std::string JsonHostname;
  std::string JsonSystemInfo;
  std::string JsonData;
  

  //IPAddress.erase(std::remove(IPAddress.begin(), IPAddress.end(), '\n'), IPAddress.end());
  //for(unsigned int i=0;i<IPAddress.length();i++) if(IPAddress[i]=='\r') IPAddress.erase(IPAddress.begin()+i);
    std::cout<<PrivateIP[0]<<endl;

//PrivateIP.resize(PrivateIP.length()-n);//to delete only once the last n elements witch are now newlines

  std::string Hostname;
  std::string Services;
  std::string Json;
  //IPAddress = system("echo -n '1. Current Directory is '; pwd");
  GetStdoutFromCommand("hostname -i | tee private_ip.tmp");
  GetStdoutFromCommand("hostname | tee hostname.tmp");
  GetStdoutFromCommand("echo 10.2.2.2 > public_ip.tmp");
  GetStdoutFromCommand("ls /etc/init.d/ -m | tee system_info.tmp");

  string line;
  ifstream myfile ("private_ip.tmp");
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
        PrivateIP = line; //cout << line << endl;
    }
  myfile.close();
  }

  ifstream myfilea ("hostname.tmp");
  if (myfilea.is_open())
  {
    while (getline(myfilea,line))
    {
        Hostname = line; //cout << line << endl;
    }
  myfilea.close();
  }

  ifstream myfileb ("public_ip.tmp");
  if (myfileb.is_open())
  {
    while (getline(myfileb,line))
    {
        PublicIP = line; //cout << line << endl;
    }
  myfileb.close();
  }

  ifstream myfilec ("system_info.tmp");
  if (myfilec.is_open())
  {
    while (getline(myfilec,line))
    {
        SystemInfo += line; //cout << line << endl;
    }
  myfilec.close();
  }


  //PrivateIP = RemoveNewLines(PrivateIP);

cout << "ok" << endl;


  //Hostname = GetStdoutFromCommand("hostname");
  //Services = GetStdoutFromCommand("ls /etc/init.d/ -m");
  //std::cout << "Just verifying my code works" << std::endl;
  //std::cout << PrivateIP << std::endl;
  //std::cout << Hostname << std::endl;
  //std::cout << Services << std::endl;
  JsonPrivateIP = "\"private_ip\":\"" + PrivateIP + "\"";
  JsonPublicIP = "\"public_ip\":\"" + PublicIP + "\"";
  JsonHostname = "\"hostname\":\"" + Hostname + "\"";
  JsonSystemInfo = "\"system_info\":\"" + SystemInfo + "\"";
  JsonData = "{" + JsonPrivateIP + "," + JsonPublicIP + "," + JsonHostname + ",\"operating_system\":\"unknown\"," + JsonSystemInfo + "}";
    //"{\"ip_address\":\"" + IPAddress + "\"}"
  //std::cout << JsonData << std::endl;
  SendCurlAddComputer(JsonData);
  std::cout << "done!" << endl;
  return 0;
}



