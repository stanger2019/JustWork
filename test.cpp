#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char Array[10][8192];


char *stringToCharArray(string inputString){
    int n = inputString.length();
    char inputCharArrey[n+1];
    strcpy(inputCharArrey,inputString.c_str());
    return inputCharArrey;
}


int main(){
    for (int i = 0; i < 10; i++)//заполнения матрицы пустыми символами
    {
        for (int j = 0; j < 8192; j++)
        {
            Array[i][j] =NULL;
        }
    }
    


    string inputString;//входящая строка
    cin>>inputString;//получение входящей строки
    if (inputString.length()>8192*10+1)//проверка на превышения максимальной длины строки
    {
        cout<<"Oversize"<<endl;//вывод сообщения об ошибке
        exit(1);//выход из программы с ошибкой
    }
    int n = inputString.length();//получение количества символов в строке
    char bigArray[n+1];//создание промежуточного единого массива 
    strcpy(bigArray,inputString.c_str());//перенос символов в единый массив
    int lineAmount = n/8192;//получение количества заполненых строк будущей матрицы
    if((n+1)%8192!= 0){//добавка для покрытия остатка
        lineAmount++;
    }
    int balance = n+1;//количество оставшихся символов
    int number = 0;//номер текущего символа
    for (int i = 0; i < balance; i++)
    {
        cout<<bigArray[i]<<endl;
    }
    
    for (int i = 0; i < lineAmount; i++)//основной цикл заполнения матрицы
    {
        if(balance>=8192){
            for (int j = 0; j < 8192; j++)//заполнение всех строк кроме последней 
            {
                Array[i][j] = bigArray[number];
                balance--;
                number++;
            }
        }
        else{
            for (int j = 0; j <= n+1; j++)//заполнение последней строки
            {
                cout<<j<<endl;
                Array[i][j] = bigArray[number];
                balance--;
                number++;
            }
        }
    }
    
    for (int i = 0; i < 10; i++)0//отладочный вывод
    {
        for (int j = 0; j < 8192; j++)
        {
            cout<<" "<<Array[i][j];
        }
        cout<<endl;
    }
    

    return 0;
}