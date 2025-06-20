#include "../headers/morse.h"

void buildMorseTree(BinaryTree *root) {
    *root = newNode('-');

    (*root)->left = newNode('A');
    (*root)->right = newNode('T');

    (*root)->left->left = newNode('E');
    (*root)->left->right = newNode('N');
    (*root)->right->left = newNode('M');
    (*root)->right->right = newNode('K');

    
    (*root)->left->left->left = newNode('I');
    (*root)->left->left->right = newNode('U');
    (*root)->left->right->left = newNode('R');
    (*root)->left->right->right = newNode('W');
    
    (*root)->right->left->left = newNode('D');
    (*root)->right->left->right = newNode('C');
    (*root)->right->right->left = newNode('Y');
    (*root)->right->right->right = newNode('G');

    
    (*root)->left->left->left->left = newNode('L');
    (*root)->left->left->left->right = newNode('F');
    (*root)->left->left->right->left = newNode('P');
    (*root)->left->left->right->right = newNode('B');
    
    (*root)->right->left->left->left = newNode('J');
    (*root)->right->left->left->right = newNode('X');
    (*root)->right->left->right->left = newNode('H');
    (*root)->right->left->right->right = newNode('Z');
    
    (*root)->right->right->left->left = newNode('Q');
    (*root)->right->right->left->right = newNode('V');
    (*root)->right->right->right->left = newNode('O');
    (*root)->right->right->right->right = newNode('S');

    
    (*root)->left->left->left->left->left = newNode('1');
    (*root)->left->left->left->left->right = newNode('2');
    (*root)->left->left->left->right->left = newNode('3');
    (*root)->left->left->left->right->right = newNode('4');
    
    (*root)->left->left->right->left->left = newNode('5');
    (*root)->left->left->right->left->right = newNode('6');
    (*root)->left->left->right->right->left = newNode('7');
    (*root)->left->right->left->left = newNode('8');
    
    (*root)->left->right->left->right = newNode('9');
    (*root)->left->right->right->left = newNode('0');
    
    
    (*root)->left->left->right->right->right = newNode('_');
}

void printAsciiTree(BinaryTree root) {
    if (root == NULL) return;
    
    char levelNodes[5][32]; // 5 levels, maksimum 32 nodes di level 5
    
    // Inisialisasi semua dengan '-'
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 32; j++) {
            levelNodes[i][j] = '-';
        }
    }
    
    // Level 0 - Root
    levelNodes[0][0] = root->data;
    
    // Level 1 - A and B
    if (root->left) levelNodes[1][0] = root->left->data;
    if (root->right) levelNodes[1][1] = root->right->data;
    
    // Level 2 - C D E F
    if (root->left) {
        if (root->left->left) levelNodes[2][0] = root->left->left->data;
        if (root->left->right) levelNodes[2][1] = root->left->right->data;
    }
    
    if (root->right) {
        if (root->right->left) levelNodes[2][2] = root->right->left->data;
        if (root->right->right) levelNodes[2][3] = root->right->right->data;
    }
    
    // Level 3 - G H I J K L M N
    BinaryTree nodes[8] = {NULL}; // Array untuk menyimpan pointer ke node level 2
    int index = 0;
    
    // Mengisi array nodes dengan pointer ke node level 2
    if (root->left && root->left->left) nodes[index++] = root->left->left;
    else index++;
    
    if (root->left && root->left->right) nodes[index++] = root->left->right;
    else index++;
    
    if (root->right && root->right->left) nodes[index++] = root->right->left;
    else index++;
    
    if (root->right && root->right->right) nodes[index++] = root->right->right;
    else index++;
    
    // Mengisi level 3 berdasarkan nodes level 2
    for (int i = 0; i < 4; i++) {
        if (nodes[i]) {
            if (nodes[i]->left) levelNodes[3][i*2] = nodes[i]->left->data;
            if (nodes[i]->right) levelNodes[3][i*2+1] = nodes[i]->right->data;
        }
    }
    
    // Level 4 - 16 nodes
    nodes[0] = NULL; // Reset
    index = 0;
    
    // Mengisi array nodes dengan pointer ke node level 3
    for (int i = 0; i < 4; i++) {
        BinaryTree parent = NULL;
        
        switch (i) {
            case 0: // anak I: (S, U)
                if (root->left && root->left->left) parent = root->left->left;
                break;
            case 1: // anak A: (R, W)
                if (root->left && root->left->right) parent = root->left->right;
                break;
            case 2: // anak N: (D, K)
                if (root->right && root->right->left) parent = root->right->left;
                break;
            case 3: // anak M: (G, O)
                if (root->right && root->right->right) parent = root->right->right;
                break;
        }
        
        if (parent) {
            nodes[index++] = parent->left;
            nodes[index++] = parent->right;
        } else {
            index += 2; // Skip jika parrent NULL
        }
    }
    
    // Mengisi level 4 berdasarkan nodes level 3
    for (int i = 0; i < 8; i++) {
        if (nodes[i]) {
            if (nodes[i]->left) levelNodes[4][i*2] = nodes[i]->left->data;
            if (nodes[i]->right) levelNodes[4][i*2+1] = nodes[i]->right->data;
        }
    }
    
    // print
    printf("\n");
    printf("                %c                \n", levelNodes[0][0]);
    printf("               / \\               \n");
    printf("              /   \\              \n");
    printf("             %c     %c             \n", levelNodes[1][0], levelNodes[1][1]);
    printf("            / \\   / \\            \n");
    printf("           %c   %c %c   %c           \n", levelNodes[2][0], levelNodes[2][1], levelNodes[2][2], levelNodes[2][3]);
    printf("          / \\ / \\ / \\ / \\          \n");
    printf("         %c  %c %c  %c %c  %c %c  %c         \n", 
           levelNodes[3][0], levelNodes[3][1], levelNodes[3][2], levelNodes[3][3], 
           levelNodes[3][4], levelNodes[3][5], levelNodes[3][6], levelNodes[3][7]);
    printf("        /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\        \n");
    printf("       %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c       \n",
           levelNodes[4][0], levelNodes[4][1], levelNodes[4][2], levelNodes[4][3],
           levelNodes[4][4], levelNodes[4][5], levelNodes[4][6], levelNodes[4][7],
           levelNodes[4][8], levelNodes[4][9], levelNodes[4][10], levelNodes[4][11],
           levelNodes[4][12], levelNodes[4][13], levelNodes[4][14], levelNodes[4][15]);
    
    printf("\n");
}

void fillScreen(BinaryTree root, char **screen, int level, int left, int right) {
    if (root == NULL) return;
    
    int mid = (left + right) / 2;
    
    screen[level][mid] = root->data;
    
    // kiri
    if (root->left != NULL) {
        // Menggambar garis ke anak kiri
        for (int i = mid - 1; i > (left + mid) / 2; i--) {
            screen[level + 1][i] = '_';
        }
        screen[level + 1][(left + mid) / 2] = '/';
        
        // Mengisi subtree kiri
        fillScreen(root->left, screen, level + 2, left, mid - 1);
    }

    // kanan
    if (root->right != NULL) {
        // Menggambar garis ke anak kanan
        for (int i = mid + 1; i < (mid + right) / 2; i++) {
            screen[level + 1][i] = '_';
        }
        screen[level + 1][(mid + right) / 2] = '\\';
        
        // Mengisi subtree kanan
        fillScreen(root->right, screen, level + 2, mid + 1, right);
    }
}

void displayMorseDictionary(BinaryTree root) {
    printf("\nKarakter | Kode Morse\n");
    printf("---------------------\n");
    
    char currentPath[20] = "";
    inOrderPrint(root, currentPath);
    printf("\n");
}

void getMorseByChar(BinaryTree root, char ch, char *result) {
    ch = toupper(ch);
    result[0] = '\0';
    
    if (ch == ' ') {
        strcpy(result, "/");
        return;
    }
    
    TreeNode* charNode = getNodeByChar(root, ch);
    if (charNode == NULL) {
        return;
    }
    
    getCurrentMorsePath(root, charNode, result, 0);
}

char getCharByMorse(BinaryTree root, const char *morse) {
    TreeNode* current = root;
    
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            if (current->left != NULL) {
                current = current->left;
            } else {
                return '?';
            }
        } else if (morse[i] == '-') {
            if (current->right != NULL) {
                current = current->right;
            } else {
                return '?';
            }
        } else if (morse[i] == '/') {
            return ' ';
        }
    }
    
    if (current->data != '\0') {
        return current->data;
    }
    return '?';
}

void textToMorse(BinaryTree root, const char *text, char *result) {
    result[0] = '\0';
    char morse[10];
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            strcat(result, "/ ");
        } else {
            getMorseByChar(root, text[i], morse);
            strcat(result, morse);
            strcat(result, " ");
        }
    }
}

void morseToText(BinaryTree root, const char *morse, char *result) {
    result[0] = '\0'; 
    char code[10]; 
    int codeIndex = 0;
    
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == ' ') {
            if (codeIndex > 0) {
                code[codeIndex] = '\0'; 
                
                if (strcmp(code, "/") == 0) {
                    strcat(result, " ");
                } else {
                    char ch = GetCharFromMorse(root, code);
                    char charStr[2] = {ch, '\0'};
                    strcat(result, charStr);
                }
                
                codeIndex = 0; 
            }
        } else {
            code[codeIndex++] = morse[i];
        }
    }
    
    if (codeIndex > 0) {
        code[codeIndex] = '\0';
      
        if (strcmp(code, "/") == 0) {
            strcat(result, " ");
        } else {
            char ch = GetCharFromMorse(root, code);
            char charStr[2] = {ch, '\0'};
            strcat(result, charStr);
        }
    }
}

void fileToMorse(BinaryTree root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error membuka file: %s\n", filename);
        return;
    }
    
    printf("\n======================File ke Morse=====================n\n");
    printf("Teks asli:\n");
    
    char line[1000];
    char morseResult[5000];
    
    while (fgets(line, sizeof(line), file)) {
 
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        printf("%s\n", line);
        
 
        TextToMorse(root, line, morseResult);
        
        printf("Kode Morse:\n%s\n\n", morseResult);
    }
    
    fclose(file);
    printf("\n========================================================\n");
}

void morseFileToText(BinaryTree root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error membuka file: %s\n", filename);
        return;
    }
    
    printf("\n============================Morse ke Teks========================n\n");
    printf("Kode Morse asli:\n");
    
    char line[5000];
    char textResult[1000];
    
    while (fgets(line, sizeof(line), file)) {
        
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        printf("%s\n", line);
        
        MorseToText(root, line, textResult);
        
        printf("Teks hasil dekode:\n%s\n\n", textResult);
    }
    
    fclose(file);
    printf("\n=================================================================\n");
}

void readFromFile(BinaryTree root, char *inputFile, char *outputFile, int mode) {
    FILE *fin, *fout;
    char line[1000], result[5000];
    
    fin = fopen(inputFile, "r");
    if (fin == NULL) {
        return;
    }
    
    fout = fopen(outputFile, "w");
    if (fout == NULL) {
        fclose(fin);
        return;
    }
    
    while (fgets(line, sizeof(line), fin)) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        
        if (mode == 1) {
            TextToMorse(root, line, result);
        } else {
            MorseToText(root, line, result);
        }
        
        fprintf(fout, "%s\n", result);
    }
    
    fclose(fin);
    fclose(fout);
    printf("berhasil konversi! Hasil disimpan di %s\n", outputFile);
}

void getCurrentMorsePath(BinaryTree root, BinaryTree current, char *path, int depth) {
    if (root == current) {
        path[0] = '\0';
        return;
    }
    
    BinaryTree queue[1000];
    char directions[1000][20];
    int front = 0, rear = 0;
    
    queue[rear] = root;
    directions[rear][0] = '\0';
    rear++;
    
    while (front < rear) {
        BinaryTree node = queue[front];
        char *currentPath = directions[front];
        front++;
        
        if (node == current) {
            strcpy(path, currentPath);
            return;
        }
        
        if (node->left) {
            queue[rear] = node->left;
            strcpy(directions[rear], currentPath);
            strcat(directions[rear], ".");
            rear++;
        }
        
        if (node->right) {
            queue[rear] = node->right;
            strcpy(directions[rear], currentPath);
            strcat(directions[rear], "-");
            rear++;
        }
    }
    
    path[0] = '\0';
}

void getMorseByNode(BinaryTree P, char *path, char *morseOut) {
    strcpy(morseOut, path);
}

void inOrderPrint(BinaryTree P, char *currentPath) {
    if (!IsEmpty(P)) {
        // Kiri
        int len = strlen(currentPath);
        if (P->left != NULL) {
            currentPath[len] = '.';
            currentPath[len+1] = '\0';
            InOrderPrint(P->left, currentPath);
            currentPath[len] = '\0';
        }
        
        // Root
        if (P->data != '\0' && P->data != '-') {
            printf("| %-10c | %-10s |\n", P->data, currentPath);
        }
        
        // Kanan
        if (P->right != NULL) {
            currentPath[len] = '-';
            currentPath[len+1] = '\0';
            InOrderPrint(P->right, currentPath);
            currentPath[len] = '\0';
        }
    }
}

