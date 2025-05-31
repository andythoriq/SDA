/**
 * @file    nbtree.h
 * @brief   Header file untuk  non-binary tree implementation in C.
 * @details Struktur data ini digunakan untuk menyimpan informasi
 *          tentang pohon N-ary, termasuk node, hubungan antar node,
 *          dan operasi-operasi dasar pada pohon.
 * @note    Struktur ini menggunakan array untuk menyimpan node-node
 *          pohon, dengan indeks 1 sebagai root. Indeks 0 tidak digunakan.
 *          dan penghitungan elemen dalam pohon.
 * @note    Untuk menggunakan struktur ini, pastikan untuk menginisialisasi
 *          pohon dengan jumlah node dan relasi yang sesuai sebelum melakukan
 *          operasi lainnya.
 * @note    Pastikan juga untuk mematuhi batasan jumlah maksimum node
 *          yang ditentukan oleh makro `jml_maks`.
 * @note    Untuk informasi lebih lanjut, silakan lihat dokumentasi
 *          atau komentar dalam kode.
 * @author  Thoriq
 * @date    2025-05-20
 */
#ifndef NBTREE_H
#define NBTREE_H

#include "queue/queue.h"
#include "stack/stack.h"
#include <stdbool.h>
#include <stdio.h>

#define jml_maks 20

#define kebawah 1 // traverse ke anak pertama
#define keatas 2  // traverse ke parent
#define kekanan 3 // traverse ke next brother
#define nil 0     // penanda tidak ada anak atau parent

// typedef char infotype;
// typedef int address;

typedef struct {
    char info;
    int ps_fs, ps_nb, ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

void NbTree_Create(Isi_Tree X, int Jml_Node);

bool NbTree_IsEmpty(Isi_Tree P);

void NbTree_PreOrder(Isi_Tree P);

void NbTree_InOrder(Isi_Tree P);

void NbTree_PostOrder(Isi_Tree P);

void NbTree_PreOrderRec(Isi_Tree P, int i);

void NbTree_InOrderRec(Isi_Tree P, int i);

void NbTree_PostOrderRec(Isi_Tree P, int i);

void NbTree_LevelOrder(Isi_Tree X);

void NbTree_Print(Isi_Tree P);

bool NbTree_Search_char(Isi_Tree P, char X);
// bool NbTree_Search_string(Isi_Tree P, char *X);
// bool NbTree_Search_int(Isi_Tree P, int X);

int NbTree_CountElement(Isi_Tree P);

int NbTree_CountLeaf(Isi_Tree P);

int NbTree_Level_char(Isi_Tree P, char X);
// int NbTree_Level_string(Isi_Tree P, char *X);
// int NbTree_Level_int(Isi_Tree P, int X);

int NbTree_Depth(Isi_Tree P);

int NbTree_Max(int a, int b);

int NbTree_Height(Isi_Tree P);

bool NbTree_IsLeaf(Isi_Tree P, int i);

#endif // TREE_H