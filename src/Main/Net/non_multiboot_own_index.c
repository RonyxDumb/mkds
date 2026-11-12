#include "Main/Net/non_multiboot_own_index.h"
#include "Main/MapObjects/data_0217a000.h"

void NonMultiBootResetOwnIndex(void) {
    gConnectionWork->mOwnIndex = 0xffff;
}
