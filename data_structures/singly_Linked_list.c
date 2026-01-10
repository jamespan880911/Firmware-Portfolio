#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *next;
};

typedef struct{
    struct Node *dummyHead;
    int size;
} MyLinkedList;

static struct Node* createNode(int val){
    struct Node *node = malloc(sizeof(struct Node));
    if (node){
        node->val = val;
        node->next = NULL;
    }
    return node;
}

MyLinkedList* myLinkedListCreate(){
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    if (!obj){
        return NULL;
    }

    obj->dummyHead = createNode(0);
    if (!obj->dummyHead){
        free(obj);
        return NULL;
    }

    obj->size = 0;
    
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size){
        return -1;
    }

    struct Node *cur = obj->dummyHead->next;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }

    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size){
        return;
    }
    
    struct Node *node = createNode(val);
    if (!node){
        return;
    }

    struct Node *pre = obj->dummyHead;
    for (int i = 0; i < index; i++){
        pre = pre->next;
    }
    node->next = pre->next;
    pre->next = node;

    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size){
        return;
    }

    struct Node *pre = obj->dummyHead;
    for (int i = 0; i < index; i++){
        pre = pre->next;
    }
    struct Node *del = pre->next;
    pre->next = pre->next->next;
    free(del);

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct Node *cur = obj->dummyHead;

    while(cur){
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free(obj);
}
