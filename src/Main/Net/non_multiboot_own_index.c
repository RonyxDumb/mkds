#include "Main/Net/non_multiboot_own_index.h"
#include "Main/Unknown/unk_0217a000.h"

void NonMultiBootResetOwnIndex(void) {
    gConnectionWork->mOwnIndex = 0xffff;
}
