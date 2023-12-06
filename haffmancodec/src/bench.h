//
// Created by 28405 on 2023/11/29.
//
#include "ll.h"
#ifndef BENCH_H
#define BENCH_H
double avg_code_length(Codell *code_book);
double source_entropy(Codell *code_book);
double coding_efficiency(Codell *code_book);
double code_variance(Codell *code_book);
#endif //BENCH_H
