#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void func_020fe488(u8 *a, u8 *b, u8 *c) {
    u8 i;
    u8 n;

    *a = 0xff;
    *b = 0;
    i = 0;
    do {
        n = i + 1;
        c[i * 2] = n;
        i = n;
    } while (n < 0x20);
    c[(n - 1) * 2] = 0xff;
}

void func_020fe46c(void) {
    func_020fe488(data_0217bd60, data_0217bd64, data_0217bd80);
}

void func_020fe450(void) {
    func_020fe488(data_0217bd68, data_0217bd5c, data_0217bdc0);
}

#pragma thumb off
