/* File : stack.c */
/* Deskripsi : Body ADT Stack dengan representasi berkait dengan pointer */
/* Representasi address dengan pointer */
/* InfoType adalah integer */

#include <stdlib.h>
#include "../include/stack.h"

/*********** PROTOTYPE ****************/

/**** Konstruktor/Kreator Stack kosong ****/
void BuatStackKosong(Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
{
    CreateList(S);
}

/**** Predikat Untuk test keadaan KOLEKSI ****/
boolean IsStackKosong(Stack S)
/* Mengirim true jika Stack kosong*/
{
    return ListEmpty(S);
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* IS : S mungkin kosong, X terdefinisi */
/* FS : X menjadi Top yang baru jika alokasi berhasil */
{
    InsVFirst(S, X);
}

/**** Menghapus sebuah elemen Stack ****/
void Pop(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen Top yang lama, */
{
    DelVFirst(S, X);
}

void TampilkanStack(Stack S)
/* IS : S mungkin kosong */
/* FS : Menampilkan isi Stack ke layar */
/* Jika Stack kosong, akan menampilkan "Stack Kosong" */
{
    if (IsStackKosong(S)) {
        printf("Stack Kosong\n");
    } else {
        PrintInfo(S);
    }
}
