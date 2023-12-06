//
// Created by 28405 on 2023/11/29.
//
#include "hufftree.h"
#include "sonds.h"
#include "codechuff.h"
#include "ll.h"

/**
 * \brief
 * \param root root of huffman tree
 * \param arr trace route
 * \param top
 * \param data
 * \param codes_head
 */
void generateHuffmanCodes(const HuffmanNode* root, int arr[], const int top, char data[], Codell *codes_head) {
    if (root->left != NULL) {
        arr[top] = 0;
        generateHuffmanCodes(root->left, arr, top + 1, data, codes_head);
    }

    if (root->right != NULL) {
        arr[top] = 1;
        generateHuffmanCodes(root->right, arr, top + 1, data, codes_head);
    }

    // we reach the leave nodes
    if (root->left == NULL && root->right == NULL) {
        // build huffmancode
        SONDS *huffmancode = SONDS_new_pointer("");
        for (int i=0;i<top;i++) {
            SONDS_add_char(huffmancode,(arr[i] + '0'));
        }
        insertAtEnd(codes_head,root->data,root->frequency,huffmancode);
    }
}

Codell* genHuffmanCodeBook(char data[], float frequency[], int len) {
    HuffmanNode* root = buildHuffmanTree(data, frequency, len);

    int arr[1024], top = 0;
    Codell *codes = initializeList();
    codes = insertAtEnd(codes,'$',0,SONDS_new_pointer(""));

    generateHuffmanCodes(root, arr, top, data, codes);

    freeHuffmanTree(root);

    return codes;
}

/**
 * \brief
 * \param codebook code book
 * \param data data to be encoded
 * \return
 */
Str* encode(Codell *codebook,const SONDS *data) {
    Str *encoded_str = SONDS_new_pointer("");
    Cache *cc = initCache(codebook);

    for(int i=0; i<data->length; i++) {
        Str *code = findViaCache(codebook,cc,data->data[i])->code;

        SONDS_add(encoded_str,code);
    }

    free(cc);
    return encoded_str;
}

// char* decode(char *data) {
//
// }
