#ifndef KOTA_H
#define KOTA_H

#include "list1.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

#define MAXKOTA 10

typedef struct
{
    char kt[50]; // nama kota
    List p;      // list nama orang
} Kota;

typedef struct
{
    Kota kota[MAXKOTA]; // array of Kota
    int jumlahKota;     // jumlah kota yang tersimpan
} DaftarKota;

// Konstruktor
void createDaftarKota(DaftarKota *D);

// Operasi Entry
void tambahKota(DaftarKota *D, char namaKota[]);

void tambahNama(DaftarKota *D, char namaKota[], char nama[]);

// Operasi Delete
void hapusKota(DaftarKota *D, char namaKota[]);

void hapusNama(DaftarKota *D, char namaKota[], char nama[]);

// Operasi Tampilan
void tampilkanSemuaKota(DaftarKota D);

void tampilkanKota(DaftarKota D, char namaKota[]);

// Operasi Tambahan
int hitungTotalNama(DaftarKota D);

int hitungNamaPerKota(DaftarKota D, char namaKota[]);

#endif
