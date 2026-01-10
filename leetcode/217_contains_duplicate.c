/**
* -----------------------------------------------------------------
 * Name: 217. Contains Duplicate
-----------------------------------------------------------------
 * * 💡 解題思路 (Approach):
 * 1. 先排序，再檢查鄰居。
 * 2. 為什麼選這個方法？(例如：為了省空間，犧牲一點時間用 O(N log N))。
 * * ⏱️ 複雜度分析 (Complexity):
 * - Time:  O(N log N) qsort排序。
 * - Space: O(1)
 * * ⚠️ 關鍵點 (Key Points & Pitfalls):
 * - function pointer的用法（compare）
 * - void 指標在進function時才定義指標型態（Casting）
 * * -----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//定義比較函式（讓qsort裡的function pointer來call他），小的放前面
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int *nums, int numsSize) {
    if (numsSize <= 1){
        return false;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1; i++){
        if (nums[i] == nums[i + 1]){
            return true;
        }
    }

    return false;

}

int main() {
    int test1[] = {2, 1, 3, 2};
    int len1 = sizeof(test1) / sizeof(test1[0]);
    printf("Test 1 = %d\n", containsDuplicate(test1, len1));

    int test2[] = {2, 1, 3, 4};
    int len2 = sizeof(test2) / sizeof(test2[0]);
    printf("Test 2 = %d\n", containsDuplicate(test2, len2));

    return 0;
}