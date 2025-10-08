#include<stdio.h>

//大氣泡往最後面浮（兩兩比較，大的往後）
void bubble_sort(int *arr, int len){
    int temp = 0;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//每論找最小值往前放
void selection_sort(int *arr, int len){
    int min = 0;
    int temp = 0;
    for (int i = 0; i < len - 1; i++){
        min = i;
        for (int j = i + 1; j < len; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

//插撲克牌（注意元素全部往後放的邏輯，從後面放到前面）
void insertion_sort(int *arr, int len){
    for (int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//不斷換pivot遞迴處理（注意和p比大小的<=判斷)
void quick_sort(int *arr, int left, int right){
    int i = left, j = right, p = arr[left];
    if (left >= right){
        return; //判斷遞迴終點
    }
    while (i != j){
        while (arr[j] > p && i < j){
            j--;
        }
        while (arr[i] <= p && i < j){
            i++;
        }
        if (i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[i];
    arr[i] = p;

    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main(){
    int test_arr[10] = {2, 4, 1, 7, 3, 6, 8, 5, 9, 3};
    quick_sort(test_arr, 0, 9);
    for (int i = 0; i < (sizeof(test_arr) / sizeof(int)); i++){
        printf("%d ", test_arr[i]);
    }
    return 0;
}

