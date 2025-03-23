/* File : stack.h */
/* Deskripsi : ADT Stack dengan representasi berkait dengan pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "list.h"
#include <stdio.h>

/* Definisi Type Stack */
typedef List Stack;

/* Definisi Akses dengan Selektor */
#define Top(S) First(S)

/*********** PROTOTYPE ****************/

/**** Konstruktor/Kreator Stack kosong ****/
void BuatStackKosong(Stack *S);
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */

/**** Predikat Untuk test keadaan KOLEKSI ****/
boolean IsStackKosong(Stack S);
/* Mengirim true jika Stack kosong*/

/**** Menambahkan sebuah elemen ke Stack ****/
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S */
/* IS : S mungkin kosong, X terdefinisi */
/* FS : X menjadi Top yang baru jika alokasi berhasil */

/**** Menghapus sebuah elemen Stack ****/
void Pop(Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen Top yang lama, */

void TampilkanStack(Stack S);
/* IS : S mungkin kosong */
/* FS : Menampilkan isi Stack ke layar */
/* Jika Stack kosong, akan menampilkan "Stack Kosong" */

#endif
