/*
思路：
不斷右移判斷即可。

關鍵點：
轉型成uint32_t可以避免掉int帶入負數所引發的問題。
*/

#include <stdio.h>
#include <stdint.h>

int hammingWeight(int n) {
    int counter = 0;
    uint32_t un = (uint32_t)n;     //強制轉型成無號數，避免負數右移時造成問題（當前題目規定n是正的所以不用保護）

    while (un){
        if ((un & 1) == 1){
            counter++;
        }
        un = un >> 1;
    }
    return counter;
}

int main(){
int test1 = 372;
int ans1 = hammingWeight(test1);
printf("ans1 = %d\n", ans1);

int test2 = 7;
int ans2 = hammingWeight(test2);
printf("ans2 = %d\n", ans2);

return 0;
}