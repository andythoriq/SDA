#include "kota.h"

void createDaftarKota(DaftarKota *D)
{
    D->jumlahKota = 0;
}

void tambahKota(DaftarKota *D, char namaKota[])
{
    if (D->jumlahKota < MAXKOTA)
    {
        strcpy(D->kota[D->jumlahKota].kt, namaKota);
        CreateList(&(D->kota[D->jumlahKota].p));
        D->jumlahKota++;
    }
}

void tambahNama(DaftarKota *D, char namaKota[], char nama[])
{
    int i;
    for (i = 0; i < D->jumlahKota; i++)
    {
        if (strcmp(D->kota[i].kt, namaKota) == 0)
        {
            InsVLast(&(D->kota[i].p), nama);
            break;
        }
    }
}

void hapusKota(DaftarKota *D, char namaKota[])
{
    int i, j;
    for (i = 0; i < D->jumlahKota; i++)
    {
        if (strcmp(D->kota[i].kt, namaKota) == 0)
        {
            // Hapus semua nama dalam list
            DelAll(&(D->kota[i].p));

            // Geser semua kota setelahnya
            for (j = i; j < D->jumlahKota - 1; j++)
            {
                strcpy(D->kota[j].kt, D->kota[j + 1].kt);
                D->kota[j].p = D->kota[j + 1].p;
            }
            D->jumlahKota--;
            break;
        }
    }
}

void hapusNama(DaftarKota *D, char namaKota[], char nama[])
{
    int i;
    for (i = 0; i < D->jumlahKota; i++)
    {
        if (strcmp(D->kota[i].kt, namaKota) == 0)
        {
            DelP(&(D->kota[i].p), nama);
            break;
        }
    }
}

void tampilkanSemuaKota(DaftarKota D)
{
    int i;
    for (i = 0; i < D.jumlahKota; i++)
    {
        printf("\nKota: %s\n", D.kota[i].kt);
        printf("Nama-nama: ");
        PrintInfo(D.kota[i].p);
        printf("\n");
    }
}

void tampilkanKota(DaftarKota D, char namaKota[])
{
    int i;
    for (i = 0; i < D.jumlahKota; i++)
    {
        if (strcmp(D.kota[i].kt, namaKota) == 0)
        {
            printf("\nKota: %s\n", D.kota[i].kt);
            printf("Nama-nama: ");
            PrintInfo(D.kota[i].p);
            printf("\n");
            break;
        }
    }
}

int hitungTotalNama(DaftarKota D)
{
    int i, total = 0;
    for (i = 0; i < D.jumlahKota; i++)
    {
        total += NbElmt(D.kota[i].p);
    }
    return total;
}

int hitungNamaPerKota(DaftarKota D, char namaKota[])
{
    int i;
    for (i = 0; i < D.jumlahKota; i++)
    {
        if (strcmp(D.kota[i].kt, namaKota) == 0)
        {
            return NbElmt(D.kota[i].p);
        }
    }
    return 0;
}
