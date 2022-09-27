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