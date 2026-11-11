#pragma once

#include "types.h"

#include "01/code_02181bd0.h"
#include "01/code_02185ef4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
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
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02146000.h"
#include "01/callees_0219b000.h"
#include "01/code_02185000.h"
#include "01/code_02186000.h"
#include "01/code_0218155c.h"
#include "01/code_021843b0.h"
#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188484.h"
#include "01/code_02188da4.h"
#include "01/code_0218f9d4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02183000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_021882b8.h"
#include "01/code_02187bfc.h"
#include "01/code_02188260.h"
#include "01/code_02184e18.h"
#include "01/code_02187e78.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02184000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_021842b4.h"
#include "01/code_021842ec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void *CreateDonketuUpdateList(void);
void *CreateKingIceDonketuDrawList(void);
void *CreateBossDonketuDrawList(void);
void CreateDonketuKindData(void);
void DrawDonketu(void *mapObjectList, Unk02188950 *donketu);
void InitKingIceDonketu(MapObjectList *list);
void InitBossDonketu(MapObjectList *list);
void InitDonketuSoundSource(Unk02188950 *donketu);
void UpdateDonketu(u32 mapObjectList, Unk02188950 *donketu);
void InitDonketuObjects(MapObjectList *list);
void StartDonketuChainStartupFirst(Unk02188950 *donketu);
void StartDonketuChainStartupSecond(Unk02188950 *donketu);
void StartDonketuStartupFirst(Unk02188950 *donketu);
void StartDonketuStartupSecond(Unk02188950 *donketu);
void StartDonketuWaitForRaceStart(Unk02188950 *donketu);
s32 UpdateDonketuKingIceEffects(Unk02188950 *donketu);
int UpdateDonketuStartupEffects(Unk02188950 *donketu);
int UpdateDonketuWaitForRaceStart(Unk02188950 *donketu);
void DonketuStandingsEndCallback(void);
void StartDonketuKartEliminatedState(Unk02188950 *donketu);
void StartDonketuWaterFallState(Unk02188950 *donketu);
void StartDonketuWalkState(Unk02188950 *donketu);
void StartDonketuWalkToCourseMapRow(Unk02188950 *donketu);
void StartDonketuChaseKartState(Unk02188950 *donketu);
void StartDonketuChaseRunAtStart(Unk02188950 *donketu);
void StartDonketuChaseWaitState(Unk02188950 *donketu);
void StartDonketuChaseRunState(Unk02188950 *donketu);
void StartDonketuChaseStopState(Unk02188950 *donketu);
s32 UpdateDonketuChaseStop(Unk02188950 *donketu);
void StartDonketuJumpWaitState(Unk02188950 *donketu);
void StartDonketuJumpState(Unk02188950 *donketu);
u32 UpdateDonketuJumpSound(Unk02188950 *donketu);
void StartDonketuJumpLandState(Unk02188950 *donketu);
void StartDonketuKartNotEliminatedState(Unk02188950 *donketu);
void StartDonketuWaterSinkState(Unk02188950 *donketu);
void StartDonketuWaterWalkState(Unk02188950 *donketu);
void StartDonketuWaterJumpState(Unk02188950 *donketu);
