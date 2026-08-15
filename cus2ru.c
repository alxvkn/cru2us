#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "def.h"
#include "layouts.h"

wchar_t ch_us_to_ru(char us_char) {
    for (int i = 0; i < sizeof(layout_us) / sizeof(*layout_us); i++) {
        if (layout_us[i] == us_char) return layout_ru[i];
    }
    return (wchar_t)us_char;
}

void str_us_to_ru(const char* us_str, wchar_t* ru_str, size_t n) {
    int i = 0;
    for (; i < n && us_str[i] != '\0'; i++) {
        ru_str[i] = ch_us_to_ru(us_str[i]);
    }

    ru_str[i] = L'\0';
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "");

    char input_buf[INPUT_BUF_SIZE];

    size_t read_bytes = fread(input_buf, 1, INPUT_BUF_SIZE, stdin);

    wchar_t w[WCHAR_BUF_SIZE];
    str_us_to_ru(input_buf, w, WCHAR_BUF_SIZE);

    wcstombs(input_buf, w, INPUT_BUF_SIZE);

    printf("%s", input_buf);
}
