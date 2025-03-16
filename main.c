#include "linkedlist.h"

int main()
{
    // Isikan sejumlah elemen ke pada List L1, pastikan setiap pengisian elemen, isi List harus terurut Ascending menurut Nama.
    insertSortedByNama(&L1_first, "AAA", 60);
    insertSortedByNama(&L1_first, "BBB", 60);
    insertSortedByNama(&L1_first, "CCC", 70);
    insertSortedByNama(&L1_first, "CCC", 80);
    insertSortedByNama(&L1_first, "DDD", 80);
    insertSortedByNama(&L1_first, "DDD", 90);

    // Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut ascending berdasarkan nama
    display(L1_first);

    printf("\n\n");

    // Tampilkan isi List L1 (Nama, Nilai UTS SDA) terurut desending berdasarkan nilai
    displayDescendingByNilai(L1_first);

    printf("\n\n");

    // Hitung Jumlah elemen (jumlah mahasiswa pada list), kemudian tampilkan
    printf("jumlah mahasiswa : %d", count(L1_first));

    printf("\n\n");

    // Copy seluruh elemen pada list L1 yang Nilainya > 70 ke List L2
    copyFilterByNilai(L1_first, &L2_first);

    // Tampilkan Isi elemen List L2
    display(L2_first);
    printf("\n\n");

    // Jika pada L2 ada yang namanya sama, maka nama yang sama tersebut hanya boleh
    // ada 1 pada list (Nama pada List harus unik). Artinya jika ada nama yang sama, maka
    // hapus datanya dari list. – data yg dihapus adalah elemen yg duplikatnya bukan yang
    // pertama.
    removeDuplicateNama(L2_first);

    // Tampilkan elemen List L2 yang baru
    display(L2_first);
    printf("\n\n");

    // Hapus List L1 dan List L2
    clear(&L1_first, &L1_last);
    clear(&L2_first, &L2_last);

    return 0;
}