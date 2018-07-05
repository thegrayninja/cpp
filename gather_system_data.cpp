//to compile:
//g++ -W -Wall -o TestLinux -p test_linux.cpp
//to run:
//chmod +x TestLinux; ./TestLinux
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

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




int main()
{
  std::string IPAddress;
  

  //IPAddress.erase(std::remove(IPAddress.begin(), IPAddress.end(), '\n'), IPAddress.end());
  //for(unsigned int i=0;i<IPAddress.length();i++) if(IPAddress[i]=='\r') IPAddress.erase(IPAddress.begin()+i);
    std::cout<<IPAddress[0]<<endl;
int n=0;
for(unsigned int i=0;i<IPAddress.length();i++){
    std::cout<<IPAddress[i]<<endl;
    if(IPAddress[i]=='.'){
        n++;//we increase the number of newlines we have found so far
        std::cout<<IPAddress[i]<<endl;
    }else{
        IPAddress[i-n]=IPAddress[i];
        
    }
}
IPAddress.resize(IPAddress.length()-n);//to delete only once the last n elements witch are now newlines

  std::string Hostname;
  std::string Services;
  std::string Json;
  //IPAddress = system("echo -n '1. Current Directory is '; pwd");
  IPAddress = GetStdoutFromCommand("hostname -i");
  Hostname = GetStdoutFromCommand("hostname");
  Services = GetStdoutFromCommand("ls /etc/init.d/ -m");
  std::cout << "Just verifying my code works" << std::endl;
  std::cout << IPAddress << std::endl;
  std::cout << Hostname << std::endl;
  std::cout << Services << std::endl;
  Json = "{\"ip_address\":\"" + IPAddress + "\"}";
  std::cout << Json << std::endl;
  return 0;
}



