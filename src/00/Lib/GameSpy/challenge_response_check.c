#include "00/Lib/GameSpy/challenge_response_check.h"

BOOL gti2CheckResponse(const u8 *left, const u8 *right) {
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < 0x20; byteIndex++) {
        if (byteIndex != 0 && byteIndex != 0xd && left[byteIndex] != right[byteIndex]) {
            return FALSE;
        }
    }
    return TRUE;
}
