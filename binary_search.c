#include<stdio.h>

void binary_search(int *arr, int len, int target){
    int left = 0, right = len - 1, mid;

    while (left <= right){                      //這裡用 <= 再配合左右縮的方式才不會漏掉元素（用!=會漏掉）
        mid = (left + right) / 2;
        if (target > arr[mid]){
            left = mid + 1;
        }
        else if (target < arr[mid]){
            right = mid - 1;
        }
        else {
            printf("found the number in [%d]\n", mid);
            return;
        }
    }
    printf("not found\n");
    return;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
    binary_search(a, 10 ,7);
    return 0; 
}