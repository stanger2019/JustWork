const int size = 1024;
char  message[size] = "HI";
void generate()
{
    int x = 0;
    while (x<size)
    {
        message[x] = x;
        x++;
    }
    
}