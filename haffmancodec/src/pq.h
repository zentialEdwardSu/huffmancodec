//
// Created by 28405 on 2023/11/29.
//

# include "hufftree.h"

#ifndef PQ_H
#define PQ_H


typedef struct PriorityQueueNode {
    HuffmanNode *node;
    struct PriorityQueueNode *next;
} PriorityQueueNode;

typedef struct PriorityQueue {
    PriorityQueueNode *front;
} PriorityQueue;

PriorityQueueNode* newPriorityQueueNode(HuffmanNode* node);
PriorityQueue* createPriorityQueue();
void enqueue(PriorityQueue* pq, HuffmanNode* node);
HuffmanNode* dequeue(PriorityQueue* pq);
#endif //PQ_H
