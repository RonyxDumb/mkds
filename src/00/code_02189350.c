#include "00/code_02189350.h"

s32 GetNotFoundInet(Unk02189350 *hold) {
    s32 result;

    if (hold->mUnk_16 < 10) {
        if (hold->mUnk_14 == 3) {
            result = -51100 - hold->mUnk_15;
        } else if (hold->mUnk_14 == 4) {
            result = -51200 - hold->mUnk_15;
        } else {
            result = -51300 - hold->mUnk_15;
        }
    } else if (hold->mUnk_16 < 13) {
        result = -52000 - hold->mUnk_15;
    } else {
        result = hold->mErrorTest;
        if (result == 0) {
            result = -50000 - hold->mUnk_15;
        } else if (result == -1) {
            result = -52100 - hold->mUnk_15;
        } else if (result == -2) {
            result = -52200 - hold->mUnk_15;
        } else if (result == -3) {
            result = -52300 - hold->mUnk_15;
        } else if (result == -4) {
            result = -53000 - hold->mUnk_15;
        } else if (result == -5) {
            result = -53100 - hold->mUnk_15;
        } else if (result == -6) {
            result = -53200 - hold->mUnk_15;
        }
    }
    return result;
}
