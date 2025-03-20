#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    CreateList(&(q->L));
}

boolean isEmpty(Queue q)
{
    return ListEmpty(q.L);
}

int length(Queue q)
{
    return NbElmt(q.L);
}

// untuk menambahkan elemen ke dalam queue
void enqueue(Queue *q, int val)
{
    InsVLast(&(q->L), val);
}

// untuk menghapus elemen dari queue
int dequeue(Queue *q)
{
    infotype val;
    DelVFirst(&(q->L), &val);
    return val;
}

// untuk mengambil elemen pertama dari queue
int front(Queue q)
{
    return Info(First(q.L));
}

void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Isi Queue: ");
        PrintInfo(q.L);
    }
}