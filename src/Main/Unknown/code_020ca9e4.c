#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caae8.h"
#include "Main/Unknown/code_020caaac.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214b824.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void echoi_vblank(void) {
    if (echoi_sState->mGraphicsUploadRequested != FALSE) {
        GXS_LoadBGPltt(echoi_sState->mChoisesSBNclr->mData + 0xe0, 0x1c0, 0x40);
        GXS_LoadBG0Char(echoi_sState->mChoisesSBNcgr->mData, 0, 0x3000);
        echoi_sState->mGraphicsUploadRequested = FALSE;
    }
    if (echoi_sState->mShown != 0) {
        GXS_LoadBG0Scr(echoi_sState->mChoisesS3Nscr->mData, 0, 0x600);
    }
    if (echoi_sState->mShown != echoi_sState->field4) {
        if (echoi_sState->mShown != 0) {
            echoi_GXS_SetVisiblePlane(echoi_GXS_GetVisiblePlane() | 1);
            echoi_G2S_SetBG0Offset(0, 0);
            echoi_G2S_SetBlendBrightnessExt(0x3e, 0x3f, 8, 8, -7);
        } else {
            echoi_GXS_SetVisiblePlane(echoi_GXS_GetVisiblePlane() & ~1);
            if (echoi_sState->fieldC != NULL) {
                echoi_sState->fieldC();
            } else {
                echoi_G2S_SetBlendAlpha(0, 0, 6, 10);
            }
        }
    }
    echoi_sState->field4 = echoi_sState->mShown;
}
#pragma thumb off
