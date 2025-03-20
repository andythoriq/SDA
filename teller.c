#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teller.h"

// untuk membuat teller
void CreateTellerSystem(TellerSystem *ts, int n) {
    ts->numTellers = n;
    ts->tellers = (Teller *)malloc(n * sizeof(Teller));
    
    for (int i = 0; i < n; i++) {
        ts->tellers[i].currentNumber = 0;
        ts->tellers[i].customersServed = 0;
        CreateQueue(&(ts->tellers[i].queue));
    }
}

// untuk menambahkan teller baru
boolean AddTeller(TellerSystem *ts, char *name, int index) {
    if (index < 0 || index >= ts->numTellers) {
        return false;
    }
    
    // Periksa apakah nama sudah ada
    if (IsTellerNameExists(*ts, name)) {
        return false;
    }
    
    strcpy(ts->tellers[index].name, name);
    return true;
}

boolean IsTellerNameExists(TellerSystem ts, char *name) {
    for (int i = 0; i < ts.numTellers; i++) {
        if (strcmp(ts.tellers[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

int FindTeller(TellerSystem ts, char *name) {
    for (int i = 0; i < ts.numTellers; i++) {
        if (strcmp(ts.tellers[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// untuk mengambil nomor antrian
int TakeQueueNumber(TellerSystem *ts, int tellerIndex) {
    if (tellerIndex < 0 || tellerIndex >= ts->numTellers) {
        return -1;
    }
    
    Teller *t = &(ts->tellers[tellerIndex]);
    t->currentNumber++;
    enqueue(&(t->queue), t->currentNumber);
    
    return t->currentNumber;
}

// untuk memproses antrian
boolean ProcessQueue(TellerSystem *ts, int tellerIndex) {
    if (tellerIndex < 0 || tellerIndex >= ts->numTellers) {
        return false;
    }
    
    Teller *t = &(ts->tellers[tellerIndex]);
    if (isEmpty(t->queue)) {
        return false;
    }
    
    dequeue(&(t->queue));
    t->customersServed++;
    return true;
}

// untuk menampilkan status teller
void DisplayTeller(Teller t) {
    printf("\nTeller: %s\n", t.name);
    printf("Jumlah pelanggan dilayani: %d\n", t.customersServed);
    printf("Antrian saat ini: ");
    displayQueue(t.queue);
    printf("\n");
}

// untuk menampilkan status semua teller
void DisplayAllTellers(TellerSystem ts) {
    printf("\n=== Status Semua Teller ===\n");
    for (int i = 0; i < ts.numTellers; i++) {
        printf("\n[Teller %d]\n", i + 1);
        DisplayTeller(ts.tellers[i]);
    }
}

void CleanupTellerSystem(TellerSystem *ts) {
    free(ts->tellers);
    ts->numTellers = 0;
} 