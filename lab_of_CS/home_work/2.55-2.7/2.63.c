#include<stdio.h>


unsigned srl(unsigned x, int  k){
    /*Perform shift arithmetically*/
    unsigned xsra = (int)x >> k;
    unsigned x2 = 0xffffffff;

    x2 =~(x2<<(64-k));
    xsra = xsra & x2;
    return xsra;
}



int main(){
    unsigned  x = 0x80000000;
    printf("%x",srl(x,4));

}