#include "Main/Menu/wait.h"

#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "gfd_VramTransferManager.h"
#include "code_0214cfe4.h"

#pragma thumb on

const u16 gWaitBnclIndices[4] = {0, 1, 2, 0};

void AdvanceWait(void) {
    u16 *paletteData;
    Wait *wait;

    gWait->mFrameIndexFrames++;
    if (gWait->mFrameIndexFrames >= 4) {
        gWait->mFrameIndex++;
        if (gWait->mFrameIndex >= 3) {
            gWait->mFrameIndex = 0;
        }
        gWait->mFrameIndexFrames = 0;
        QueueCellChars(gWaitBnclIndices[gWait->mFrameIndex], gWait->mNcer, gWait->mNcgr, gWait->mBncl,
                       gWait->mQueueSelector, gWait->mDestinationBnclIndex, gWait->mDestinationNcer,
                       gWait->mDestinationBncl);
        wait = gWait;
        paletteData = wait->mNclr->mData;
        switch (wait->mQueueSelector) {
            case 0:
                NNS_GfdRegisterNewVramTransferTask(0xe, wait->mPaletteIndex << 5, paletteData + 0xe0, 0x20);
                break;
            case 1:
                NNS_GfdRegisterNewVramTransferTask(0x1e, wait->mPaletteIndex << 5, paletteData + 0xe0, 0x20);
                break;
        }
    }
}

#pragma thumb off
