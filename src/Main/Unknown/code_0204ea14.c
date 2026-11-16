#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02008570.h"

#pragma thumb on

u32 mbp_204EA3C(void) {
    u32 size;
    int v2;
    u32 result;
    result = 0;
    size = MB_GetSegmentLength(NULL);
    if ((0x00010000u) <= size) {
        v2 = MB_ReadSegment(NULL, gStruct217AA00->mUnk_1658, gStruct217AA00->mUnk_168c);
        if ((v2 != 0) && (v2 = MB_RegisterFile(sMBGameRegistry, gStruct217AA00->mUnk_1658), v2 != 0)) {
            result = 1;
        }
    }
    return result;
}

void mbp_loadBannerText(Bmg *bmg) {
    void **table;
    void *firstEntry;
    void *secondEntry;
    firstEntry = jn_msg_getMessage(bmg, 0);
    secondEntry = jn_msg_getMessage(bmg, 1);
    table = sMBGameRegistry;
    sMBGameRegistry[1] = firstEntry;
    table[2] = secondEntry;
}

#pragma thumb off
