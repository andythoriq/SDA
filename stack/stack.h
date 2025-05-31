#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef int infotype;
// typedef char infotype;

typedef struct SNode {
    infotype data;
    struct SNode *next;
} SNode;

typedef struct {
    SNode *top;
} Stack;

void initStack(Stack *s);
bool isStackEmpty(Stack *s);
bool isStackFull(Stack *s);
void freeStack(Stack *s);
void push_int(Stack *s, int data);
int pop_int(Stack *s);
// void push_char(Stack *s, char data);
// char pop_char(Stack *s);
// void push_string(Stack* s, char* data);
// char* pop_string(Stack* s);

#endif