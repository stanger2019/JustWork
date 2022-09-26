#include <sys/types.h>
#include <sys/socket.h>
int bind(int sockfd, struct sockaddr *addr, int addrlen);

int main()
{
    socket(AF_INET,SOCK_STREAM,0);
    return 0;
}