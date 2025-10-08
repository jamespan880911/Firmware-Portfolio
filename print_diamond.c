#include <stdio.h>

void print_diamond(int n){
    //上半
    for (int i = 0; i < n; i++){
        for (int j = 1; j < (n-i); j++){
            printf(" ");
        }
        for (int j = 0; j < 2 * (i+1) - 1; j++){
            printf("*");
        }
        printf("\n");
    }

    //下半
    for (int i = (n-2); i >= 0; i--){
        for(int j = 1; j < (n-i); j++){
            printf(" ");
        }
        for (int j = 0; j < 2 * (i+1) - 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("n = ");
    scanf("%d", &n);
    print_diamond(n);
    return 0;
}