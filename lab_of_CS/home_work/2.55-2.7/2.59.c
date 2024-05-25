#include<stdio.h>
typedef unsigned long int  num;
num oper(num x,num y){
    return (x & 0x000000ff) + ( y & 0xffffff00);
}
int main(){
    num x=0x89ABCDEF;
    num y = 0x76543210;
    printf("%llx\n",x & 0x000000ff);
    printf("%llx\n", y & 0xffffff00);
    printf("%llx",oper(x,y));
    return 0;
} 