#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    struct ListNode *cur = head;
    while (cur){
        printf("%d ->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode **head){
    struct ListNode *cur = *head;
    struct ListNode *pre = NULL;

    while (cur){
        pre = cur;
        cur = cur->next;
        free(pre);
    }

    *head = NULL;  //結束後要記得把頭設成null，不然會dangling pointer
}

struct ListNode* deleteDuplicates_2(struct ListNode *head){
    struct ListNode *cur = head;
    struct ListNode *pre = NULL;
    if (head == NULL) return NULL;

    while (cur && cur->next){
        pre = cur;
        cur = cur->next;
        if (cur->data == pre->data){
            pre->next = cur->next;
            free(cur);
            cur = pre;
        }
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode *head){
    struct ListNode *cur = head;
    while (cur && cur->next){
        if (cur->data == cur->next->data){
            struct ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
            continue;
        }
        cur = cur->next;
    }
    return head;
}

struct ListNode* merge_two_list(struct ListNode *list1, struct ListNode *list2){
    struct ListNode *dum = NULL;
    dum = malloc(sizeof(struct ListNode));
    if (!dum) return NULL; //記得malloc完都要檢查有沒有heap成功
    dum->next = NULL;
    dum->data = 0;
    struct ListNode *head = dum;

    while(list1 && list2){
        if(list1->data < list2->data){
            head->next = list1;
            list1 = list1->next;
            head = head->next;
        }
        else{
            head->next = list2;
            list2 = list2->next;
            head = head->next;
        }
    }

    if (list1){
        head->next = list1;
    }

    if (list2){
        head->next = list2;
    }
    struct ListNode *result = dum->next;
    free(dum);
    return result;
}


void reverseList(struct ListNode **head){
    struct ListNode *cur = *head;
    struct ListNode *pre = NULL;
    while (cur){
        struct ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    *head = pre;
}

void swap_1(int *a, int *b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_2(int *a, int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

void swap_char(char *a, char *b){
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

char *reverse_string(char *c){
    int j = strlen(c) - 1;
    int i = 0;
    while (i < j){
        swap_char(&c[i],&c[j]);
        i++;
        j--;
    }
    return c;
}

void find_prime(int n){

}

//不用+-做加法器
int add (int a, int b){
    while (b != 0){
        int c = a & b;
        a = a ^ b;
        b = c << 1;
    }
    return a;
}

// 取第N個bit的值
int function_bit(unsigned char *a, int N){
    int numByte = N / 8;
    int numBit = N % 8;
    int result = (a[numByte] >> numBit) & 1;
    return result;
}

//用位置找出陣列中最大最小值，並交換
void swap(int *val1,int *val2){
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void Find_Value(int *arr, int len){
    int *data1 = arr;
    int *data2 = arr;

    for (int i = 1; i < len; i++){
        if (*(arr + i) > *data1){
            data1 = arr + i;
        }
        if (*(arr + i) < *data2){
            data2 = arr + i;
        }
    }

    swap(data1, data2);
}

//用struct回傳min max

struct result{
    int max;
    int min;
};

struct result find_min_max(int a, int b, int c){
    struct result ans;

    if (a > b){
        if (a > c){
            ans.max = a;
        }
        else {
            ans.max = c;
        }
    }

    else if (b > a){
        if (b > c){
            ans.max = b;
        }
        else{
            ans.max = c;
        }
    }

    if (a < b){
        if (a < c){
            ans.min = a;
        }
        else{
            ans.min = c;
        }
    }

    else if (b < a){
        if (b < c){
            ans.min = b;
        }
        else{
            ans.min = c;
        }
    }

    return ans;
}

//實作queue


struct Queue{
    struct ListNode *head;
    struct ListNode *tail;
};

struct Queue *init_queue(){
    struct Queue *q = malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void qpush(struct Queue *queue, int data){
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->data = data;
    node->next = NULL;

    if (queue->head == NULL){
        queue->head = node;
        queue->tail = node;
        return;
    }
    else{
        queue->tail->next = node;
        queue->tail = queue->tail->next;
    }
    return;
}

void qpop(struct Queue *queue){
    if (queue->head == NULL){
        return;
    }
    else{
        struct ListNode *tmp = queue->head;
        queue->head = queue->head->next;
        free(tmp);
        if(queue->head == NULL){
            queue->tail = NULL;
        }
    }
    return;
}

void print_queue(struct Queue *queue){
    if (queue->head == NULL){
        return;
    }
    else{
        struct ListNode *cur = queue->head;
        while (cur){
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
    }
    printf("NULL");
    printf("\n");
    return;
}

//sorting
//泡泡大的一直換上去
void bubble_sort(int *a, int len){
    for (int i = 0; i < len; i++){
        for (int j = 1; j < len; j++){
            if (a[j-1] > a[j]){
                int tmp;
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
}

//每一輪選(selection)最小的往前放
void selection_sort(int *a, int len){
    for (int i = 0; i < len; i++){
        int min = a[i];
        int tmp = i;
        for (int j = i; j < len; j++){
            if (a[j] < min){
                min = a[j];
                tmp = j;
            }
        }
        a[tmp] = a[i];
        a[i] = min;
    }
}

//（從第一張開始的撲克牌手排整理）從頭開始，一張一張牌選要插到前面整理好的手牌裡的哪個位置（這題要多注意）
void insertion_sort(int *a, int len){
    for (int i = 1; i < len; i++){
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

//每次都忘記的quick sort（比pivot小或一樣大的放左邊，比pivot大的放右邊。然後divide and conquer）
void quick_sort(int *a,int left, int right){
    int i = left, j = right, p = a[left];

    if (left >= right){     //記得加遞迴終止條件（<=的原因是因為剩一個元素就該跳出去了）
        return;
    }

    while (i != j){
        while (a[j] > p && i < j){
            j--;
        }
        while (a[i] <= p && i < j){
            i++;
        }

        if (i < j){
            int tmp;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    a[left] = a[i];
    a[i] = p;

    quick_sort(a, left, i - 1);
    quick_sort(a, i + 1, right);
}

//刪除指定pos的Linklist
struct ListNode *delete_node_index(struct ListNode **head, int index){
    struct ListNode *cur = *head;
    struct ListNode *pre = NULL;

    if (index < 0){
        return NULL;
    }
    else if (index == 0){
        pre = cur;
        *head = cur->next;
        free(pre);
        return *head;
    }
    
    for (int i = 0; i < index; i++){
        pre = cur;
        cur = cur->next;
        //做indext超過的檢查
        if (cur == NULL){
            return NULL;
        }
    }
    pre->next = cur->next;
    free(cur);
    return *head;
}




int main(){
    //int *p = (int *)0x8265;
    //*p = 0x2235;

    struct result find = find_min_max(1, 2, 3);
    printf("max is : %d\n", find.max);
    printf("min is : %d\n", find.min);

    struct Queue *q = NULL;
    q = init_queue();
    qpush(q, 10);
    qpush(q, 8);
    print_queue(q);
    qpop(q);
    print_queue(q);
    return 0;
}