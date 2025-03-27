#include "ADT/kota.h"

void tampilkanMenu()
{
    printf("\nSTUDI KASUS 5:\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Nama ke Kota\n");
    printf("3. Hapus Kota\n");
    printf("4. Hapus Nama dari Kota\n");
    printf("5. Tampilkan Semua Kota dan Nama\n");
    printf("6. Tampilkan Nama-nama di Kota Tertentu\n");
    printf("7. Tampilkan Total Nama\n");
    printf("8. Tampilkan Jumlah Nama di Kota Tertentu\n");
    printf("0. Keluar\n");
    printf("Pilihan Anda: ");
}

void bersihkanMemori(DaftarKota *D)
{
    int i;
    for (i = 0; i < D->jumlahKota; i++)
    {
        DelAll(&(D->kota[i].p));
    }
    D->jumlahKota = 0;
}

int main()
{
    DaftarKota D;
    char namaKota[50], nama[50];
    int pilihan;

    createDaftarKota(&D);

    do
    {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // Membersihkan newline

        switch (pilihan)
        {
        case 1:
            printf("Masukkan nama kota: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0; // Menghapus newline
            tambahKota(&D, namaKota);
            printf("Kota %s berhasil ditambahkan!\n", namaKota);
            break;

        case 2:
            printf("Masukkan nama kota: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            printf("Masukkan nama: ");
            fgets(nama, 50, stdin);
            nama[strcspn(nama, "\n")] = 0;
            tambahNama(&D, namaKota, nama);
            printf("Nama %s berhasil ditambahkan ke kota %s!\n", nama, namaKota);
            break;

        case 3:
            printf("Masukkan nama kota yang akan dihapus: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            hapusKota(&D, namaKota);
            printf("Kota %s dan semua namanya berhasil dihapus!\n", namaKota);
            break;

        case 4:
            printf("Masukkan nama kota: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            printf("Masukkan nama yang akan dihapus: ");
            fgets(nama, 50, stdin);
            nama[strcspn(nama, "\n")] = 0;
            hapusNama(&D, namaKota, nama);
            printf("Nama %s berhasil dihapus dari kota %s!\n", nama, namaKota);
            break;

        case 5:
            tampilkanSemuaKota(D);
            break;

        case 6:
            printf("Masukkan nama kota: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            tampilkanKota(D, namaKota);
            break;

        case 7:
            printf("Total nama dari semua kota: %d\n", hitungTotalNama(D));
            break;

        case 8:
            printf("Masukkan nama kota: ");
            fgets(namaKota, 50, stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;
            printf("Jumlah nama di kota %s: %d\n", namaKota, hitungNamaPerKota(D, namaKota));
            break;

        case 0:
            bersihkanMemori(&D);
            printf("Terima kasih telah menggunakan program ini!\n");
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}