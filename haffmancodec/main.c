#include <stdio.h>
#include "src/codechuff.h"
#include "src/bench.h"

int main() {
    char data[8] = {'a','h','b','c','d','e','f','g'};
    float freq[8] = {0.1,0.1,0.19,0.17,0.18,0.15,0.01,0.1};

    Str *to_encode = SONDS_new_pointer("cfgdebad");
    Codell *codebook = genHuffmanCodeBook(data,freq,8); // gen code book

    const Codell *tmp = codebook->next_code;
    while(tmp != NULL) {
        printf(" %c - %f - %s\n", tmp->data,tmp->freq,SONDS_to_char(tmp->code));
        tmp = tmp->next_code;
    }

    HuffmanNode* root = buildHuffmanTree(data, freq, 7); // build tree

    displayHuffmanTree(root,0); // display tree struct

    printf("coding efficiency: %.5f\n",coding_efficiency(codebook));
    printf("code variance: %.5f\n",code_variance(codebook));

    Str *encoded_str = encode(codebook,to_encode);

    printf("encode result of %s is %s\n",SONDS_to_char(to_encode),SONDS_to_char(encoded_str));

    SONDS_free(to_encode);
    SONDS_free(encoded_str);
    freeList(codebook);
    freeHuffmanTree(root);

    return 0;
}
