#include<stdio.h>
#include<bal.h>

int main(){
    int lval = 0xfedcba98 << 32;
    int aval = 0xfedcba98 >> 36;
    unsigned uval = 0xfedcba98u >> 40;
    printf("%d,%d,%d",lval,aval,uval);
}