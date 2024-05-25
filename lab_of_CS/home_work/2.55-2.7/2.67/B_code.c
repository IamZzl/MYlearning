#include <stdio.h>

int goog_int_size_is_32(){
    /*Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1<<31;
    /*Shift past msb of 32-bit word*/
    int beyond_msb = 1 << 31;
    beyond_msb = beyond_msb << 1;
    /*set_msb is nonzero when word size >= 32
      beyound_msb id zero when word size <=32*/

}

int goog_int_size_is_32(){
    /*Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1<<15;
    set_msb =  set_msb << 15;
    set_msb =  set_msb <<1;
    /*Shift past msb of 32-bit word*/
    int beyond_msb = 1 << 15;
    beyond_msb = beyond_msb << 15;
    beyond_msb = beyond_msb << 2;
    /*set_msb is nonzero when word size >= 32
      beyound_msb id zero when word size <=32*/

}


int main(){

}