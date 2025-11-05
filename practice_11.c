#include<stdio.h>
#include<stdlib.h>

#define SET_BIT(x,n) ((x) |= (1 << (n)))
#define CLEAR_BIT(x,n) ((x) &= ~(1 << (n))) //記得是～（因為其他bit不能動）
#define CHANGE_BIT(x,n) ((x) ^= (1 << (n))) //XOR一樣是0，不同是1
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define MAX(a,b) (((a) > (b)) ? (a) : (b)) //記得a > b 要刮起來

//建議可以直接背起來（當場應該想不到）往-1去想
int judge_2(unsigned int x){
    return (x > 0) && (x & (x - 1)) == 0;
}

//Brian Kernighan’s Algorithm，每次透過x &= (x - 1);清掉最低位元的1 (也是建議背起來)
int num_1(unsigned int x){
    int sum = 0;
    while (x){
        x &= (x - 1);
        sum++;
    }
    return sum;
}

int LSB(unsigned int x){
    if (x == 0) return -1;
    int n = 1;
    int bit = 0;
    while ((x & n) == 0){
        n = n << 1;
        bit++;
    }
    return bit;
}

int MSB(unsigned int x){
    if (x == 0) return -1;
    int bit = 31;
    unsigned int n = 0x80000000;
    while ((x & n) == 0){
        n >>= 1;
        bit--;
    }
    return bit;
}

//只能檢查16bit
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

//定義struct結尾記得要加;（#define 定義Macor不用加;）
struct ListNode{
    struct ListNode *next;
    int data;
};

//頭節點
void push_node(struct ListNode **head, int data){
    struct ListNode *node = NULL;
    node = malloc(sizeof(struct ListNode));
    if (!node) return; // 記得檢查有沒有heap成功
    node->data = data;
    node->next = NULL;

    /* 這裡不用判斷，就算空的也是直接接上NULL
    if (*head == NULL){
        *head = node;
        return;
    }
    */

    node->next = *head;
    *head = node;
    return;
}

//尾節點
void append_node(struct ListNode **head, int data){
    struct ListNode *cur = *head;
    struct ListNode *node = NULL;
    node = malloc(sizeof(struct ListNode));
    if (!node) return;
    node->data = data;
    node->next = NULL;

    if (*head == NULL){
        *head = node;
        return;
    }

    while (cur && cur->next){ //可以用（cur->next）就好，因為前面已經檢查過了
        cur = cur->next;
    }
    cur->next = node;
    return;
}

void print_list(struct ListNode *head){

}

void 


int main(){
    int *p = (int *)0x8265;
    *p = 0x2235;
    return 0;
}