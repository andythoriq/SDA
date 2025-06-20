#ifndef PAGES_H
#define PAGES_H

#include "morse.h"

void clear_screen();


void pause();


void display_menu();


void show_tree(BinaryTree tree);


void show_morse_dictionary(BinaryTree tree);


void translate_text_to_morse(BinaryTree tree);


void translate_morse_to_text(BinaryTree tree);


void translate_file_to_morse(BinaryTree tree);


void translate_morse_file_to_text(BinaryTree tree);


#endif
