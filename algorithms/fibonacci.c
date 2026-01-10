#include<stdio.h>

int fib_recursive(int n){
    if (n == 1){
        return 1;
    }
    else if (n == 0){
        return 0;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
}

int fib_DP(int n){
    int dp[500] = {0};
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){
    int n = 7;
    printf("recursive fib is : %d\n", fib_recursive(n));
    printf("DP fib is : %d\n", fib_DP(n));
    return 0;
}