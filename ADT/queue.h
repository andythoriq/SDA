#ifndef QUEUE_H
#define QUEUE_H

#include "list1.h"

typedef List Queue;

void CreateEmptyQueue(Queue *Q);

boolean IsQueueEmpty(Queue Q);

boolean Enqueue(Queue *Q, infotype X);

boolean Dequeue(Queue *Q, infotype *X);

void DisplayQueue(Queue Q);

void ClearQueue(Queue *Q);

#endif