#include "Main/Unknown/code_02061428.h"
#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057800.h"
#include "01/code_021956dc.h"

void ghdat_loadDownloadGhostsTask(void) {
    u8 i;
    u8 *records;
    GhostRecord *record;

    records = gSaveData->mReadDestination;
    for (i = 0; i < 10; i++) {
        record = (GhostRecord *) (records + i * 0x230);
        if (savd_isDownloadGhostAvailable(i) != 0) {
            savd_readGhostHeaderWithEmblem(0, i, record);
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
    savd_endOperation();
    gSaveData->mReadDestination = NULL;
}

void ghdat_loadDownloadGhostsAsync(void *records) {
    gSaveData->mReadDestination = records;
    savd_beginOperation();
    bgwkr_enqueueTask((void (*)(void)) ghdat_loadDownloadGhostsTask);
    gBgWkrState->mRunRequested = 1;
}
