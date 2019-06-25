#include<iostream>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/ip.h>
#include <string>

using namespace std;

int main(){

    int client, server, i;
    int portNum = 1491;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    struct sockaddr_in server_addr;
    socklen_t size;

    client = socket(AF_INET, SOCK_STREAM, 0);

   if (client < 0){

    cout << "Something went wrong while creating socket." << endl;
    exit(1);
    }

    cout << "Server Socket connection created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);



    if (bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){

    cout << "Error binding socket...." << endl; 
    exit(1);
    }

    size = sizeof(server_addr);
    cout << "Looking for clients..." << endl;



    listen(client, 1);


    server = accept(client, (struct sockaddr*)&server_addr, &size);

    if (server < 0){
        cout << "Error on accepting.." << endl;
        exit(1);
    }

    cout << "Connected with client..." << endl;
    system("clear");

    while(true){
        cout << "Enter your message:\n" << endl;
        cin >> buffer;
        send(server, buffer, bufsize, 0);
        system("clear");
    }

return 0;
}