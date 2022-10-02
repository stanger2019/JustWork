#include "server_main.h"
using namespace std;
Network net(2000);//создание обьекта работы с сетью на порт 3425
int main(){
    net.main();//запуск основного цикла работы с сетью
}