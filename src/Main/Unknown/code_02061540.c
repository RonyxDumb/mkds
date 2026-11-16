#include "Main/Unknown/code_02061540.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void ghdat_loadPersonalGhostsTask(void) {
    u8 i;
    u8 *records;
    GhostRecord *record;

    records = gSaveData->mReadDestination;
    for (i = 0; i < 0x20; i++) {
        record = (GhostRecord *) (records + i * 0x30);
        if (savd_isPersonalGhostAvailable(i) != 0) {
            savd_readGhostHeader(1, i, record);
            if (gSaveCore->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
            if (gSaveCore->mErrorCode != 0) {
                record->mFilled = 0;
            }
        } else {
            record->mFilled = 0;
        }
    }
    gSaveData->mReadDestination = NULL;
    savd_endOperation();
}

void ghdat_loadPersonalGhostsAsync(void *records) {
    gSaveData->mReadDestination = records;
    savd_beginOperation();
    bgwkr_enqueueTask((void (*)(void)) ghdat_loadPersonalGhostsTask);
    gBgWkrState->mRunRequested = 1;
}
