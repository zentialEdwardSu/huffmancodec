//
// Created by 28405 on 2023/11/29.
//
#include "ll.h"
int main() {
    struct Codell *list = initializeList();

    // 在末尾插入元素
    list = insertAtEnd(list,'$',0,SONDS_new_pointer(""));
    insertAtEnd(list,'b',0.12,SONDS_new_pointer("101"));
    insertAtEnd(list,'a',0.12,SONDS_new_pointer("011"));

    // 获取链表长度并输出
    int length = len(list);
    printf("Length of the list: %d\n", length);
    return 0;
}
