#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void insertStack(int a, stack *s){
    node *n;
    n = malloc(sizeof(node));
    n->value = a;
    n->next = n;
    n->prev = n;
    if(s->size == 0){
        s->top = n;
        s->bottom = n;
    }
    else{
        s->top->next = n;
        n->prev = s->top;
        s->top = n;
        n->next = s->bottom;
        s->bottom->prev = n;
        s->size++;
    }
}

int pop(stack *head){
    int value = head->top->value;
    head->top->next->prev = head->top->prev;
    head->top->prev->next = head->top->next;
    head->top = head->top->prev;
    return value;
}


int main(int ac, char **av){
    printf("%d", ac);
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    int c = atoi(av[3]);
    stack *head = malloc(sizeof(stack));
    head->size = 0;
    head->top = 0;
    head->bottom = 0;
    insertStack(a, head);
    insertStack(b, head);
    insertStack(c, head);
    printf("%d", pop(head));
    printf("%d", pop(head));
    printf("%d", pop(head));
}