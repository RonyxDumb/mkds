#include "00/code_021a4b84.h"

void func_ov000_021a4b84(s32 index, void *value) {
    if (index >= 0x32 && index <= 0xfe) {
        gQr2RegisteredKeyList[index] = value;
    }
}
