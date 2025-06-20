#include "../headers/pages.h"

void display_header(const char *title) {
    printf("\n====================== %s ==============================\n", title);
}

void display_footer() {
    printf("\n========================================================\n");
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    printf("\nPress Enter to continue...");
    getchar();
    while (getchar() != '\n');
}

void display_menu() {
    clear_screen();
    printf("\n");
    printf("  +---------------------------------------------------+\n");
    printf("  |               MORSE CODE CONVERTER                |\n");
    printf("  +---------------------------------------------------+\n");
    printf("  |                                                   |\n");
    printf("  |   (1) Show Morse Code Tree                        |\n");
    printf("  |   (2) Show Morse Code Dictionary                  |\n");
    printf("  |   (3) Translate Text to Morse Code                |\n");
    printf("  |   (4) Translate Morse Code to Text                |\n");
    printf("  |   (5) Translate File to Morse Code                |\n");
    printf("  |   (6) Translate Morse Code File to Text           |\n");
    printf("  |                                                   |\n");
    printf("  |   (0) Exit                                        |\n");
    printf("  |                                                   |\n");
    printf("  +---------------------------------------------------+\n");
    printf("\n");
    printf("  Choose an option: ");
}

void show_tree(BinaryTree tree) {
    clear_screen();
    display_header("Morse Code Tree");

    printf("ASCII representation of the tree (up to level 5):\n\n");
    PrintAsciiTree(tree);

    printf("\nDetailed tree with Morse code mappings:\n\n");
    DisplayTree(tree, 0, '*');

    display_footer();
    pause();
}

void show_morse_dictionary(BinaryTree tree) {
    clear_screen();
    display_header("Morse Code Dictionary");

    PrintMorseDictionary(tree);

    display_footer();
    pause();
}

void translate_text_to_morse(BinaryTree tree) {
    clear_screen();
    display_header("Text to Morse Code");

    char text[1000];
    char morse[5000] = {0};

    printf("Enter your text (max 1000 characters): ");
    getchar();
    fgets(text, sizeof(text), stdin);

    int len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    TextToMorse(tree, text, morse);

    printf("\nOriginal text: %s\n", text);
    printf("Morse code: %s\n", morse);

    display_footer();
    pause();
}

void translate_morse_to_text(BinaryTree tree) {
    clear_screen();
    display_header("Morse Code to Text");

    char morse[5000];
    char text[1000] = {0};

    printf("Enter Morse code (use spaces between letters, / for spaces): ");
    getchar();  
    fgets(morse, sizeof(morse), stdin);

    int len = strlen(morse);
    if (len > 0 && morse[len - 1] == '\n') {
        morse[len - 1] = '\0';
    }

    MorseToText(tree, morse, text);

    printf("\nMorse code: %s\n", morse);
    printf("Translated text: %s\n", text);

    display_footer();
    pause();
}

void translate_file_to_morse(BinaryTree tree) {
    clear_screen();
    display_header("Text File to Morse Code");

    char inputFile[100], outputFile[100];

    printf("Enter input file name (e.g. input.txt): ");
    scanf("%s", inputFile);

    printf("Enter output file name (e.g. output.txt): ");
    scanf("%s", outputFile);

    ReadFromFile(tree, inputFile, outputFile, 1);

    display_footer();
    pause();
}

void translate_morse_file_to_text(BinaryTree tree) {
    clear_screen();
    display_header("Morse Code File to Text");

    char inputFile[100], outputFile[100];

    printf("Enter input file name (Morse code, e.g. morse.txt): ");
    scanf("%s", inputFile);

    printf("Enter output file name (e.g. text.txt): ");
    scanf("%s", outputFile);

    ReadFromFile(tree, inputFile, outputFile, 2);

    display_footer();
    pause();
}
