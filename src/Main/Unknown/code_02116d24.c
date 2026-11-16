#include "Main/Unknown/code_02116d24.h"

#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

const u16 wait_sFrameBnclIndex[4] = {0, 1, 2, 0};

void wait_update(void) {
    u16 *q;
    Wait *p;

    sWaitData->mFrameIndexFrames++;
    if (sWaitData->mFrameIndexFrames >= 4) {
        sWaitData->mFrameIndex++;
        if (sWaitData->mFrameIndex >= 3) {
            sWaitData->mFrameIndex = 0;
        }
        sWaitData->mFrameIndexFrames = 0;
        jn_ui_fillPlaceholder(wait_sFrameBnclIndex[sWaitData->mFrameIndex], sWaitData->mNcer, sWaitData->mNcgr, sWaitData->mBncl, sWaitData->field20,
                       sWaitData->mDestinationBnclIndex, sWaitData->mDestinationNcer, sWaitData->mDestinationBncl);
        p = sWaitData;
        q = p->mNclr->mData;
        switch (p->field20) {
            case 0:
                NNS_GfdRegisterNewVramTransferTask(0xe, p->mPaletteIndex << 5, q + 0xe0, 0x20);
                break;
            case 1:
                NNS_GfdRegisterNewVramTransferTask(0x1e, p->mPaletteIndex << 5, q + 0xe0, 0x20);
                break;
        }
    }
}

#pragma thumb off
