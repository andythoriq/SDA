#ifndef MORSE_H
#define MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tree.h"

typedef TreeNode* BinaryTree;

TreeNode* newNode(char info);

void buildMorseTree(BinaryTree *root);

void displayMorseDictionary(BinaryTree root);

void displayMorseDictionaryTableFormat(BinaryTree root);

void displayTree(BinaryTree root, int level, char side);

void getMorseByChar(BinaryTree root, char ch, char *result);

char getCharByMorse(BinaryTree root, const char *morse);

void textToMorse(BinaryTree root, const char *text, char *result);

void morseToText(BinaryTree root, const char *morse, char *result);

void fileToMorse(BinaryTree root, const char *filename);

void morseFileToText(BinaryTree root, const char *filename);

void readFromFile(BinaryTree root, char *inputFile, char *outputFile, int mode);

void getCurrentMorsePath(BinaryTree root, BinaryTree current, char *path, int depth);

void getMorseByNode(BinaryTree P, char *path, char *morseOut);

void inOrderPrint(BinaryTree P, char *currentPath);

void printAsciiTree(BinaryTree root);

void fillScreen(BinaryTree root, char **screen, int level, int left, int right);

#endif
