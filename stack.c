#include "stack.h"
#include "list1.h"

// Inisialisasi stack kosong
void initStack(Stack *s)
{
    CreateList(&(s->L));
}

// menambahkan elemen ke stack
void push(Stack *s, int data)
{
    InsVFirst(&(s->L), data);
}

// menghapus elemen dari stack dan mengembalikan nilainya
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int data;
    DelVFirst(&(s->L), &data);
    return data;
}

// melihat elemen teratas stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return Info(First(s->L));
}

// memeriksa apakah stack kosong
int isEmpty(Stack *s)
{
    return ListEmpty(s->L);
}

// menampilkan isi stack
void display(Stack *s)
{
    PrintInfo(s->L);
}
