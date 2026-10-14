/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CARDi_UnlockResource SDK_data_021459cc
#define CARD_UnlockBackup Card_UnlockBackupResource
#include "CARD_common.h"
#include "CARD_request.h"
#include "consts.h"
#include "MI_memory.h"
#include "OS_terminate_proc.h"
#include "OS_spinLock.h"
#include "OS_cache.h"
#include "MB_mb.h"
#include "PXI_fifo.h"
#include "mmap.h"
#include "code32.h"
extern void CARDi_UnlockResource(CARDiOwner owner, CARDTargetMode target);
#pragma thumb off
void CARD_UnlockBackup(u16 lock_id)
{
    CARDi_UnlockResource(lock_id, CARD_TARGET_BACKUP);
}
