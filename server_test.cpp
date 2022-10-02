#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
using namespace std;

class Network{
    private:
    int listener,bnd,lst;
    sockaddr_in sckddr,ac_sckddr;
    socklen_t *ac_sckddr_langht;
    public:
    void accpt(){
        int accept_socket = accept(listener,(struct sockaddr *)&ac_sckddr,ac_sckddr_langht);
        cout<<"accepted"<<endl;
        cout<<"client IP: "<< inet_ntoa(ac_sckddr.sin_addr)<<endl;
        cout<<"client port: "<<ntohs(ac_sckddr.sin_port)<<endl;
        /*clientProcessing();*/
    }
    Network(int port){
        listener = socket(AF_INET,SOCK_STREAM,0);
        sckddr.sin_addr.s_addr = ntohl(INADDR_ANY);
        sckddr.sin_family = AF_INET;
        sckddr.sin_port  = htons(port);
        bnd = bind(listener,(struct sockaddr *)&sckddr,sizeof(sckddr));
        lst = listen(listener,1);

    }
};
Network net(2000);
int main(){
    while(true){
    net.accpt();
    }
}