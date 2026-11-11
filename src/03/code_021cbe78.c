#include "03/code_021cbe78.h"
#include "03/code_021c209c.h"
#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021cd000.h"
#include "03/code_021ce000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021cbc00.h"

void UpdateConnectMessageFadeIn(void) {
    ConnectMessageIds messageIds = gConnectMessageIds;
    s32 secondaryPairSecond;
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        GetSecondaryMenuPair(NULL, &secondaryPairSecond);
        func_ov003_021cefc0(messageIds.mUnk_00[secondaryPairSecond], 1, 1, -1, 0);
        SetUpdateFunction(UpdateConnectMessage);
    }
}
