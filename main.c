#include "include/queue.h"
#include "include/list.h"
#include "include/stack.h"

int main()
{
    int choice, data;
    Queue Q; // menyatakan antrean
    BuatQueueKosong(&Q);
    Stack S; // menyatakan kereta
    BuatStackKosong(&S);

    printf("Selamat Datang di Sistem Kereta\n");
    printf("admin akan memasukkan id ke dalam antrean\n");
    printf("id akan diproses, lalu masuk kedalam kereta\n");
    printf("id akan turun dari kereta\n");
    printf("\n");

    while (choice != 0)
    {
        printf("1. Masukan semua penumpang (id) ke antrean\n");
        printf("2. Proses satu id dari antrean (masuk kereta)\n");
        printf("3. Turunkan satu id dari kereta\n");
        printf("0. exit\n");
        printf("Pilih : ");
        scanf("%d", &choice);
        int jml, i;

        while ((getchar()) != '\n');

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            printf("Masukkan jumlah data id yang akan mengantri: ");
            scanf("%d", &jml);
            if (jml <= 0)
            {
                printf("Jumlah harus lebih dari 0\n");
                break;
            }
            for (i = 0; i < jml; i++)
            {
                printf("Masukan id ke-%d : ", i + 1);
                scanf("%d", &data);
                Enqueue(&Q, data);
            }
            printf("penumpang (id) yang masuk ke dalam antrean: ");
            TampilkanQueue(Q);
            break;
        case 2:
            if (!IsQueueKosong(Q))
            {
                Dequeue(&Q, &data);
                printf("id %d masuk ke dalam kereta\n", data);
                Push(&S, data);
            }
            else
            {
                printf("Antrean kosong\n");
            }
            printf("Antrean saat ini: ");
            TampilkanQueue(Q);
            printf("Penumpang kereta saat ini: ");
            TampilkanStack(S);
            break;
        case 3:
            if (!IsStackKosong(S))
            {
                Pop(&S, &data);
                printf("id %d turun dari kereta\n", data);
            }
            else
            {
                printf("Kereta kosong\n");
            }
            printf("Penumpang kereta saat ini: ");
            TampilkanStack(S);
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
    }
    DelAll(&Q);
    DelAll(&S);
    return 0;
}