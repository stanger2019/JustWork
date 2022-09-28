//JW project
//mod.from 28.09.2022 by Sam Stanger
//partially workable
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include"errs.h"
#define ADR 101
#define NAME 100
using namespace std;
struct hostent *host;

class Dns{//класс работы с dns
    public:

        hostent *get_hoststruct(){//функция возврата 
            if(!hoststruct_ready_flag){//проверка на обращение к пустому хостконструкту
                Errs err(4);
            }
            return hoststruct;
        }
        Dns(const char *name){//создание обьекта  = инициализации хостконструкта
            set_hoststruct(NAME,name);
        }
    private:
        void set_hoststruct(int mode,const char *in_str){//общая функция создания хостконструкта(в последствии планируется добавление созднаия через IP)
            switch (mode){
                case 101:
                    set_hoststruct_by_addr(in_str);
                break;
                case 100:
                cout<<in_str<<endl;
                    set_hoststruct_by_name(in_str);
                break;
            }
        }
        void set_hoststruct_by_addr(const char *addr){//функция создания хостконструкта через IP(неактивно)
            //hoststruct = gethostbyaddr(addr);
            

        }   
        void set_hoststruct_by_name(const char *name ){//функция создания хостконструкта по имени
            hoststruct = gethostbyname(name);
            cout<<hoststruct->h_name<<endl;
            if(NULL == hoststruct) Errs err(5);
            hoststruct_ready_flag = true;
        }
        hostent *hoststruct;
        bool hoststruct_ready_flag = false;
};