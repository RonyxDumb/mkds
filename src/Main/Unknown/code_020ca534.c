#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020c06c4.h"
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
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"

void mpicn_updateShine16Icon(void) {
    s32 i;
    s32 n;
    u32 v;

    n = 0;
    v = mpicn_20C0DB0();
    for (i = 0; i < mpicn_sShine16Icon->mObjectCount; i++) {
        Unk0217b498_00 *p;

        p = mpicn_sShine16Icon->mObjects[i];
        if (!(p->mFlags & 1)) {
            if (lmap_20B5AE8(&p->mPos, &mpicn_sShine16Icon->mCells[n].mDrawPos, v, 1,
                                                1)) {
                mpicn_sShine16Icon->mCells[n].mCell = r2d_getRaceSCell(0xb6);
                mpicn_sShine16Icon->mCells[n].fieldC = (p->mFlags & 0x20) ? 2 : 1;
                mpicn_sShine16Icon->mCells[n].fieldE = p->mFlags & 0x20;
                n++;
            }
        }
    }
    mpicn_sShine16Icon->mCellCount = n;
}

void mpicn_renderShine16Icon(RaceHudOamBuffer *a) {
    mpicn_renderMObjIcon(a, mpicn_sShine16Icon, 0);
}

s32 mpicn_createCrabIcon(void) {
    return mpicn_createMapObjIcon(&mpicn_sCrabIcon, MAP_OBJECT_KIND_CRAB);
}
