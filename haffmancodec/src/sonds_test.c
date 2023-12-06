//
// Created by 28405 on 2023/11/29.
//

# include "sonds.h"

int main() {
    Str str1,str2;
    SONDS_init(&str1,"1");
    SONDS_init(&str2,"");

    SONDS_printf(&str1);

    SONDS_add_chars(&str1,"123");
    SONDS_printf(&str1);

    SONDS_add_char(&str2,(1+'0'));
    SONDS_add_char(&str2,(2+'0'));
    SONDS_add_char(&str2,(1+'0'));
    SONDS_add_chars(&str2,"67854");
    SONDS_printf(&str2);
    SONDS_consoleLog(&str2);
    return 0;
}