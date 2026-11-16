#include "Main/Unknown/code_020ced10.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"

#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020cedf8.h"

void mpicn_destroyPakkunFireIcon(void) {
    u32 address;
    u32 value12;
    address = (u32) &mpicn_sPakkunFireIcon;
    mpicn_destroyMObjIcon((RaceHudSubScreenCells **) address);
}

void mpicn_updatePakkunFireIcon(void) {
    s32 i;
    s32 cellCount;
    s32 v;
    Unk0217b498_00 *object;

    cellCount = 0;
    v = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sPakkunFireIcon->mObjectCount; i++) {
        object = mpicn_sPakkunFireIcon->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            if (lmap_20B5AE8(&object->mPos, &mpicn_sPakkunFireIcon->mCells[cellCount].mDrawPos, v, 1, 1) !=
                FALSE) {
                mpicn_sPakkunFireIcon->mCells[cellCount].mCell = r2d_getRaceSCell(0xa4);
                mpicn_sPakkunFireIcon->mCells[cellCount].fieldC = 2;
                cellCount++;
            }
        }
    }
    mpicn_sPakkunFireIcon->mCellCount = cellCount;
}

void mpicn_renderPakkunFireIcon(RaceHudOamBuffer *oamBuffer) {
    mpicn_renderMObjIcon(oamBuffer, mpicn_sPakkunFireIcon, 0);
}
