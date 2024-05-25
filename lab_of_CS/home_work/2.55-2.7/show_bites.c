#include<stdio.h>

void show_bytes( char * p , size_t len){
    //将数据按照在内存中的位序列打印
    size_t j = 0;
    for(j ; j<len; j++)
    {
        printf("%.3x ", p[j]);
    }
}

void show_int_by( int  a)
{
    show_bytes(( char*)&a,sizeof(int));
}


int main(){
    int b = 0x16;
    
    show_int_by(b);
}