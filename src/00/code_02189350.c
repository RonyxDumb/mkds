#include "00/code_02189350.h"

s32 func_ov000_02189350(Unk02189350 *v1) {
    s32 v;

    if (v1->mUnk_16 < 10) {
        if (v1->mUnk_14 == 3) {
            v = -51100 - v1->mUnk_15;
        } else if (v1->mUnk_14 == 4) {
            v = -51200 - v1->mUnk_15;
        } else {
            v = -51300 - v1->mUnk_15;
        }
    } else if (v1->mUnk_16 < 13) {
        v = -52000 - v1->mUnk_15;
    } else {
        v = v1->mUnk_10;
        if (v == 0) {
            v = -50000 - v1->mUnk_15;
        } else if (v == -1) {
            v = -52100 - v1->mUnk_15;
        } else if (v == -2) {
            v = -52200 - v1->mUnk_15;
        } else if (v == -3) {
            v = -52300 - v1->mUnk_15;
        } else if (v == -4) {
            v = -53000 - v1->mUnk_15;
        } else if (v == -5) {
            v = -53100 - v1->mUnk_15;
        } else if (v == -6) {
            v = -53200 - v1->mUnk_15;
        }
    }
    return v;
}
