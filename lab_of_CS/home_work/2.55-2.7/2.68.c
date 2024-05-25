#include<stdio.h>

int low_one_mask(int n){
    int x = 0xffffffff;
    x = x<<(n-1);
    x = x<<1;
    return ~x;
}

int main(){
   printf("%x \n%x",low_one_mask(6),low_one_mask(17)) ;
}