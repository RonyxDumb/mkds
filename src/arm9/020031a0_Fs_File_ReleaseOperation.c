/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_WakeupThread Os_Thread_WakeUp
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#include "FS_file.h"
#include "FS_archive.h"
#include "FSi_util.h"
#include "FS_command.h"
#include "code32.h"

#pragma thumb off
void FSi_ReleaseCommand(FSFile * p_file, FSResult ret)
{
    OSIntrMode bak_psr = OS_DisableInterrupts();
    FSi_CutFromList(p_file);
    p_file->stat &= ~(FS_FILE_STATUS_CANCEL | FS_FILE_STATUS_BUSY | FS_FILE_STATUS_SYNC | FS_FILE_STATUS_ASYNC | FS_FILE_STATUS_OPERATING);
    p_file->error = ret;
    OS_WakeupThread(p_file->queue);
    (void)OS_RestoreInterrupts(bak_psr);
}
