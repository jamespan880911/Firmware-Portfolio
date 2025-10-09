#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ListNode{
    struct ListNode *next;
    uint32_t data;
}ListNode;

typedef struct Queue{
    struct ListNode *head;
    struct ListNode *tail;
    void (*qpush)(uint32_t);
    void (*qpop)();
}Queue;

Queue *queue = NULL;

void qpush(uint32_t val){
    ListNode *temp = NULL;
    temp = malloc(sizeof(ListNode));
    if (queue->head == NULL){
        queue->head = temp;
        queue->tail = temp;
        temp->data = val;
        temp->next = NULL;
        return;
    }
    else{
        queue->tail->next = temp;
        temp->data = val;
        temp->next = NULL;
        queue->tail = queue->tail->next;
    }
    return;
}

void qpop(){
    ListNode *temp = NULL;
    if (queue->head == NULL){
        queue->tail = NULL;
        return;
    }
    else{
        temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    return;
}

void init_queue(struct Queue **Q){
    *Q = malloc(sizeof(struct Queue));
    (*Q)->head = NULL; //注意(*Q)，->優先級比*高
    (*Q)->tail = NULL;
    (*Q)->qpush = qpush;
    (*Q)->qpop = qpop;
}

void print_queue(struct Queue *q){
    ListNode *temp = q->head;
    while(temp != NULL){
        printf("%u -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    init_queue(&queue);
    queue->qpush(10);
    queue->qpush(20);
    queue->qpush(30);
    print_queue(queue);
    queue->qpop();
    print_queue(queue);
    return 0;
}