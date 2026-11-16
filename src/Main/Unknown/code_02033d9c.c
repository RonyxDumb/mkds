#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void bres_startSelectChoices(void) {
    void *firstText;
    void *secondText;
    firstText = jn_msg_getMessage(bres_sState->mCommonMessages, 0x5d);
    secondText = jn_msg_getMessage(bres_sState->mCommonMessages, 0x5f);
    gmenu_startSelectChoices(firstText, secondText, 0);
}

#pragma thumb off
