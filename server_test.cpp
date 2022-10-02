#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
using namespace std;

int main(){
int listener = socket(AF_INET,SOCK_STREAM,0);
cout<<"listener started"<<endl;
sockaddr_in sckddr;
sckddr.sin_addr.s_addr = ntohl(INADDR_ANY);
sckddr.sin_family = AF_INET;
sckddr.sin_port  = htons(2000);
int bnd = bind(listener,(struct sockaddr *)&sckddr,sizeof(sckddr));
cout<<"binded"<<endl;
int lst = listen(listener,1);
sockaddr_in ac_sckddr;
socklen_t *ac_sckddr_langht;
while(true){
int accept_socket = accept(listener,(struct sockaddr *)&ac_sckddr,ac_sckddr_langht);
cout<<"accepted"<<endl;
cout<<"client IP: "<< inet_ntoa(ac_sckddr.sin_addr)<<endl;
cout<<"client port: "<<ntohs(ac_sckddr.sin_port)<<endl;
}
return 0;
}