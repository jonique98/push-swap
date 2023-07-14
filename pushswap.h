#ifndef PUSHSWAP_H
#define PUSHSWAP_H

typedef struct _stack{

    int value;
    struct _stack *next;
    struct _stack *prev;

}node;


typedef struct _headTail{
    int size;
    node *top;
    node *bottom;
}stack;

#endif