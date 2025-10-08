#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

//加入尾部節點
void append_node(struct ListNode **head, int data){
    struct ListNode *new_node = NULL;
    struct ListNode *cur = *head;
    new_node = malloc(sizeof(struct ListNode));
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
void push_node(struct ListNode **head, int data){
    struct ListNode *new_node = NULL;
    new_node = malloc(sizeof(struct ListNode));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}

//印出整條list
void print_list(struct ListNode *head){
    struct ListNode *ptr = head;
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

//刪除指定數值的節點
void delete_node_value(struct ListNode **head, int val){
    struct ListNode *prev = NULL;
    struct ListNode *cur = *head;

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
void insert_node_pos(struct ListNode **head, int pos, int val){
    struct ListNode *new_node = NULL;
    new_node = malloc(sizeof(struct ListNode));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->data = val;

    struct ListNode *cur = *head;
    
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
void free_list(struct ListNode *head){
    struct ListNode *cur = head;
    while (head){
        cur = head;
        head = head->next;
        free(cur);
    }
}

//合併兩條Linklist
struct ListNode* merge_TwoList(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *dummy = NULL;
    dummy = malloc(sizeof(struct ListNode));
    struct ListNode* cur = dummy;

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
    struct ListNode *ans = dummy->next;
    free(dummy);
    return ans;
}

int main(){
    struct ListNode *list1 = NULL;
    struct ListNode *list2 = NULL;

    append_node(&list1, 1);
    append_node(&list1, 3);
    append_node(&list1, 5);

    append_node(&list2, 2);
    append_node(&list2, 4);
    append_node(&list2, 6);

    struct ListNode *merge = merge_TwoList(list1, list2);
    print_list(merge);
    free_list(merge);
    return 0;
}

