//
// Created by 28405 on 2023/11/29.
//
#include "hufftree.h"
#ifndef CODECHUFF_H
#define CODECHUFF_H


void generateHuffmanCodes(const HuffmanNode* root, int arr[], int top, char data[], Codell *codes_head);
Codell* genHuffmanCodeBook(char data[], float frequency[], int len) ;
Str* encode(Codell *codebook,const SONDS *data);
#endif //CODECHUFF_H
