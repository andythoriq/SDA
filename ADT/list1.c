#include "list1.h"

/********** BODY SUB PROGRAM ***********/

/**** Predikat untuk test keadaan LIST ****/
boolean ListEmpty(List L)
/* Mengirim true jika List Kosong */
{
    return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List *L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
    First(*L) = Nil;
}

/**** Manajemen Memory ****/

address Alokasi(infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, */
/* dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = (char*)malloc(strlen(X) + 1);
        if (Info(P) != NULL) {
            strcpy(Info(P), X);
            Next(P) = Nil;
        } else {
            free(P);
            P = Nil;
        }
    }
    return P;
}

void DeAlokasi(address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
    if (P != Nil)
    {
        if (Info(P) != NULL) {
            free(Info(P));
        }
        free(P);
    }
}

/**** Pencarian sebuah elemen List ****/

address Search(List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
    address P = First(L);
    boolean found = false;
    
    while ((P != Nil) && (!found))
    {
        if (strcmp(Info(P), X) == 0)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    return P;
}

boolean FSearch(List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    address PSearch = First(L);
    boolean found = false;
    
    while ((PSearch != Nil) && (!found))
    {
        if (PSearch == P)
        {
            found = true;
        }
        else
        {
            PSearch = Next(PSearch);
        }
    }
    return found;
}

address SearchPrec(List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    address P = First(L);
    address Prec = Nil;
    boolean found = false;
    
    while ((P != Nil) && (!found))
    {
        if (strcmp(Info(P), X) == 0)
        {
            found = true;
        }
        else
        {
            Prec = P;
            P = Next(P);
        }
    }
    return (found ? Prec : Nil);
}

// New: Search by string prefix
address SearchByPrefix(List L, infotype prefix)
{
    address P = First(L);
    boolean found = false;
    size_t prefixLen = strlen(prefix);
    
    while ((P != Nil) && (!found))
    {
        if (strncmp(Info(P), prefix, prefixLen) == 0)
        {
            found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    return P;
}

// New: Sort list lexicographically
void SortList(List *L)
{
    if (ListEmpty(*L) || Next(First(*L)) == Nil)
        return;

    boolean swapped;
    address ptr1;
    address lptr = Nil;
    char* temp;

    do {
        swapped = false;
        ptr1 = First(*L);

        while (Next(ptr1) != lptr)
        {
            if (strcmp(Info(ptr1), Info(Next(ptr1))) > 0)
            {
                temp = Info(ptr1);
                Info(ptr1) = Info(Next(ptr1));
                Info(Next(ptr1)) = temp;
                swapped = true;
            }
            ptr1 = Next(ptr1);
        }
        lptr = ptr1;
    } while (swapped);
}

/**** PRIMITIF BERDASARKAN NILAI ****/

/**** Penambahan Elemen ****/
void InsVFirst(List *L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(&(*L), P);
    }
}

void InsVLast(List *L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(&(*L), P);
    }
}

/**** Penghapusan Elemen ****/

void DelVFirst(List *L, infotype *X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
{
    address P = First(*L);
    if (P != Nil) {
        *X = (char*)malloc(strlen(Info(P)) + 1);
        if (*X != NULL) {
            strcpy(*X, Info(P));
            First(*L) = Next(First(*L));
            DeAlokasi(P);
        }
    }
}

void DelVLast(List *L, infotype *X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
{
    address PDel = First(*L);
    if (PDel != Nil) {
        DelLast(&(*L), &PDel);
        *X = (char*)malloc(strlen(Info(PDel)) + 1);
        if (*X != NULL) {
            strcpy(*X, Info(PDel));
            DeAlokasi(PDel);
        }
    }
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/

/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst(List *L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/* P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(List *L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
    if (First(*L) == Nil)
    {
        First(*L) = P;
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

/**** Penghapusan sebuah elemen ****/

void DelFirst(List *L, address *P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/* elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

{
    *P = First(*L);
    if (*P != Nil)
    {
        First(*L) = Next(First(*L));
        Next(*P) = Nil;
    }
}

void DelP(List *L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    address Prec = Nil;
    boolean found = false;
    
    while ((P != Nil) && (!found))
    {
        if (strcmp(Info(P), X) == 0)
        {
            found = true;
        }
        else
        {
            Prec = P;
            P = Next(P);
        }
    }
    
    if (found)
    {
        if (Prec == Nil)
        {
            First(*L) = Next(P);
        }
        else
        {
            Next(Prec) = Next(P);
        }
        Next(P) = Nil;
        DeAlokasi(P);
    }
}

void DelLast(List *L, address *P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
    address Prec = Nil;
    *P = First(*L);
    
    while (Next(*P) != Nil)
    {
        Prec = *P;
        *P = Next(*P);
    }
    
    if (Prec == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(Prec) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
    {
        Next(Prec) = Next(*Pdel);
        Next(*Pdel) = Nil;
    }
}

/**** PROSES SEMUA ELEMEN LIST ****/

void PrintInfo(List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/* diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
    if (First(L) == Nil)
    {
        printf("List Kosong .... \a\n");
    }
    else
    {
        address P = First(L);
        while (P != Nil)
        {
            printf("%s ", Info(P));
            P = Next(P);
        }
        printf("\n");
    }
}

int NbElmt(List L)
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
{
    int count = 0;
    address P = First(L);
    
    while (P != Nil)
    {
        count++;
        P = Next(P);
    }
    return count;
}

/***************************************/
/******* PROSES TERHADAP LIST ********/
/***************************************/

void DelAll(List *L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
    address P;
    while (First(*L) != Nil)
    {
        P = First(*L);
        First(*L) = Next(First(*L));
        DeAlokasi(P);
    }
}

void InversList(List *L)
/* IS : L sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
/* Membalik elemen list, tanpa melakukan alokasi / dealokasi */
{
    List Temp;
    CreateList(&Temp);
    
    while (First(*L) != Nil)
    {
        address P = First(*L);
        First(*L) = Next(First(*L));
        Next(P) = Nil;
        InsertFirst(&Temp, P);
    }
    
    First(*L) = First(Temp);
}

List FInversList(List L)
/* Mengirimkan list baru, hasil invers dari L */
{
    List Temp;
    CreateList(&Temp);
    address P = First(L);
    
    while (P != Nil)
    {
        infotype tempStr = (char*)malloc(strlen(Info(P)) + 1);
        if (tempStr != NULL)
        {
            strcpy(tempStr, Info(P));
            InsVFirst(&Temp, tempStr);
            free(tempStr);
            P = Next(P);
        }
    }
    return Temp;
}

void CopyList(List L1, List *L2)
/* IS : L1 sembarang */
/* FS : L2 = l1 */
/* L1 dan L2 "menunjuk" ke list yang sama, Tidak ada alokasi / dealokasi */
{
    CreateList(&(*L2));
    First(*L2) = First(L1);
}

List FCopyList(List L)
/* Mengirimkan List yang merupakan salinan L */
{
    List Temp;
    CreateList(&Temp);
    address P = First(L);
    
    while (P != Nil)
    {
        infotype tempStr = (char*)malloc(strlen(Info(P)) + 1);
        if (tempStr != NULL)
        {
            strcpy(tempStr, Info(P));
            InsVLast(&Temp, tempStr);
            free(tempStr);
            P = Next(P);
        }
    }
    return Temp;
}