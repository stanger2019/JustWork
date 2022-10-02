//JW project
//mod. from 27.09.2022 by Sam Stanger
//workable
#include <iostream>
using namespace std;
class Errs{//класс - обработчик ошибок
    private:
        string err_str;
        int err_code;
        void codeToStr(int code){//перевод int  кода ошибки в строку - пояснение
            switch(err_code){
                case 1://ошибка инициализации сокета
                    err_str = "socket_err";
                break;
                case 2://ошибка настройки соединений
                    err_str = "bind_err";
                break;
                case 3:
                    err_str = "accept_err";//ошибка установки соединения 
                break;
                case 4:
                    err_str = "empty hoststruct";//попытка обращения к пустой хостструктуре
                break;
                case 5:
                    err_str = "hostconstructing by name failed";//ошибка получения хостконструкта по имени
                break;
                case 6:
                    err_str = "net_sending error";
                break;
                case 7:
                    err_str = "net_reading error";
                break;
                default://прочие ошибки
                    err_str = "unknown_err";
                break;
            }
        }
    public:
    Errs(int  code){//инициализация класса = завершению программы с ошибкой
        err_code = code;
        codeToStr(err_code);
        cerr<<err_str<<endl;
        exit(err_code);
        }
    
};