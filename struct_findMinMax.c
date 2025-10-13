#include<stdio.h>

struct return_val{
    int min;
    int max;
};

struct return_val find_MinMax(int a, int b, int c){
    struct return_val ret;
    if (a > b){
        if (a > c){
            ret.max = a;
        }
        else{
            ret.max = c;
        }
    }
    else if (a < b){
        if (b > c){
            ret.max = b;
        }
        else{
            ret.max = c;
        }
    }

    if (a < b){
        if (a < c){
            ret.min = a;
        }
        else{
            ret.min = c;
        }
    }
    else if (a > b){
        if (b < c){
            ret.min = b;
        }
        else{
            ret.min = c;
        }
    }

    return ret;
}

int main(){
    int a, b, c;
    printf("請輸入3個數字 : \n");
    scanf("%d %d %d", &a, &b, &c);
    struct return_val ret = find_MinMax(a, b, c);
    printf("Max : %d\n", ret.max);
    printf("Min : %d\n", ret.min);
    return 0;
}