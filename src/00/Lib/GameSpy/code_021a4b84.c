#include "00/Lib/GameSpy/code_021a4b84.h"

void qr2_register_keyA(s32 keyid, void *key) {
    if (keyid >= 0x32 && keyid <= 0xfe) {
        gQr2RegisteredKeyList[keyid] = key;
    }
}
