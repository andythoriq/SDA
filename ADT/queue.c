#include "queue.h"

void CreateEmptyQueue(Queue *Q)
{
    CreateList(Q);
}

boolean IsQueueEmpty(Queue Q)
{
    return ListEmpty(Q);
}

boolean Enqueue(Queue *Q, infotype X)
{
    if (Q == NULL)
    {
        fprintf(stderr, "Error: Queue tidak valid.\n");
        return false;
    }

    InsVLast(Q, X);
    return true;
}

boolean Dequeue(Queue *Q, infotype *X)
{
    if (Q == NULL || X == NULL)
    {
        fprintf(stderr, "Error: Queue atau pointer output NULL.\n");
        return false;
    }

    if (IsQueueEmpty(*Q))
    {
        fprintf(stderr, "Error: Queue kosong, tidak bisa dequeue.\n");
        return false;
    }

    DelVFirst(Q, X);
    return true;
}

void DisplayQueue(Queue Q)
{
    if (IsQueueEmpty(Q))
    {
        printf("Antrean Kosong!\n");
    } else {
        PrintInfo(Q);
    }
}

void ClearQueue(Queue *Q)
{
    infotype temp;
    while (!IsQueueEmpty(*Q)) {
        Dequeue(Q, &temp);
    }
}