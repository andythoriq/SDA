#include "nbtree.h"

bool NbTree_IsEmpty(Isi_Tree P) {
    return P[1].info == ' ';
}

void NbTree_Create(Isi_Tree X, int Jml_Node) {
    if (Jml_Node < 1 || Jml_Node > jml_maks) {
        printf("Jumlah node harus antara 1 dan %d.\n", jml_maks);
        return;
    }

    // inisialisasi dengna mengosongkan semua node atau element
    for (int i = 0; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    int i;
    char temp;

    for (i = 1; i <= Jml_Node; i++) {
        printf("Masukkan info node ke-%d: ", i);
        scanf(" %c", &temp);
        X[i].info = temp;

        if (i == 1) {
            X[i].ps_pr = 0;
        } else {
            printf("Masukkan parent dari node %c (indeks): ", temp);
            int parent;
            scanf("%d", &parent);
            X[i].ps_pr = parent;
            if (X[parent].ps_fs == 0) {
                X[parent].ps_fs = i;
            } else {
                int sibling = X[parent].ps_fs;
                while (X[sibling].ps_nb != 0) {
                    sibling = X[sibling].ps_nb;
                }
                X[sibling].ps_nb = i;
            }
        }
    }
}

void NbTree_PreOrder(Isi_Tree T) {
    if (NbTree_IsEmpty(T)) {
        printf("Tree is empty!\n");
        return;
    }

    Stack S;
    initStack(&S);
    push_int(&S, nil); // inisiasi dengan nilai nil
    int pcur = 1;      // asumsi root selalu di indeks 1

    while (pcur != nil) {
        printf("%c ", T[pcur].info); // kunjungan resmi

        if (T[pcur].ps_fs != nil) {
            if (T[pcur].ps_nb != nil)
                push_int(&S, T[pcur].ps_nb);
            pcur = T[pcur].ps_fs;
        } else if (T[pcur].ps_nb != nil) {
            pcur = T[pcur].ps_nb;
        } else {
            pcur = pop_int(&S);
        }
    }

    freeStack(&S);
}

void NbTree_InOrder(Isi_Tree T) { /* Knuth */
    if (NbTree_IsEmpty(T)) {
        printf("Tree is empty!\n");
        return;
    }

    int pcur = 1;
    bool resmi = true;

    while (pcur != nil) {
        if (T[pcur].ps_fs != nil && resmi) {
            // ke anak pertama
            pcur = T[pcur].ps_fs;
        } else {
            if (resmi) {
                // Kunjungan resmi node ini
                printf("%c ", T[pcur].info);
            }

            // jika node ini adalah anak pertama dari parent-nya, maka kunjungi
            // parent
            if (T[pcur].ps_pr != nil && T[T[pcur].ps_pr].ps_fs == pcur) {
                printf("%c ", T[T[pcur].ps_pr].info);
            }

            if (T[pcur].ps_nb != nil) {
                // ke saudara kanan
                pcur = T[pcur].ps_nb;
                resmi = true;
            } else {
                // naik ke parent
                pcur = T[pcur].ps_pr;
                resmi = false; // numpang lewat
            }
        }
    }
}

void NbTree_PostOrder(Isi_Tree T) {
    if (NbTree_IsEmpty(T)) {
        printf("Tree is empty!\n");
        return;
    }

    Stack S;
    initStack(&S);
    int pcur = 1;
    int arah = kebawah;

    while (pcur != nil) {
        switch (arah) {
        case kebawah:
            if (T[pcur].ps_fs != nil) {
                arah = kebawah;
                push_int(&S, pcur);
                pcur = T[pcur].ps_fs;
            } else if (T[pcur].ps_fs == nil && T[pcur].ps_nb != nil) {
                arah = kekanan;
                printf("%c ", T[pcur].info);
                pcur = T[pcur].ps_nb;
            } else {
                arah = keatas;
                printf("%c ", T[pcur].info);
                pcur = pop_int(&S);
            }
            break;

        case kekanan:
            if (T[pcur].ps_fs != nil) {
                arah = kebawah;
                push_int(&S, pcur);
                pcur = T[pcur].ps_fs;
            } else if (T[pcur].ps_fs == nil && T[pcur].ps_nb != nil) {
                arah = kekanan;
                printf("%c ", T[pcur].info);
                pcur = T[pcur].ps_nb;
            } else {
                arah = keatas;
                printf("%c ", T[pcur].info);
                pcur = pop_int(&S);
            }
            break;

        case keatas:
            if (pcur == 1) {
                printf("%c ", T[pcur].info);
                pcur = nil;
            } else if (T[pcur].ps_nb != nil) {
                arah = kekanan;
                printf("%c ", T[pcur].info);
                pcur = T[pcur].ps_nb;
            } else {
                arah = keatas;
                printf("%c ", T[pcur].info);
                pcur = pop_int(&S);
            }
            break;
        }
    }

    freeStack(&S);
}

void NbTree_PreOrderRec(Isi_Tree P, int i) {
    if (i == nil || P[i].info == ' ')
        return;

    printf("%c ", P[i].info); // kunjungan resmi

    int child = P[i].ps_fs;
    while (child != nil) {
        NbTree_PreOrderRec(P, child);
        child = P[child].ps_nb;
    }
}

void NbTree_InOrderRec(Isi_Tree P, int i) {
    if (i == nil || P[i].info == ' ')
        return;

    int child = P[i].ps_fs;

    if (child != nil) {
        NbTree_InOrderRec(P, child); // anak pertama
        printf("%c ", P[i].info);    // akar setelah anak pertama

        child = P[child].ps_nb;
        while (child != nil) {
            NbTree_InOrderRec(P, child);
            child = P[child].ps_nb;
        }
    } else {
        // jika tidak ada anak, kunjungi langsung
        printf("%c ", P[i].info);
    }
}

void NbTree_PostOrderRec(Isi_Tree P, int i) {
    if (i == nil || P[i].info == ' ')
        return;

    int child = P[i].ps_fs;
    while (child != nil) {
        NbTree_PostOrderRec(P, child);
        child = P[child].ps_nb;
    }

    printf("%c ", P[i].info); // kunjungi root setelah anak-anaknya
}

// void NbTree_LevelOrder(Isi_Tree X) {
//     if (NbTree_IsEmpty(X)) {
//         printf("Tree is empty!\n");
//         return;
//     }

//     Queue Q;
//     initQueue(&Q);
//     enqueue_int(&Q, 1); // masukkan root ke queue

//     while (!isQueueEmpty(&Q)) {
//         int pcur = dequeue_int(&Q);
//         printf("%c ", X[pcur].info); // kunjungan resmi

//         // Tambah semua children ke queue (anak pertama dan semua saudaranya)
//         int child = X[pcur].ps_fs;
//         while (child != nil) {
//             enqueue_int(&Q, child);
//             child = X[child].ps_nb;
//         }
//     }
// }

void NbTree_LevelOrder(Isi_Tree X) {
    if (NbTree_IsEmpty(X)) {
        printf("Tree is empty!\n");
        return;
    }

    int pcur;
    Queue Q;
    initQueue(&Q);

    // root
    printf("%c ", X[1].info);
    pcur = X[1].ps_fs;

    while (pcur != nil) {
        // current node
        printf("%c ", X[pcur].info);

        // jika current node punya children, tambah first son ke queue
        if (X[pcur].ps_fs != nil) {
            if (!isQueueFull(&Q)) {
                enqueue_int(&Q, X[pcur].ps_fs);
            }
        }

        // pindah ke next brother jika ada
        if (X[pcur].ps_nb != nil) {
            pcur = X[pcur].ps_nb;
        } else {
            // tidak ada lagi brothers, jadi ambil dari queue
            if (!isQueueEmpty(&Q)) {
                pcur = dequeue_int(&Q);
            } else {
                pcur = nil;
            }
        }
    }

    freeQueue(&Q);
}

// int NbTree_LevelOrderRec

void NbTree_Print(Isi_Tree P) {
    if (NbTree_IsEmpty(P)) {
        printf("Tree is empty!\n");
        return;
    }

    printf("Isi Tree:\n");
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            printf("Node %d: %c, Parent: %d, First Son: %d, Next Brother: %d\n",
                   i, P[i].info, P[i].ps_pr, P[i].ps_fs, P[i].ps_nb);
        }
    }
}

bool NbTree_Search_char(Isi_Tree P, char X) {
    if (NbTree_IsEmpty(P)) {
        return false;
    }

    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X) {
            return true;
        }
    }
    return false;
}

int NbTree_CountElement(Isi_Tree P) {
    if (NbTree_IsEmpty(P)) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            count++;
        }
    }
    return count;
}

int NbTree_CountLeaf(Isi_Tree P) {
    if (NbTree_IsEmpty(P)) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ' && P[i].ps_fs == nil) {
            count++;
        }
    }
    return count;
}

// int NbTree_Level_char(Isi_Tree P, char X) {
//     if (NbTree_IsEmpty(P)) {
//         return -1;
//     }

//     // Menggunakan BFS untuk mencari level dari karakter X
//     Queue Q;
//     Queue LevelQ; // Queue untuk melacak levels
//     initQueue(&Q);
//     initQueue(&LevelQ);

//     // mulai dari root (index 1) di level 0
//     enqueue_int(&Q, 1);
//     enqueue_int(&LevelQ, 0);

//     while (!isQueueEmpty(&Q)) {
//         int pcur = dequeue_int(&Q);
//         int currentLevel = dequeue_int(&LevelQ);

//         if (P[pcur].info == X) {
//             return currentLevel;
//         }

//         // tambah anak ke queue dengan increment level
//         int child = P[pcur].ps_fs;
//         while (child != nil) {
//             enqueue_int(&Q, child);
//             enqueue_int(&LevelQ, currentLevel + 1);
//             child = P[child].ps_nb;
//         }
//     }

//     return -1;
// }

int NbTree_Level_char(Isi_Tree P, char X) {
    if (NbTree_IsEmpty(P)) {
        return -1;
    }

    // jika langsung ketemu
    if (P[1].info == X) {
        return 0;
    }

    int pcur;
    Queue Q;
    Queue LevelQ;
    initQueue(&Q);
    initQueue(&LevelQ);

    // Mulai dari anak pertama root di level 1
    pcur = P[1].ps_fs;
    int currentLevel = 1;

    while (pcur != nil) {
        // cek current node
        if (P[pcur].info == X) {
            freeQueue(&Q);
            freeQueue(&LevelQ);
            return currentLevel;
        }

        // jika current node punya children, tambah first child ke queue
        if (P[pcur].ps_fs != nil) {
            if (!isQueueFull(&Q)) {
                enqueue_int(&Q, P[pcur].ps_fs);
                enqueue_int(&LevelQ, currentLevel + 1);
            }
        }

        // Move ke next brother jika ada (same level)
        if (P[pcur].ps_nb != nil) {
            pcur = P[pcur].ps_nb;
            // Level tetap sama untuk brothers
        } else {
            // tidak ada lagi brothers, jadi ambil next node dari queue (level
            // berbeda)
            if (!isQueueEmpty(&Q)) {
                pcur = dequeue_int(&Q);
                currentLevel = dequeue_int(&LevelQ);
            } else {
                pcur = nil;
            }
        }
    }

    freeQueue(&Q);
    freeQueue(&LevelQ);
    return -1; // Character not found
}

int NbTree_Max(int a, int b) {
    return (a > b) ? a : b;
}

int NbTree_Depth(Isi_Tree P) {
    // Check if tree is empty first
    if (NbTree_IsEmpty(P)) {
        return -1; // or 0, depending on your convention for empty tree
    }

    int maxDepth = 0;
    Queue Q;
    Queue LevelQ;
    initQueue(&Q);
    initQueue(&LevelQ);

    // Start from root at level 0
    enqueue_int(&Q, 1);
    enqueue_int(&LevelQ, 0);

    while (!isQueueEmpty(&Q)) {
        int pcur = dequeue_int(&Q);
        int currentLevel = dequeue_int(&LevelQ);

        // Update maximum depth
        maxDepth = NbTree_Max(maxDepth, currentLevel);

        // Add all children to queue
        int child = P[pcur].ps_fs;
        while (child != nil) {
            enqueue_int(&Q, child);
            enqueue_int(&LevelQ, currentLevel + 1);
            child = P[child].ps_nb;
        }
    }

    freeQueue(&Q);
    freeQueue(&LevelQ);
    return maxDepth;
}

int NbTree_Height(Isi_Tree P) {
    return NbTree_Depth(P);
}

bool NbTree_IsLeaf(Isi_Tree P, int nodeIndex) {
    if (nodeIndex < 1 || nodeIndex > jml_maks || P[nodeIndex].info == ' ') {
        return false;
    }
    return (P[nodeIndex].ps_fs == nil);
}