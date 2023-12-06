//
// Created by 28405 on 2023/11/29.
//

#include "pq.h"

/**
 * \brief  create a new pq node with given huffman node
 * \param node huffman node
 * \return the created pqnode
 */
PriorityQueueNode* newPriorityQueueNode(HuffmanNode* node) {
    PriorityQueueNode* pqNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    pqNode->node = node;
    pqNode->next = NULL;
    return pqNode;
}

/**
 * \brief create a new priority queue
 * \return pq
 */
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->front = NULL;
    return pq;
}

/**
 * \brief 
 * \param pq exist priority queue
 * \param node huffman node to be inserted
 */
void enqueue(PriorityQueue* pq, HuffmanNode* node) {
    PriorityQueueNode* pqNode = newPriorityQueueNode(node);

    // null or miner freq -> head
    if (pq->front == NULL || node->frequency < pq->front->node->frequency) {
        pqNode->next = pq->front;
        pq->front = pqNode;
    } else {
        PriorityQueueNode* current = pq->front;
        while (current->next != NULL && current->next->node->frequency < node->frequency) {
            current = current->next;
        }
        pqNode->next = current->next;
        current->next = pqNode;
    }
}

/**
 * \brief 
 * \param pq exisist priority queue
 * \return the popedd huffman node
 */
HuffmanNode* dequeue(PriorityQueue* pq) {
    if (pq->front == NULL) {
        return NULL;
    }

    PriorityQueueNode* temp = pq->front;
    HuffmanNode* node = temp->node;
    pq->front = pq->front->next;
    free(temp);
    return node;
}