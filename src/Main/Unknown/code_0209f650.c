#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0209bf70.h"

u16 FX_Atan2Idx(s32 a, s32 b);

void CreateChandelier(void *mapObjectList) {
    CreateMapObjectModelNsbcaAnimation(gChandelier = CreateMapObjectModelAnimated(mapObjectList, gChandelierNsbmdName),
                                       gChandelierNsbcaName);
    SetMapObjectModelPolygonId(gChandelier, 0x3f);
}
