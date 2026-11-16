#include "Main/Unknown/code_020b3278.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_021059e0.h"

#pragma thumb on
#pragma optimize_for_size on
// In mode 5 the sequence index is always 4, whatever the selected value.
void rchoi_emitOptionActivationSound(void) {
    if (rchoi_race_getCurrentRaceMode() == 5) {
        sfx_emitRaceChoiceActivationSound(4);
    } else {
        switch (rchoi_sState->mSelectedValue) {
            case 0:
            case 8:
                sfx_emitRaceChoiceActivationSound(0);
                break;
            case 1:
            case 3:
                sfx_emitRaceChoiceActivationSound(1);
                break;
            case 2:
            case 7:
            case 10:
                sfx_emitRaceChoiceActivationSound(5);
                break;
            case 4:
            case 5:
            case 6:
                sfx_emitRaceChoiceActivationSound(2);
                break;
            case 9:
                sfx_emitRaceChoiceActivationSound(3);
                break;
        }
    }
}
#pragma thumb off
