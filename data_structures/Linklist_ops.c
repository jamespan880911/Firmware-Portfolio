#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

//加入尾部節點
void append_node(struct Node **head, int data){
    struct Node *new_node = NULL;
    struct Node *cur = *head;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL) //如果沒有heap成功的檢查
        return;
    new_node->next = NULL;
    new_node->data = data;

    if (*head == NULL){
        *head = new_node;
    }
    else{
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

//加入頭節點
void push_node(struct Node **head, int data){
    struct Node *new_node = NULL;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}

//印出整條list
void print_list(struct Node *head){
    struct Node *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//刪除指定數值的節點
void delete_node_value(struct Node **head, int val){
    struct Node *prev = NULL;
    struct Node *cur = *head;

    while (cur && cur->data != val){
        prev = cur;
        cur = cur->next;
    }
    if (cur){
        if (cur == *head){
            *head = cur->next;
            free(cur);
        }
        else {
            prev->next = cur->next;
            free(cur);
        }
    }
    else{
        printf("val is not in the list");
    }
}

//在指定位置插入節點
void insert_node_pos(struct Node **head, int pos, int val){
    struct Node *new_node = NULL;
    new_node = malloc(sizeof(struct Node));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = val;

    struct Node *cur = *head;
    
    for (int i = 1;cur && i < pos; i++){
        cur = cur->next;
    }
    if (pos == 0){
        new_node->next = *head;
        *head = new_node;
    }
    else{
        if (cur){
            new_node->next = cur->next;
            cur->next = new_node;
        }
        else{
            free(new_node);
        }
    }
}

//釋放整條list的記憶體空間(防止memory leak)
void free_list(struct Node *head){
    struct Node *cur = head;
    while (head){
        cur = head;
        head = head->next;
        free(cur);
    }
}

//刪除重複節點
struct Node* deleteDuplicates(struct Node *head){
    struct Node *cur = head;
    if (cur == NULL){
        return NULL;
    }
    while (cur != NULL && cur->next != NULL){
        if (cur->data == cur->next->data){
            struct Node *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
            continue;
        }
        cur = cur->next;
    }
    return head;
}

//翻轉鏈錶
void reverseList(struct Node **head){
    struct Node *cur = *head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    *head = prev;
    return;
}

//合併兩條Linklist
struct Node* merge_TwoList(struct Node* list1, struct Node* list2){
    struct Node *dummy = NULL;
    dummy = malloc(sizeof(struct Node));
    struct Node* cur = dummy;

    while (list1 && list2){
        if (list1->data < list2->data){
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
    }
    if (list1){
        cur->next = list1;
    }
    else if (list2){
        cur->next = list2;
    }
    struct Node *ans = dummy->next;
    free(dummy);
    return ans;
}

//面試寫的版本（比較亂但還是可以work，還是用原版可讀性比較高）
struct Node* deleteDuplicates_2(struct Node *head){
    struct Node *cur = head;
    struct Node *pre = NULL;
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

//反轉鏈錶練習
void REVERT(struct Node **head){
    if (*head == NULL || (*head)->next == NULL){
        return;
    }

    struct Node *pre = NULL;
    struct Node *cur = *head;

    while(cur){
        struct Node *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    
    *head = pre;
}

int main(){
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    append_node(&list1, 1);
    append_node(&list1, 1);
    append_node(&list1, 1);
    append_node(&list1, 5);
    print_list(list1);
    //reverseList(&list1);
    //print_list(list1);
    deleteDuplicates(list1);
    print_list(list1);


    append_node(&list2, 2);
    append_node(&list2, 4);
    append_node(&list2, 6);

    struct Node *merge = merge_TwoList(list1, list2);
    print_list(merge);
    free_list(merge);
    return 0;
}

