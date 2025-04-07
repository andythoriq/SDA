#ifndef KOTA_H
#define KOTA_H

// #include "./ADT/stack.h"
#include "./ADT/queue.h"

#define MAX_NAMA_KOTA 50

typedef struct Kota {
    char kt[MAX_NAMA_KOTA];
    Queue daftarNama;
    struct Kota *nextKt;
} Kota;

typedef struct {
    Kota *First;
}ListOfKota;

// alokasi (konstruktor)
Kota* AllocKota();

// pengecekan
boolean IsDaftarKotaEmpty(const ListOfKota *L);

// Operasi Entry
void AddKota(ListOfKota *L, char namaKota[]);

void AddNama(ListOfKota *L, char namaKota[], char namaOrang[]);

// Operasi Delete
void DeleteKota(ListOfKota *L, char namaKota[]);

void DeleteNama(ListOfKota *L, char namaKota[]);

// Operasi Tampilan
void DisplayAllKota(const ListOfKota *L);

void DisplayNameByKota(const ListOfKota *L, char namaKota[]);

// Operasi Tambahan
// int CountAllName(Kota K);

// int CountKota(ListOfKota *L);

// int CountNameInKota(Kota K, char namaKota[]);

boolean HandleEmptyKota(const ListOfKota *L);

boolean HandleKotaNotFound(const ListOfKota *L, const char namaKota[]);

boolean isKotaFound(const ListOfKota *L, const char namaKota[]);

#endif