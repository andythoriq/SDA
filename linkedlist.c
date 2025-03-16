#include "linkedlist.h"

void display(node *p)
{
    while (p != NULL)
    {
        printf("Nama: %s | Nilai: %d\n", p->nama, p->nilai);
        p = p->next;
    }
}

void insertSortedByNama(node **first, char nama[], int nilai)
{
    node *t = (node *)malloc(sizeof(node));
    node *p = *first, *q = NULL;

    if (t == NULL)
    {
        return;
    }

    strcpy(t->nama, nama);
    t->nilai = nilai;
    t->next = NULL;

    if (*first == NULL || strcmp((*first)->nama, nama) > 0)
    {
        t->next = *first;
        *first = t;
        return;
    }

    while (p != NULL && strcmp(p->nama, nama) < 0)
    {
        q = p;
        p = p->next;
    }
    t->next = q->next;
    q->next = t;
}

int count(node *p)
{
    int jumlah = 0;
    while (p != NULL)
    {
        jumlah++;
        p = p->next;
    }
    return jumlah;
}

void removeDuplicateNama(node *first)
{
    node *p = first;

    while (p != NULL && p->next != NULL)
    {
        node *q = p;
        while (q->next != NULL)
        {
            if (strcmp(p->nama, q->next->nama) == 0)
            {
                node *temp = q->next;
                q->next = q->next->next;
                free(temp);
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
    }
}

void clear(node **first, node **last)
{
    node *temp;
    while (*first != NULL)
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
    *last = NULL;
    printf("Linked list telah dikosongkan.\n");
}

// dari chatGPT
int compareNilai(const void *a, const void *b)
{
    node *nodeA = *(node **)a;
    node *nodeB = *(node **)b;
    return nodeB->nilai - nodeA->nilai; // Descending order
}

// dari chatGPT
void displayDescendingByNilai(node *first)
{
    int count = 0, i;
    node *p = first;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    if (count == 0)
        return;

    node *arr[count];
    p = first;
    for (i = 0; i < count; i++)
    {
        arr[i] = p;
        p = p->next;
    }

    qsort(arr, count, sizeof(node *), compareNilai);

    for (i = 0; i < count; i++)
    {
        printf("Nama: %s | Nilai: %d\n", arr[i]->nama, arr[i]->nilai);
    }
}

void copyFilterByNilai(node *L1, node **L2)
{
    node *p = L1;
    while (p != NULL)
    {
        if (p->nilai > KKM)
        {
            insertSortedByNama(L2, p->nama, p->nilai);
        }
        p = p->next;
    }
}