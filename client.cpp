#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<string>

using namespace std;

int main(){

    int client, server, i;
    int portNum = 1491;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
    cout << "Something went wrong while creating socket." << endl;
    exit(1);
    }

cout << "Client socket created..." << endl;

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(portNum);
server_addr.sin_addr.s_addr = htons(INADDR_ANY);


if (connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0)

{
    cout << "CONNECTED...";
    system("clear");
    while(true){
        
     recv(client, buffer, bufsize, 0);

     buffer[bufsize] = '\0';
     cout << "Message: " << buffer << endl;
}
 close(client);
}
return 0;
}