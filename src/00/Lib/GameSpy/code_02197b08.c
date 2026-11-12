#include "00/Lib/GameSpy/code_02197b08.h"

BOOL gti2CheckResponse(const u8 *left, const u8 *right) {
    s32 i;
    for (i = 0; i < 0x20; i++) {
        if (i != 0 && i != 0xd && left[i] != right[i]) {
            return FALSE;
        }
    }
    return TRUE;
}
