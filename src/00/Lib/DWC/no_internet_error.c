#include "00/Lib/DWC/no_internet_error.h"
#include "00/Lib/DWC/access_point_power_mode.h"

s32 GetNotFoundInet(ACHOLD *hold) {
    s32 result;

    if (hold->mEndSequence < 10) {
        if (hold->mEndState == AUTO_CONNECT_FIND_ERROR_51100) {
            result = -51100 - hold->mEndType;
        } else if (hold->mEndState == AUTO_CONNECT_FIND_ERROR_51200) {
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
