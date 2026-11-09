#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateEmblemChoises(void) {
    gEmblemChoises->mCycleFrames++;
    if (gEmblemChoises->mCycleFrames >= 0x32) {
        gEmblemChoises->mCycleFrames = 0;
    }
    if (gEmblemChoises->mPickFrames == 0 && gEmblemChoises->mCloseFrames == 0 && gEmblemChoises->mShown != 0 &&
        gEmblemChoises->mDrawnShown != 0) {
        if (MoveEmblemChoisesIndexByTouch()) {
            gEmblemChoises->mPickFrames = 1;
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_A)) {
            gEmblemChoises->mPickFrames = 1;
            gEmblemChoises->mPickStartedOnSelected = TRUE;
            switch (gEmblemChoises->mChoisesIndex) {
                case 0:
                    StartEmblemChoisesSound(0x10);
                    break;
                case 1:
                    StartEmblemChoisesSound(0xb);
                    break;
                case 2:
                    StartEmblemChoisesSound(5);
                    break;
            }
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_B | PAD_KEY_START)) {
            gEmblemChoises->mCloseFrames = 1;
            StartEmblemChoisesSound(0x10);
        }
        if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_UP)) {
            MoveEmblemChoisesIndex(-1);
        } else if (EmblemChoisesGetNewBits(GetEmblemChoisesInputSlot(), PAD_KEY_DOWN)) {
            MoveEmblemChoisesIndex(1);
        }
    }
    if (gEmblemChoises->mPickFrames != 0) {
        gEmblemChoises->mPickFrames++;
        if (gEmblemChoises->mPickFrames > 0xf) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = gEmblemChoises->mChoisesIndex;
                gEmblemChoises->mPickFrames = 0;
            }
            gEmblemChoises->mPickFrames = 0;
            gEmblemChoises->mPickStartedOnSelected = FALSE;
        }
    }
    if (gEmblemChoises->mCloseFrames != 0) {
        gEmblemChoises->mCloseFrames++;
        if (gEmblemChoises->mCloseFrames > 4) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = -2;
                gEmblemChoises->mPickFrames = 0;
            }
            gEmblemChoises->mCloseFrames = 0;
        }
    }
}
#pragma thumb off
