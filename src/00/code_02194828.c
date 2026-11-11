#include "00/code_02194828.h"

BOOL gpiCheckForBuddy(void *unused, Unk02194828 *entry, GpiProfileSearch *search) {
    if (entry->mValue != NULL && search->mKey == *entry->mValue) {
        search->mEntry = entry;
        return FALSE;
    }
    return TRUE;
}
