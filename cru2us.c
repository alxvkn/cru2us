#include <locale.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "def.h"
#include "layouts.h"

char ch_ru_to_us(wchar_t ru_char) {
    for (int i = 0; i < sizeof(layout_ru) / sizeof(*layout_ru); i++) {
        if (layout_ru[i] == ru_char) return layout_us[i];
    }
    return (char)ru_char;
}

void str_ru_to_us(const wchar_t* ru_str, char* us_str, size_t n) {
    int i = 0;
    for (; i < n && ru_str[i] != L'\0'; i++) {
        us_str[i] = ch_ru_to_us(ru_str[i]);
    }

    us_str[i] = '\0';
}

void print_bytes(char* bytes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%02hhx ", bytes[i]);
    }
    putchar('\n');
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    char input_buf[INPUT_BUF_SIZE];

    size_t read_bytes = fread(input_buf, 1, INPUT_BUF_SIZE, stdin);

    wchar_t w[WCHAR_BUF_SIZE];
    mbstowcs(w, input_buf, WCHAR_BUF_SIZE);

    str_ru_to_us(w, input_buf, INPUT_BUF_SIZE);

    printf("%s", input_buf);
}
