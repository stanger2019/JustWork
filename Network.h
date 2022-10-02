//JW project
//mod from 27.09.2022 by Sam Stanger
//Workable
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
//#include"Errs.h"
#include"Client.h"
#include<linux/errqueue.h>


using namespace std;

class Network{//класс основной сетевой работы.
    private:
        int listener,bnd,lst;
        sockaddr_in sckddr,ac_sckddr;
        socklen_t *ac_sckddr_langht;

        void sock_check(int obj){//проверка на ошибки инициализации сокета
            if(obj == 0){
                Errs err(1);
            }
        }

        void bind_check(int obj){//проверка на ошибки настройки подключений
            if(obj == -1){
                Errs err(2);            
            }
        }
        void accept_check (int obj){
            if(obj == 0){
                Errs err(3);
            }
        }
    public:
    void accpt(){
        cout<<listener<<endl;
        int accept_socket = accept(listener,(struct sockaddr *)&ac_sckddr,ac_sckddr_langht);
        cout<<accept_socket<<endl;
        accept_check(accept_socket);
        Client client(accept_socket);
        cout<<"accepted"<<endl;
        cout<<"client IP: "<< inet_ntoa(ac_sckddr.sin_addr)<<endl;
        cout<<"client port: "<<ntohs(ac_sckddr.sin_port)<<endl;
        client.processing();
    }
    Network(int port){
        listener = socket(AF_INET,SOCK_STREAM,0);
        sock_check(listener);
        sckddr.sin_addr.s_addr = ntohl(INADDR_ANY);
        sckddr.sin_family = AF_INET;
        sckddr.sin_port  = htons(port);
        bnd = bind(listener,(struct sockaddr *)&sckddr,sizeof(sckddr));
        bind_check(bnd);
        lst = listen(listener,1);
    }
};
