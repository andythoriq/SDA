#include "kota.h"

Kota* AllocKota() {
    return (Kota*)malloc(sizeof(Kota));
}

boolean IsDaftarKotaEmpty(const ListOfKota *L)
{
    return (L->First == Nil);
}

boolean HandleEmptyKota(const ListOfKota *L)
{
    if (IsDaftarKotaEmpty(L)) {
        printf("Data atau List kosong, mohon isi terlebih dahulu!\n");
        return true;
    }
    return false;
}

boolean HandleKotaNotFound(const ListOfKota *L, const char namaKota[])
{
    if (!isKotaFound(L, namaKota)) {
        printf("Kota dengan nama %s tidak ditemukan!\n", namaKota);
        return true;
    }
    return false;
}

boolean isKotaFound(const ListOfKota *L, const char namaKota[])
{
    Kota *curr = L->First;

    while (curr != Nil)
    {
        if (strcmp(curr->kt, namaKota) == 0) {
            return true;
        }
        curr = curr->nextKt;
    }

    return false;
}

void AddKota(ListOfKota *L, char namaKota[])
{
    Kota *newKota = AllocKota();
    if (newKota != Nil) {
        CreateEmptyQueue(&newKota->daftarNama);
        strcpy(newKota->kt, namaKota);
        newKota->nextKt = Nil;
        
        if (IsDaftarKotaEmpty(L)) {
            L->First = newKota;
        } else {
            Kota *curr = L->First;
            while (curr->nextKt != Nil) {
                curr = curr->nextKt;
            }
            curr->nextKt = newKota;
        }
        printf("Kota %s berhasil ditambahkan!\n", namaKota);
    }
}

void AddNama(ListOfKota *L, char namaKota[], char namaOrang[])
{
    if (HandleEmptyKota(L)) {
        return;
    }
    if (HandleKotaNotFound(L, namaKota)) {
        return;
    }

    Kota *curr = L->First;

    while (curr != Nil) {
        if (strcmp(curr->kt, namaKota) == 0) {
            if (Enqueue(&curr->daftarNama, namaOrang)) {
                printf("Nama %s berhasil ditambahkan ke kota %s!\n", namaOrang, namaKota);
            } else {
                printf("Gagal menambahkan nama %s ke kota %s!\n", namaOrang, namaKota);
            }
            break;
        }
        curr = curr->nextKt;
    }
}

void DeleteKota(ListOfKota *L, char namaKota[])
{
    if (HandleEmptyKota(L)) {
        return;
    }
    if (HandleKotaNotFound(L, namaKota)) {
        return;
    }

    Kota *curr = L->First;
    Kota *prev = Nil;

    while (curr != Nil) {
        if (strcmp(curr->kt, namaKota) == 0) {
            ClearQueue(&curr->daftarNama);

            if (prev == Nil) {
                L->First = curr->nextKt;
            } else {
                prev->nextKt = curr->nextKt;
            }

            free(curr);
            break;
        }
        prev = curr;
        curr = curr->nextKt;
    }
    printf("Kota %s dan semua namanya berhasil dihapus!\n", namaKota);
}

void DeleteNama(ListOfKota *L, char namaKota[])
{
    if (HandleEmptyKota(L)) {
        return;
    }
    if (HandleKotaNotFound(L, namaKota)) {
        return;
    }

    Kota *curr = L->First;
    infotype nama = Nil;

    while (curr != Nil) {
        if (strcmp(curr->kt, namaKota) == 0) {
            if (Dequeue(&curr->daftarNama, &nama)) {
                printf("Data dengan nama: %s telah dihapus (keluar antrean)\n", nama);
            } else {
                printf("Tidak ada nama dalam antrean di kota %s.\n", namaKota);
            }
            break;
        }
        curr = curr->nextKt;
    }
}


void DisplayAllKota(const ListOfKota *L)
{
    if (HandleEmptyKota(L)) {
        return;
    }

    Kota * curr = L->First;

    while (curr != Nil)
    {
        printf("\nKota: %s\n", curr->kt);
        printf("Nama-nama: ");
        DisplayQueue(curr->daftarNama);
        printf("\n");
        curr = curr->nextKt;
    }
}

void DisplayNameByKota(const ListOfKota *L, char namaKota[])
{
    if (HandleEmptyKota(L)) {
        return;
    }
    if (HandleKotaNotFound(L, namaKota)) {
        return;
    }


    Kota *curr = L->First;

    while (curr != Nil)
    {
        if (strcmp(curr->kt, namaKota) == 0) {
            printf("\nKota: %s\n", curr->kt);
            printf("Nama-nama: ");
            DisplayQueue(curr->daftarNama);
            printf("\n");
            break;
        }
    }
}