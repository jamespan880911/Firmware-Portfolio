#include<stdio.h>

void swap1(int *a, int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 10, b = 5;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}