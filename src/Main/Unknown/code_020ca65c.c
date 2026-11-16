#include "Main/Unknown/code_020ca65c.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/unk_0217b000.h"

void mpicn_destroyShine16Icon(void) {
    u32 address;
    u32 unusedValue;
    address = (u32) &mpicn_sShine16Icon;
    mpicn_destroyMObjIcon((RaceHudSubScreenCells **) address);
}
