/* File : queue.c */
/* Deskripsi : Body ADT Queue dengan representasi berkait dengan pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */

#include <stdlib.h>
#include "../include/queue.h"

/*********** BODY PROTOTYPE ****************/

/**** Konstruktor/Kreator Queue kosong ****/
void BuatQueueKosong(Queue *Q)
/* IS : Q sembarang */
/* FS : Membuat sebuah Queue Q yang kosong */
{
    CreateList(Q);
}

/**** Predikat Untuk test keadaan KOLEKSI ****/
boolean IsQueueKosong(Queue Q)
/* Mengirim true jika Queue kosong */
{
    return ListEmpty(Q);
}

/**** Menambahkan sebuah elemen ke Queue ****/
void Enqueue(Queue *Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian Tail dari Q */
/* IS : Q mungkin kosong */
/* FS : X menjadi Tail yang baru, Tail "maju" */
/*      Jika alokasi berhasil, Tail baru berisi X */
{
    InsVLast(Q, X);
}

/**** Menghapus sebuah elemen Queue ****/
void Dequeue(Queue *Q, infotype *X)
/* Proses: Menghapus X pada bagian Head dari Q dan mendealokasi elemen Head */
/* IS : Q tidak mungkin kosong */
/* FS : X = nilai elemen Head yang lama */
/*      Head "maju" */
{
    DelVFirst(Q, X);
}

/**** Operasi Lain ****/
int NbElmtQueue(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    return NbElmt(Q);
}

void TampilkanQueue(Queue Q)
/* IS : Q mungkin kosong */
/* FS : Menampilkan isi Queue ke layar */
/* Jika Queue kosong, akan menampilkan "Antrean Kosong" */
{
    if (IsQueueKosong(Q)) {
        printf("Antrean Kosong\n");
    } else {
        PrintInfo(Q);
    }
}
