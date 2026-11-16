#include "00/code_021947e4.h"

u32 GpiIsProfileEmpty(GpiProfile *a) {
    if (a != NULL && a->fieldC == 0 && a->mBuddyStatus == NULL && a->field18 == NULL && a->field10 == NULL) {
        return 1;
    }
    return 0;
}
