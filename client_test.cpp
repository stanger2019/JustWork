//тестовый клиент
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include<string>
#include<cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;
string inputString;

char *stringToCharArray(string inputString){
    int n = inputString.length();
    char inputCharArrey[n+1];
    strcpy(inputCharArrey,inputString.c_str());
    return inputCharArrey;
}

int main()
{
    string inputString;
    int sock;
    struct sockaddr_in addr;
    char buf[1024];
    cin>>inputString;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); 
    in_addr *adr;
    inet_aton("25.21.218.252",adr);
    addr.sin_addr.s_addr = htonl(adr->s_addr);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(sock, stringToCharArray(inputString), sizeof(stringToCharArray(inputString)), 0);
    recv(sock, buf, sizeof(stringToCharArray(inputString)), 0);
    
    for (int i = 0; i < 1024;i++)
    {
        cout<<buf[i]<<endl;
    }
    
    
    //close(sock);

    return 0;
}