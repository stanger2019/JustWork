#include "server_main.h"
using namespace std;
Network net(3425);//создание обьекта работы с сетью на порт 3425
int main(){
    net.main();//запуск основного цикла работы с сетью
}