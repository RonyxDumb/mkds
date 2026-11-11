#include "00/code_02189350.h"

s32 GetNotFoundInet(ACHOLD *hold) {
    s32 result;

    if (hold->mEndSequence < 10) {
        if (hold->mEndState == 3) {
            result = -51100 - hold->mEndType;
        } else if (hold->mEndState == 4) {
            result = -51200 - hold->mEndType;
        } else {
            result = -51300 - hold->mEndType;
        }
    } else if (hold->mEndSequence < 13) {
        result = -52000 - hold->mEndType;
    } else {
        result = hold->mErrorTest;
        if (result == 0) {
            result = -50000 - hold->mEndType;
        } else if (result == -1) {
            result = -52100 - hold->mEndType;
        } else if (result == -2) {
            result = -52200 - hold->mEndType;
        } else if (result == -3) {
            result = -52300 - hold->mEndType;
        } else if (result == -4) {
            result = -53000 - hold->mEndType;
        } else if (result == -5) {
            result = -53100 - hold->mEndType;
        } else if (result == -6) {
            result = -53200 - hold->mEndType;
        }
    }
    return result;
}
