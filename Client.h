#include"Errs.h"
#include<iostream>
#include <sys/types.h>
#include <sys/socket.h>

class Client{
    private:
        int sock;
        char buf[1024];
        void sendall(char *buf, int len, int flags){
            int total = 0;
            int n;
            while(total < len){
                n = send(sock, buf+total, len-total,flags);
                if(n == -1) {
                      Errs err(6);
                }
                total += n;
            }
        }
        void readall(char *buf,int len,int flags){
            /*int total = 0;
            int n;
            while(total<len){
                n = recv(sock,buf+total,len-total,flags);
                if(n == -1){
                    Errs err(7);
                }
                total += n;
            }*/
            recv(sock,buf,len,flags);
        }
    public:
    void processing(){
        cout<<sock<<endl;
        //readall(buf,1024,0);
        cout<<recv(sock,buf,1024,0)<<endl;
        cout<<buf;
    }
    Client(int sock_in){
        sock = sock_in;
    }
};