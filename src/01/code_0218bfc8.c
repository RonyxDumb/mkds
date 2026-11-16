#include "01/code_0218bfc8.h"
#include "01/code_02185ef4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"
#include "01/code_0218c0a4.h"
#include "01/code_0218c584.h"
#include "01/code_0219b1c4.h"

void func_ov001_0218bfc8(Unk02188950 *mapObject) {
    CourseMapGroupEntry *currentGroupEntry;
    MissionRunPrm *prm;
    func_ov001_02187218(mapObject, 2, &func_ov001_0218c584);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->field15C, mapObject->mPrm->field160);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->field164, mapObject->mPrm->field160, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->field168, mapObject->mPrm->field16C);
    prm = mapObject->mPrm;
    func_ov001_021889ec(mapObject, prm->field178, prm->field17C, prm->field170, prm->field174);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetAnglePoint(mapObject, &currentGroupEntry->mPos);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetMoveAnglePoint(mapObject, &currentGroupEntry->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->field180, &func_ov001_0218c354);
    func_ov001_0218c5fc(mapObject);
}
