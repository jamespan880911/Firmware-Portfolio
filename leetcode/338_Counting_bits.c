/*
思路：
整體要用DP的思路去解，以下
ans[i] = ans[i >> 1] + (i & 1);
該數值有多少1都可以用右移一位的1數量加上自己第一位的1數量，這是這題ＤＰ的精髓，

關鍵點：
returnSize之所以要用指標的方式傳入是因為要把大小偷渡出來（要回陣列的指標又要回傳陣列大小，但Ｃ的回傳值只能有一個）
動態陣列需要知道大小這個資訊才可以準確操作(不overflow)，相比靜態陣列來說危險。（靜態陣列 VS 動態陣列）Stack vs Heap .... 
*/

#include <stdio.h>
#include <stdlib.h>


int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;

    int *ans = malloc(*returnSize * sizeof(int));
    ans[0] = 0;

    for (int i = 1; i <= n; i++){
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

int main(){
    int test1 = 5;
    int size1 = 0;

    int test2 = 7;
    int size2 = 0;

    int *ans1 = countBits(test1, &size1);
    for (int i = 0; i < (size1); i++){
        printf("%d, ", ans1[i]);
    }
    printf("\n");

    int *ans2 = countBits(test2, &size2);
    for (int i = 0; i < (size2); i++){
        printf("%d, ", ans2[i]);
    }
    printf("\n");

    return 0;
}