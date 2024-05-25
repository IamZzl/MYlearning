#ifndef BAL_H
#define BAL_H
#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer ,size_t);
void show_float(float *);
void show_int (int *);
void show_double(double *);

void show_bytes(byte_pointer start, size_t len){
    for(size_t i = 0; i< len; i++){
        printf("%.2x",start[i]); 
    }
    printf("\n");
}

void show_float(float *x){
    show_bytes((byte_pointer)x,sizeof(float));
}

void show_int(int *x){
    show_bytes((byte_pointer)x,sizeof(int));
}

void show_double(double *x){
    show_bytes((byte_pointer)x,sizeof(double));
}

#endif

