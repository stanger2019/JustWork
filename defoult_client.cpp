#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>
#include<iostream>
#include<netdb.h>
#include <arpa/inet.h>
using namespace std;
struct sockaddr_in server;
char message[] = "Hello there!\n";
char buf[sizeof(message)];
char addres[] = "89.108.99.49";
int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }
    inet_aton(addres,(struct in_addr *)&addr.sin_addr);
    cout<<inet_ntoa(addr.sin_addr)<<endl;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2000); // или любой другой порт...
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);
    
    printf(buf);
    //close(sock);

    return 0;
}