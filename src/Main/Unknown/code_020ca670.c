#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_021000d0.h"

#pragma thumb on
void echoi_setMenuVisible(u32 shown) {
    echoi_sState->mShown = shown;
    echoi_resetSelectedOption();
}
#pragma thumb off

s32 mpicn_createShine16Icon(void) {
    return mpicn_createMapObjIcon(&mpicn_sShine16Icon, MAP_OBJECT_KIND_SHINE16);
}
