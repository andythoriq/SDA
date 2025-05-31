#include "queue.h"

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

bool isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

bool isQueueFull(Queue *q) {
    QNode *temp = (QNode *)malloc(sizeof(QNode));
    if (temp == NULL) {
        return true;
    }
    free(temp);
    return false;
}

void freeQueue(Queue *q) {
    while (!isQueueEmpty(q)) {
        QNode *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
}

void enqueue_int(Queue *q, int data) {
    QNode *newNode = malloc(sizeof(QNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue_int(Queue *q) {
    if (isQueueEmpty(q))
        return -1;
    QNode *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

// void enqueue_char(Queue *q, char data) {
//     QNode *newNode = malloc(sizeof(QNode));
//     newNode->data = data;
//     newNode->next = NULL;
//     if (q->rear == NULL) {
//         q->front = q->rear = newNode;
//     } else {
//         q->rear->next = newNode;
//         q->rear = newNode;
//     }
// }

// char dequeue_char(Queue *q) {
//     if (isQueueEmpty(q))
//         return '\0';
//     QNode *temp = q->front;
//     char val = temp->data;
//     q->front = q->front->next;
//     if (q->front == NULL)
//         q->rear = NULL;
//     free(temp);
//     return val;
// }

// void enqueue_string(Queue *q, char *data) {
//     QNode *newNode = malloc(sizeof(QNode));
//     newNode->data = data;
//     newNode->next = NULL;
//     if (q->rear == NULL) {
//         q->front = q->rear = newNode;
//     } else {
//         q->rear->next = newNode;
//         q->rear = newNode;
//     }
// }

// char *dequeue_string(Queue *q) {
//     if (isQueueEmpty(q))
//         return NULL;
//     QNode *temp = q->front;
//     char *val = temp->data;
//     q->front = q->front->next;
//     if (q->front == NULL)
//         q->rear = NULL;
//     free(temp);
//     return val;
// }