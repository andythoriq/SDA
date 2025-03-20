#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

// Struktur Stack (Memanfaatkan List yang sudah ada)
typedef struct
{
    List L; // dari ADT Linked List
} Stack;

// Inisialisasi Stack
void initStack(Stack *s);

// Push data ke Stack
void push(Stack *s, int data);

// Pop data dari Stack
int pop(Stack *s);

// Melihat elemen teratas Stack
int peek(Stack *s);

// Memeriksa apakah Stack kosong
int isEmpty(Stack *s);

// Menampilkan isi Stack
void display(Stack *s);

#endif
