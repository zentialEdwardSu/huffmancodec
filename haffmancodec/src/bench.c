//
// Created by 28405 on 2023/11/29.
//

#include "bench.h"
#include "ll.h"
#include <math.h>

double avg_code_length(Codell *code_book) {
    double res = 0;

    Codell *tmp = code_book->next_code;

    while(tmp!=NULL) {
        res += tmp->freq * tmp->code->length;
        tmp = tmp->next_code;
    }

    return res;
}

double source_entropy(Codell *code_book) {
    double res = 0;

    Codell *tmp = code_book->next_code;

    while(tmp!=NULL) {
        res += tmp->freq * log2f(tmp->freq);
        tmp = tmp->next_code;
    }

    return res;
}

double coding_efficiency(Codell *code_book) {
    double h = source_entropy(code_book);
    double k = avg_code_length(code_book);

    return -1*h/k;
}

double code_variance(Codell *code_book) {
    double k = avg_code_length(code_book);
    double res = 0;

    Codell *tmp = code_book->next_code;

    while(tmp!=NULL) {
        res += tmp->freq * pow(((double)tmp->code->length - k),2);
        tmp = tmp->next_code;
    }

    return res;
}