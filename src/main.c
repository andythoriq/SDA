#include <stdio.h>
#include <stdlib.h>
#include "headers/pages.h"

/* Program utama aplikasi kode morse */
int main() {
	int pilihan;
	BinaryTree morseTree = NULL;
	
	// Tampilkan layar selamat datang
	display_welcome_screen();
	
	// Inisialisasi pohon morse
	BuildMorseTree(&morseTree);
	
	do {
		display_menu();
		scanf("%d", &pilihan);
		
		switch (pilihan) {
			case 1:
				show_tree(morseTree);
				break;
			case 2:
				show_morse_dictionary(morseTree);
				break;
			case 3:
				translate_text_to_morse(morseTree);
				break;
			case 4:
				translate_morse_to_text(morseTree);
				break;
			case 5:
				translate_file_to_morse(morseTree);
				break;
			case 6:
				translate_morse_file_to_text(morseTree);
				break;
			case 0:
				clear_screen();
				printf("\n*************************Terima Kasih************************\n\n");
				printf("   _____ _                     _                _     _     _ \n");
				printf("  |_   _| |__   __ _ _ __   | | __ __   _____  _ __| |   | |\n");
				printf("    | | | '_ \\ / _` | '_ \\  | |/ / \\ \\ / / _ \\| '__| |   | |\n");
				printf("    | | | | | | (_| | | | | |   <   \\ V / (_) | |  |_|   |_|\n");
				printf("    |_| |_| |_|\\__,_|_| |_| |_|\\_\\   \\_/ \\___/|_|  (_)   (_)\n");
				printf("\n");
				printf("  Terima kasih telah menggunakan aplikasi Morse Code ini!\n\n");
				printf("*************************************************************\n");
				break;
			default:
				clear_screen();
				printf("\nPilihan tidak valid. Silakan coba lagi.\n");
				pause();
				break;
		}
	} while (pilihan != 0);
	
	return 0;
}