#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node *pre;
    struct Node *next;
};

typedef struct{
    struct Node *dummyHead;
    struct Node *dummyTail;
    int size;
}MyLinkedList;

//輔助函式（ststic限定此檔案內可見）
static struct Node* createNode(int val){
    struct Node *node = malloc(sizeof(struct Node));
    if (node){
        node->val = val;
        node->next = NULL;
        node->pre = NULL;
    }
    return node;
}

MyLinkedList* myLinkedListCreate(){
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    if (!obj){
        return NULL;
    }

    obj->dummyHead = createNode(0);
    obj->dummyTail = createNode(0);

    if (!obj->dummyHead || !obj->dummyTail){
        if(obj->dummyHead){
            free(obj->dummyHead);
        }
        if(obj->dummyTail){
            free(obj->dummyTail);
        }
        free(obj);
        return NULL;
    }

    obj->dummyHead->next = obj->dummyTail;
    obj->dummyTail->pre = obj->dummyHead;

    obj->size = 0;

    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index){
    if (index < 0 || index >= obj->size){
        return -1;
    }

    struct Node *cur;

    if (index < (obj->size / 2)){
        cur = obj->dummyHead->next;
        for (int i = 0; i < index; i++){
            cur = cur->next;
        }
    }
    else{
        cur = obj->dummyTail->pre;
        for (int i = 0; i < (obj->size - 1 - index); i++){
            cur = cur->pre;
        }
    }

    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val){
    if (index > obj->size){
        return;
    }

    struct Node *preNode;

    if (index < (obj->size / 2)){
        preNode = obj->dummyHead;
        for (int i = 0; i < index; i++){
            preNode = preNode->next;
        }
    }
    else{
        struct Node *postNode = obj->dummyTail;
        for (int i = 0; i < (obj->size - index); i++){
            postNode = postNode->pre;
        }
        preNode = postNode->pre;
    }

    struct Node *nextNode  = preNode->next;
    struct Node *node = createNode(val);
    if (!node){
        return;
    }

    node->pre = preNode;
    node->next = nextNode;
    preNode->next = node;
    nextNode->pre = node;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index){
    if (index < 0 || index >= obj->size){
        return;
    }
    struct Node *del;

    if (index < (obj->size / 2)){
        del = obj->dummyHead->next;
        for (int i = 0; i < index; i++){
            del = del->next;
        }
    }
    else{
        del = obj->dummyTail->pre;
        for (int i = 0; i < (obj->size - 1 - index); i++){
            del = del->pre;
        }
    }

    struct Node *preNode = del->pre;
    struct Node *nextNode = del->next;

    preNode->next = nextNode;
    nextNode->pre = preNode;

    free(del);
    obj->size--;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val){
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val){
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListFree(MyLinkedList* obj){
    struct Node *cur = obj->dummyHead;

    while (cur){
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    free(obj);
}