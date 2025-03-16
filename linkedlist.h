#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char nama[50];
    int nilai;
    struct node *next;
} node;

node *L1_first = NULL, *L1_last = NULL;
node *L2_first = NULL, *L2_last = NULL;

const int KKM = 70;

// function, procedure

void clear(node **first, node **last);

int count(node *p);

void copyFilterByNilai(node *L1, node **L2);

void insertSortedByNama(node **first, char nama[], int nilai);

void removeDuplicateNama(node *first);

void display(node *p);

void displayDescendingByNilai(node *first);

#endif