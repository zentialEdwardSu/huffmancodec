//
// Created by Edward on 2023/11/29.
//
#include "ll.h"

#ifndef HAFFTREE_H
#define HAFFTREE_H

typedef struct HuffmanNode {
    char data;
    float frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

HuffmanNode* newHuffmanNode(char data, float frequency);
void freeHuffmanTree(HuffmanNode* root);
HuffmanNode* buildHuffmanTree(char data[], float frequency[], int n);
void displayHuffmanTree(HuffmanNode* root, int level);
#endif //HAFFTREE_H
