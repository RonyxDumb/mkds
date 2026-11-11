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
void DrawDonketu(void *mapObjectList, MissionRunMapObject *donketu);
void InitKingIceDonketu(MapObjectList *list);
void InitBossDonketu(MapObjectList *list);
void InitDonketuSoundSource(MissionRunMapObject *donketu);
void UpdateDonketu(u32 mapObjectList, MissionRunMapObject *donketu);
void InitDonketuObjects(MapObjectList *list);
void StartDonketuChainStartupFirst(MissionRunMapObject *donketu);
void StartDonketuChainStartupSecond(MissionRunMapObject *donketu);
void StartDonketuStartupFirst(MissionRunMapObject *donketu);
void StartDonketuStartupSecond(MissionRunMapObject *donketu);
void StartDonketuWaitForRaceStart(MissionRunMapObject *donketu);
s32 UpdateDonketuKingIceEffects(MissionRunMapObject *donketu);
int UpdateDonketuStartupEffects(MissionRunMapObject *donketu);
int UpdateDonketuWaitForRaceStart(MissionRunMapObject *donketu);
void DonketuStandingsEndCallback(void);
void StartDonketuKartEliminatedState(MissionRunMapObject *donketu);
void StartDonketuWaterFallState(MissionRunMapObject *donketu);
void StartDonketuWalkState(MissionRunMapObject *donketu);
void StartDonketuWalkToCourseMapRow(MissionRunMapObject *donketu);
void StartDonketuChaseKartState(MissionRunMapObject *donketu);
void StartDonketuChaseRunAtStart(MissionRunMapObject *donketu);
void StartDonketuChaseWaitState(MissionRunMapObject *donketu);
void StartDonketuChaseRunState(MissionRunMapObject *donketu);
void StartDonketuChaseStopState(MissionRunMapObject *donketu);
s32 UpdateDonketuChaseStop(MissionRunMapObject *donketu);
void StartDonketuJumpWaitState(MissionRunMapObject *donketu);
void StartDonketuJumpState(MissionRunMapObject *donketu);
u32 UpdateDonketuJumpSound(MissionRunMapObject *donketu);
void StartDonketuJumpLandState(MissionRunMapObject *donketu);
void StartDonketuKartNotEliminatedState(MissionRunMapObject *donketu);
void StartDonketuWaterSinkState(MissionRunMapObject *donketu);
void StartDonketuWaterWalkState(MissionRunMapObject *donketu);
void StartDonketuWaterJumpState(MissionRunMapObject *donketu);
