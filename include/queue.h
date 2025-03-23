/* File : queue.h */
/* Deskripsi : ADT Queue dengan representasi berkait dengan pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "list.h"
#include <stdio.h>

/* Definisi Type Queue */
typedef List Queue;

/* Definisi Akses dengan Selektor */
#define Head(Q) First(Q)

/*********** PROTOTYPE ****************/

/**** Konstruktor/Kreator Queue kosong ****/
void BuatQueueKosong(Queue *Q);
/* IS : Q sembarang */
/* FS : Membuat sebuah Queue Q yang kosong */

/**** Predikat Untuk test keadaan KOLEKSI ****/
boolean IsQueueKosong(Queue Q);
/* Mengirim true jika Queue kosong */

/**** Menambahkan sebuah elemen ke Queue ****/
void Enqueue(Queue *Q, infotype X);
/* Proses: Mengalokasi X dan menambahkan X pada bagian Tail dari Q */
/* IS : Q mungkin kosong */
/* FS : X menjadi Tail yang baru, Tail "maju" */
/*      Jika alokasi berhasil, Tail baru berisi X */

/**** Menghapus sebuah elemen Queue ****/
void Dequeue(Queue *Q, infotype *X);
/* Proses: Menghapus X pada bagian Head dari Q dan mendealokasi elemen Head */
/* IS : Q tidak mungkin kosong */
/* FS : X = nilai elemen Head yang lama */
/*      Head "maju" */

/**** Operasi Lain ****/
int NbElmtQueue(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */

void TampilkanQueue(Queue Q);
/* IS : Q mungkin kosong */
/* FS : Menampilkan isi Queue ke layar */
/* Jika Queue kosong, akan menampilkan "Antrean kosong" */

#endif
