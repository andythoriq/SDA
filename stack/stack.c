#include "stack.h"

void initStack(Stack *s) {
    s->top = NULL;
}

bool isStackEmpty(Stack *s) {
    return s->top == NULL;
}

bool isStackFull(Stack *s) {
    SNode *temp = (SNode *)malloc(sizeof(SNode));
    if (temp == NULL) {
        return true;
    }
    free(temp);
    return false;
}

void freeStack(Stack *s) {
    while (!isStackEmpty(s)) {
        SNode *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

void push_int(Stack *s, int data) {
    SNode *node = malloc(sizeof(SNode));
    node->data = data;
    node->next = s->top;
    s->top = node;
}

int pop_int(Stack *s) {
    if (isStackEmpty(s))
        return -1;
    SNode *temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

// void push_char(Stack *s, char data) {
//     SNode *node = malloc(sizeof(SNode));
//     node->data = data;
//     node->next = s->top;
//     s->top = node;
// }

// char pop_char(Stack *s) {
//     if (isStackEmpty(s))
//         return '\0';
//     SNode *temp = s->top;
//     char val = temp->data;
//     s->top = temp->next;
//     free(temp);
//     return val;
// }

// void push_string(Stack* s, char* data) {
//     SNode* node = malloc(sizeof(SNode));
//     node->data = data;
//     node->next = s->top;
//     s->top = node;
// }

// char* pop_string(Stack* s) {
//     if (isStackEmpty(s)) return NULL;
//     SNode* temp = s->top;
//     char* val = temp->data;
//     s->top = temp->next;
//     free(temp);
//     return val;
// }