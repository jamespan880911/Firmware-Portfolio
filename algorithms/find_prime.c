#include<stdio.h>

void find_prime(int n){
    for (int i = 2; i < (n + 1); i++){
        int flag = 1;
        for (int j = 2; j < i; j++){
            if (i % j == 0){
                flag = 0;
                break;
            }
        }
        if (flag){
            printf("%d is prime\n", i);
        }
    }
}

int main(){
    int n;
    printf("n is :\n");
    scanf("%d", &n);
    find_prime(n);
    return 0;
}