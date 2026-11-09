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
void DrawEmblemChoises(void) {
    if (gEmblemChoises->mGraphicsUploadRequested != FALSE) {
        GXS_LoadBGPltt(gEmblemChoises->mChoisesSBNclr->mData + 0xe0, 0x1c0, 0x40);
        GXS_LoadBG0Char(gEmblemChoises->mChoisesSBNcgr->mData, 0, 0x3000);
        gEmblemChoises->mGraphicsUploadRequested = FALSE;
    }
    if (gEmblemChoises->mShown != 0) {
        GXS_LoadBG0Scr(gEmblemChoises->mChoisesS3Nscr->mData, 0, 0x600);
    }
    if (gEmblemChoises->mShown != gEmblemChoises->mDrawnShown) {
        if (gEmblemChoises->mShown != 0) {
            EmblemChoisesWriteSubDispcntBits(GetSubDispcntBits() | 1);
            EmblemChoisesWriteSubBg0Offset(0, 0);
            WriteSubBlendBrightness(0x3e, 0x3f, 8, 8, -7);
        } else {
            EmblemChoisesWriteSubDispcntBits(GetSubDispcntBits() & ~1);
            if (gEmblemChoises->mHideCallback != NULL) {
                gEmblemChoises->mHideCallback();
            } else {
                EmblemChoisesWriteSubBlendAlpha(0, 0, 6, 10);
            }
        }
    }
    gEmblemChoises->mDrawnShown = gEmblemChoises->mShown;
}
#pragma thumb off
