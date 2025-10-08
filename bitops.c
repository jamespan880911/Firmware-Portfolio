#include <stdio.h>


#define set_bit(x, n) ((x) |= (1 << (n)))
#define clear_bit(x, n) ((x) &= ~(1 << (n)))
#define toggle_bit(x, n) ((x) ^= (1 << (n)))
#define array_size(arr) (sizeof(arr) / sizeof(arr[0]))
#define Max(a, b) ((a) > (b)) ? (a) : (b)

//判斷是否為2的冪次方
int judge_pow2(unsigned int x){
    return (x & (-x)) == x;
}

//判斷1的數量
int num_of_1(unsigned int x){
    int c = 0;
    /*while (x != 0){
        x -= x & -x;
        c++;
    }*/
    while (x != 0){
        x = x & (x - 1); //這個寫法比較多人在用（比較直觀）
        c++;
    }
    return c;
}

//找最高位元
void MSB(unsigned int x){
    unsigned int n = 0x80000000;
    int count = 31;
    while ((x & n) >> count != 1){
        count--;
        n >>= 1;
    }
    printf("The MSB is : %d \n", count);
}

//找最低位元
void LSB(unsigned int x){
    unsigned int n = 0x1;
    int count = 0;
    if (x < 0){
        return;
    }
    while ((x & n) >> count != 1){
        count++;
        n <<= 1;
    }
    printf("The LSB is : %d\n", count);
}

//判斷16進位數是否一致
int hex_equal(unsigned int x){
    unsigned int hex[4] = {0};
    hex[0] = (x & 0xF000) >> 12;
    hex[1] = (x & 0x0F00) >> 8;
    hex[2] = (x & 0x00F0) >> 4;
    hex[3] = (x & 0x000F);
    if (hex[0] == hex[1] && hex[1] == hex[2] && hex[2] == hex[3]){
        return 1;
    }
    return 0;
}

int main(){
    int *p = (int*) 0x8264;
    *p = 0x2645; //寫入將數值寫入指定暫存器
    return 0;
}

