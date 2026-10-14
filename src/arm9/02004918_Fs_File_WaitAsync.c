/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_ExecuteSyncCommand Fs_File_ExecuteSyncOperation
#define FS_WaitAsync Fs_File_WaitAsync
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"

#pragma thumb off
BOOL FS_WaitAsync(FSFile * p_file)
{
    BOOL is_owner = FALSE;
    OSIntrMode bak_par = OS_DisableInterrupts();
    if (FS_IsBusy(p_file))
    {
        is_owner = !(p_file->stat & (FS_FILE_STATUS_SYNC | FS_FILE_STATUS_OPERATING));
        if (is_owner)
        {
            p_file->stat |= FS_FILE_STATUS_SYNC;
            do
            {
                OS_SleepThread(p_file->queue);
            } while (!(p_file->stat & FS_FILE_STATUS_OPERATING));
        }
        else
        {
            do
            {
                OS_SleepThread(p_file->queue);
            } while (FS_IsBusy(p_file));
        }
    }
    (void)OS_RestoreInterrupts(bak_par);
    if (is_owner)
    {
        return FSi_ExecuteSyncCommand(p_file);
    }

    return FS_IsSucceeded(p_file);
}
