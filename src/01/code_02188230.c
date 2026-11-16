#include "01/code_02188230.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

BOOL func_ov001_02188230(Unk02188950 *mapObject) {
    s32 limit;

    mapObject->fieldAC--;
    limit = -mapObject->mPrm->field0;
    if (mapObject->fieldAC <= limit) {
        mapObject->fieldAC = limit;
        return TRUE;
    }
    return FALSE;
}
