#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *next;
    int data;
};

struct Queue{
    struct Node *head;
    struct Node *tail;
};

void qpush(struct Queue *q, int data){
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (q->head == NULL){
        q->head = node;
        q->tail = node;
        return;
    }

    q->tail->next = node;
    q->tail = q->tail->next;
}

int qpop(struct Queue *q){
    int ans;
    if (q->head == NULL){
        return -1;
    }
    struct Node *tmp = q->head;
    q->head = q->head->next;
    ans = tmp->data;
    free(tmp);
    if (q->head == NULL){
        q->tail = NULL;
        return ans;
    }
    return ans;
}

void init_queue(struct Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int qsearch(struct Queue *q, int data){

}

int main(){
    struct Queue *queue = malloc(sizeof(struct Queue));
    init_queue(queue);

}