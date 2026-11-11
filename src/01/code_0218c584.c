#include "01/code_0218c584.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02110000.h"

s32 UpdateKurikingKartInRangeState(Unk02188950 *mapObject) {
    SetAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}

s32 UpdateKurikingWalkState(Unk02188950 *mapObject) {
    SetAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}

s32 UpdateKurikingTurnToEntryState(Unk02188950 *mapObject) {
    SetMoveAnglePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    SetPointInRangePoint(mapObject, &GetCurrentGroupEntry(mapObject)->mPos);
    return 0;
}
