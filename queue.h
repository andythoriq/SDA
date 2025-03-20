#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "list1.h"

#define MAX_QUEUE 100
#define IDX_UNDEF -1
#define QUEUE_CAPACITY 100

typedef struct {
    List L;
} Queue;

/* Operasi Queue */

/* membuat queue kosong */
void CreateQueue(Queue *q);

/* return true jika queue kosong */
boolean isEmpty(Queue q);

/* return jumlah elemen dalam queue */
int length(Queue q);

/* menambah val ke dalam queue */
void enqueue(Queue *q, int val);

/* menghapus elemen dari queue */
int dequeue(Queue *q);

/* mengirim elemen pertama dari queue */
int front(Queue q);

/* menampilkan isi queue */
void displayQueue(Queue q);

#endif