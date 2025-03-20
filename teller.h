#ifndef TELLER_H
#define TELLER_H

#include "queue.h"
#include "boolean.h"

typedef struct {
    char name[50];        /* Nama teller */
    Queue queue;          /* Antrian untuk teller ini */
    int currentNumber;    /* Nomor antrian terakhir */
    int customersServed;  /* Jumlah pelanggan yang telah dilayani */
} Teller;

typedef struct {
    Teller *tellers;     /* Array of tellers */
    int numTellers;      /* Jumlah teller */
} TellerSystem;

/* *** Konstruktor *** */

/* membuat sistem teller dengan n teller */
void CreateTellerSystem(TellerSystem *ts, int n);

/* menambahkan teller baru (unik) */
boolean AddTeller(TellerSystem *ts, char *name, int index);

/* *** Operasi-operasi pada Teller *** */

/* mencari teller berdasarkan nama */
int FindTeller(TellerSystem ts, char *name);

/* get nomor antrian untuk teller tertentu */
int TakeQueueNumber(TellerSystem *ts, int tellerIndex);

/* proses antrian pada teller tertentu */
boolean ProcessQueue(TellerSystem *ts, int tellerIndex);

/* tampil status semua teller */
void DisplayAllTellers(TellerSystem ts);

/* tampil status teller tertentu */
void DisplayTeller(Teller t);

void CleanupTellerSystem(TellerSystem *ts);

/* memeriksa apakah nama teller sudah ada */
boolean IsTellerNameExists(TellerSystem ts, char *name);

#endif 