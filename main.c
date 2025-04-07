#include <stdio.h>
#include <string.h>
#include "kota.h"

void ClearMemory(ListOfKota *L)
{
    Kota *curr = L->First;
    Kota *temp;

    while (curr != Nil)
    {
        DelAll(&curr->daftarNama);
        temp = curr;
        curr = curr->nextKt;
        free(temp);
    }

    L->First = Nil;
}

void tampilkanMenu()
{
    printf("\nSTUDI KASUS 6:\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Nama ke Kota\n");
    printf("3. Hapus Kota\n");
    printf("4. Hapus Nama dari Kota\n");
    printf("5. Tampilkan Semua Kota dan Nama\n");
    printf("6. Tampilkan Nama-nama di Kota Tertentu\n");
    printf("0. Keluar\n");
    printf("Pilihan Anda: ");
}

void InputNama(const char* prompt, char* nama)
{
    do {
        printf("%s", prompt);
        fgets(nama, 50, stdin);
        nama[strcspn(nama, "\n")] = '\0';
        
        if (strlen(nama) == 0) {
            printf("Input tidak boleh kosong. Silakan coba lagi!\n");
        }
    } while (strlen(nama) == 0);
}

int main()
{
    ListOfKota ListKota;
    ListKota.First = NULL;
    char namaKota[50], namaOrang[50];
    int pilihan = 0;

    printf("Masukkan minimal 5 nama kota terlebih dahulu:\n");
    int jumlahKota = 0;
    while (jumlahKota < 5)
    {
        printf("Kota ke-%d: ", jumlahKota + 1);
        InputNama("", namaKota);
        
        if (isKotaFound(&ListKota, namaKota)) {
            printf("Kota %s sudah ada. Masukkan kota lain.\n", namaKota);
        } else {
            AddKota(&ListKota, namaKota);
            jumlahKota++;
        }
    }

    do
    {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan)
        {
        case 1:
            InputNama("Masukkan nama kota: ", namaKota);
            AddKota(&ListKota, namaKota);
            break;

        case 2:
            InputNama("Masukkan nama kota: ", namaKota);
            InputNama("Masukkan nama: ", namaOrang);
            AddNama(&ListKota, namaKota, namaOrang);
            break;

        case 3:
            InputNama("Masukkan nama kota yang akan dihapus: ", namaKota);
            DeleteKota(&ListKota, namaKota);
            break;

        case 4:
            InputNama("Masukkan nama kota: ", namaKota);
            DeleteNama(&ListKota, namaKota);
            break;

        case 5:
            DisplayAllKota(&ListKota);
            break;

        case 6:
            InputNama("Masukkan nama kota: ", namaKota);
            DisplayNameByKota(&ListKota, namaKota);
            break;

        case 0:
            printf("Terima kasih telah menggunakan program ini!\n");
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);

    ClearMemory(&ListKota);
    return 0;
}
