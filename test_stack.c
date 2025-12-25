#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
  struct Node *top;
};


void spop(struct Stack *s){
    if (s->top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
}

void spush(struct Stack *s, int data){
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = s->top;
    s->top = node;
}

void s_top(struct Stack *s){
    if (s->top == NULL){
        printf("Stack top is empty\n");
        return;
    }
    printf("top is %d\n", s->top->data);
}

void print_s(struct Stack *s){
    struct Node *cur = s->top;
    if (cur == NULL){
        printf("Stack is empty\n");
    }
    while (cur){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(){
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    spush(stack, 1);
    spush(stack, 2);
    spush(stack, 3);
    print_s(stack);
    spop(stack);
    print_s(stack);
    s_top(stack);
}

