#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node{
    struct Node *next;
    uint32_t data;
}Node;

typedef struct Queue{
    struct Node *head;
    struct Node *tail;
    void (*qpush)(uint32_t);
    void (*qpop)();
}Queue;

Queue *queue = NULL;

void qpush(uint32_t val){
    Node *temp = NULL;
    temp = malloc(sizeof(Node));
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
    Node *temp = NULL;
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

//雙指標是為了不要再複製的指標底下做事（把該指標自己的address丟進去）
void init_queue(struct Queue **Q){
    *Q = malloc(sizeof(struct Queue));
    (*Q)->head = NULL; //注意(*Q)，->優先級比*高
    (*Q)->tail = NULL;
    (*Q)->qpush = qpush;
    (*Q)->qpop = qpop;
}

void print_queue(struct Queue *q){
    Node *temp = q->head;
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