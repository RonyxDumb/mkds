#include "Main/Unknown/code_020c7450.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/unk_0217b000.h"

void mpicn_destroyItemboxIcon(void) {
    u32 address;
    u32 value12;
    address = (u32) &mpicn_sItemboxIcon;
    mpicn_destroyMObjIcon((RaceHudSubScreenCells **) address);
}
