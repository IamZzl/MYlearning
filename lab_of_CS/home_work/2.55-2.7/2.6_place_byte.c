#include<stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){

    unsigned y = 0x000000ff;
   y =  y << 8*i;
    x = (x & ~y)  + ((unsigned)b << 8*i);
    return x;
    
    

}
int main(){
    unsigned char b;
    unsigned x;
    int ii;
    scanf("%x %hhu %d",&x,&b,&ii);
   
   

    
    printf("%x",replace_byte(x,ii,b));
}