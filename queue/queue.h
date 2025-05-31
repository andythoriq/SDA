#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef int infotype;
// typedef char infotype;

typedef struct QNode {
    infotype data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} Queue;

void initQueue(Queue *q);
bool isQueueEmpty(Queue *q);
bool isQueueFull(Queue *q);
void enqueue_int(Queue *q, int data);
int dequeue_int(Queue *q);
void freeQueue(Queue *q);
// void enqueue_char(Queue *q, char data);
// char dequeue_char(Queue *q);
// void enqueue_string(Queue* q, char* data);
// char* dequeue_string(Queue* q);

#endif