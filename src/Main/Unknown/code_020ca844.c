#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void echoi_update(void) {
    echoi_sState->field24++;
    if (echoi_sState->field24 >= 0x32) {
        echoi_sState->field24 = 0;
    }
    if (echoi_sState->field14 == 0 && echoi_sState->field18 == 0 && echoi_sState->mShown != 0 &&
        echoi_sState->field4 != 0) {
        if (echoi_handleTouch()) {
            echoi_sState->field14 = 1;
        } else if (echoi_input_isSetPadTrigById(echoi_input_getDefaultInputId(), PAD_KEY_A)) {
            echoi_sState->field14 = 1;
            echoi_sState->field10 = TRUE;
            switch (echoi_sState->mChoisesIndex) {
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
        } else if (echoi_input_isSetPadTrigById(echoi_input_getDefaultInputId(), PAD_KEY_B | PAD_KEY_START)) {
            echoi_sState->field18 = 1;
            StartEmblemChoisesSound(0x10);
        }
        if (echoi_input_isSetPadTrigById(echoi_input_getDefaultInputId(), PAD_KEY_UP)) {
            echoi_moveCursor(-1);
        } else if (echoi_input_isSetPadTrigById(echoi_input_getDefaultInputId(), PAD_KEY_DOWN)) {
            echoi_moveCursor(1);
        }
    }
    if (echoi_sState->field14 != 0) {
        echoi_sState->field14++;
        if (echoi_sState->field14 > 0xf) {
            if (echoi_sState->mShown != 0) {
                echoi_sState->mResult = echoi_sState->mChoisesIndex;
                echoi_sState->field14 = 0;
            }
            echoi_sState->field14 = 0;
            echoi_sState->field10 = FALSE;
        }
    }
    if (echoi_sState->field18 != 0) {
        echoi_sState->field18++;
        if (echoi_sState->field18 > 4) {
            if (echoi_sState->mShown != 0) {
                echoi_sState->mResult = -2;
                echoi_sState->field14 = 0;
            }
            echoi_sState->field18 = 0;
        }
    }
}
#pragma thumb off
