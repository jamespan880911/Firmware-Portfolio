#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void add(int *a, int *b){
    int sum, carry;
    int x = *a;
    int y = *b;

    while (y != 0){
        //1.計算不進位的和
        sum = x ^ y;
        
        //2.模擬進位
        carry = (x & y) << 1;

        //3.更新
        x = sum;
        y = carry;
    }

    *a = x;        //把結果存回a
}

int mod(int a, int b){
    if (b == 0){
        return -1;
    }

    while (a >= b){
        a -= b;
    }

    return a;
}

void Execute_Selection(int n){
    void (*function_select[])(void) = {NULL, fun1, fun2, fun3, fun4, fun5};

    if (n >= 1 && n <= 5){
        function_select[n]();
    }
}

int setbit(int num, int n){
    return num |= (1 << n);
}

unsigned short swap_16(unsigned short val){
    return (val << 8) | (val >> 8);
}

unsigned int swap_32(unsigned int val){
    return ((val & 0x000000FF) << 24) | ((val & 0xFF000000) >> 24) | ((val & 0x00FF0000) >> 8) | ((val & 0x0000FF00) << 8);
}