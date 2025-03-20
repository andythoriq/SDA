#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teller.h"

// untuk menmpilkan menu pilihan
void displayMenu()
{
    printf("\nSistem Antrian Bank\n");
    printf("1. Ambil Nomor Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Tampilkan Status Semua Teller\n");
    printf("4. Keluar\n");
    printf("Pilih opsi (1-4): ");
}

int main()
{
    TellerSystem ts;
    int numTellers;
    int choice;
    char tellerName[50];
    
    // Input jumlah teller
    printf("Masukkan jumlah teller: ");
    scanf("%d", &numTellers);
    
    // Buat teller
    CreateTellerSystem(&ts, numTellers);
    
    // Input nama untuk setiap teller
    for (int i = 0; i < numTellers; i++) {
        do {
            printf("Masukkan nama untuk teller ke-%d: ", i + 1);
            scanf(" %[^\n]s", tellerName);
            
            if (IsTellerNameExists(ts, tellerName)) {
                printf("Nama teller sudah ada! Gunakan nama lain.\n");
            }
        } while (!AddTeller(&ts, tellerName, i));
    }
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { // Ambil nomor antrian
                printf("\nDaftar Teller:\n");
                DisplayAllTellers(ts);
                printf("\nPilih teller (masukkan nama): ");
                scanf(" %[^\n]s", tellerName);
                
                int tellerIndex = FindTeller(ts, tellerName);
                if (tellerIndex == -1) {
                    printf("Teller tidak ditemukan!\n");
                } else {
                    int queueNumber = TakeQueueNumber(&ts, tellerIndex);
                    printf("\nNomor antrian Anda: %d\n", queueNumber);
                    DisplayTeller(ts.tellers[tellerIndex]);
                }
                break;
            }
            
            case 2: { // Proses antrian
                printf("\nDaftar Teller:\n");
                DisplayAllTellers(ts);
                printf("\nPilih teller untuk memproses antrian (masukkan nama): ");
                scanf(" %[^\n]s", tellerName);
                
                int tellerIndex = FindTeller(ts, tellerName);
                if (tellerIndex == -1) {
                    printf("Teller tidak ditemukan!\n");
                } else {
                    if (ProcessQueue(&ts, tellerIndex)) {
                        printf("\nBerhasil memproses antrian\n");
                    } else {
                        printf("\nTidak ada antrian untuk diproses!\n");
                    }
                    DisplayTeller(ts.tellers[tellerIndex]);
                }
                break;
            }
            
            case 3: { // Tampilkan status
                DisplayAllTellers(ts);
                break;
            }
            
            case 4: { // Keluar
                printf("\nTerima kasih telah menggunakan Sistem Antrian Bank!\n");
                break;
            }
            
            default: {
                printf("\nOpsi tidak valid! Silakan pilih 1-4\n");
                break;
            }
        }
    } while (choice != 4);
    
    // Bersihkan sistem
    CleanupTellerSystem(&ts);
    return 0;
}
