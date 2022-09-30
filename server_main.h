//JW project
//mod from 27.09.2022 by Sam Stanger
//Workable
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include"errs.h"

using namespace std;

class Network{//класс основной сетевой работы.
    private:
        int port;
        int sock,listener;
        struct sockaddr_in addr;
        char data[1024];
        int bytes_read;

        void sock_check(int obj){//проверка на ошибки инициализации сокета
            if(obj = 0){
                Errs err(1);
            }
        }

        void bind_check(int obj){//проверка на ошибки настройки подключений
            if(obj = 0){
                Errs err(2);            
            }
        }
        void accept_check (int obj){
            if(sock < 0){
                Errs err(3);
            }
        }
    public:
    void main(){//функция основного цикла сетевой работы
        listen(listener,1);
        cout<<"main_started"<<endl;//отладочный вывод
         while(true)//цикл ожидания входящего подключения 
    {
        cout<<"1"<<endl;//отладочный вывод
        sock = accept(listener, NULL, NULL);//перевод подключения на отдельный идентификатор
        accept_check(sock);
        while(1)//цикл работы с клиентом
        {
            cout<<"2"<<endl;//отладочный вывод
            bytes_read = recv(sock, data, 1024, 0);//чтение входящий информации с сокетa
            if(bytes_read <= 0) break;
            send(sock, data, bytes_read, 0);//отправка информации клиенту
            
        }
    }
    }

    Network(int port_in){//при инициализации инициализируется сокет и настройка подключений
        port = port_in;
        listener = socket(AF_INET,SOCK_STREAM,0);
        sock_check(listener);
        cout<<"sock_check ok"<<endl;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        int bind_out = bind(listener, (struct sockaddr *)&addr, sizeof(addr));
        bind_check(bind_out);
        cout<<"bind_check_ok"<<endl;
    }
};


