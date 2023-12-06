//
// Created by Edward on 2023/11/29.
//
#include "hufftree.h"
#include "sonds.h"
#include "ll.h"
#include "pq.h"
#include <stdlib.h>


HuffmanNode* newHuffmanNode(char data, float frequency) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->data = data;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * \brief free huffman tree
 * \param root root of the tree
 */
void freeHuffmanTree(HuffmanNode* root) {
    if (root == NULL) {
        return;
    }

    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}

/**
 * \brief build huffman tree with given char&freq list
 * \param data list of char to be encode
 * \param frequency list of freq of char in data
 * \param n len of list to be encode
 * \return
 */
HuffmanNode* buildHuffmanTree(char data[], float frequency[], int n) {
    PriorityQueue* pq = createPriorityQueue();

    for (int i = 0; i < n; ++i) {
        HuffmanNode* node = newHuffmanNode(data[i], frequency[i]);
        enqueue(pq, node);
    }

    // pop 2 wuth minilist freq merge them and insert to pq
    while (pq->front->next != NULL) {
        HuffmanNode* left = dequeue(pq);
        HuffmanNode* right = dequeue(pq);

        HuffmanNode* merged = newHuffmanNode('_', left->frequency + right->frequency);

        merged->left = left;
        merged->right = right;
        enqueue(pq, merged);
    }

    HuffmanNode *root = dequeue(pq);

    free(pq);
    // the last on is the root of the tree
    return root;
}

void displayHuffmanTree(HuffmanNode* root, int level) {
    if (root != NULL) {
        displayHuffmanTree(root->right, level + 1);

        for (int i = 0; i < level; ++i) {
            printf("    ");
        }

        if (root->data == '_') {
            printf("[%d]\n",level); // non-leave node represent with current level
        } else {
            printf("%c\n", root->data); // char in leave node
        }

        displayHuffmanTree(root->left, level + 1);
    }
}

// HuffmanNode* rebuildHuffmanTree(char* encodedData, char data[], int frequency[], int n) {
//     PriorityQueue* pq = createPriorityQueue();
//
//     for (int i = 0; i < n; ++i) {
//         HuffmanNode* node = newHuffmanNode(data[i], frequency[i]);
//         enqueue(pq, node);
//     }
//
//     // rebuild huffman tree
//     HuffmanNode* root = NULL;
//     for (int i = 0; i < strlen(encodedData); ++i) {
//         if (encodedData[i] == '0') {
//             root = dequeue(pq);
//             HuffmanNode* newNode = newHuffmanNode('$', root->frequency);
//             newNode->left = root;
//             enqueue(pq, newNode);
//         } else if (encodedData[i] == '1') {
//             root = dequeue(pq);
//             HuffmanNode* newNode = newHuffmanNode('$', root->frequency);
//             newNode->right = root;
//             enqueue(pq, newNode);
//         }
//     }
//
//     return root;
// }