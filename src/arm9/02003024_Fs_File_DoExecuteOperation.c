/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_SleepThread Os_Thread_Sleep
#define OS_RestoreInterrupts Os_RestoreIrq
#define FSi_ReleaseCommand Fs_File_ReleaseOperation
#define fsi_default_command SDK_data_02152b5c
#define FSi_TranslateCommand Fs_File_DoExecuteOperation
#include "FS_file.h"
#include "FS_archive.h"
#include "FSi_util.h"
#include "FS_command.h"
#include "code32.h"
extern void FSi_ReleaseCommand(FSFile * p_file, FSResult ret);
#pragma thumb off
FSResult FSi_TranslateCommand(FSFile *p_file, FSCommandType command)
{
    FSResult ret;

    FSArchive *const p_arc = p_file->arc;
    const int bit = (1 << command);

    if (FS_IsFileSyncMode(p_file))
        p_arc->flag |= FS_ARCHIVE_FLAG_IS_SYNC;
    else
        p_arc->flag |= FS_ARCHIVE_FLAG_IS_ASYNC;

    if ((p_arc->proc_flag & bit) != 0)
    {
        switch (ret = (*p_arc->proc) (p_file, command))
        {
        case FS_RESULT_SUCCESS:
        case FS_RESULT_FAILURE:
        case FS_RESULT_UNSUPPORTED:
            p_file->error = ret;
            break;
        case FS_RESULT_PROC_ASYNC:
            break;
        case FS_RESULT_PROC_UNKNOWN:
            ret = FS_RESULT_PROC_DEFAULT;
            p_arc->proc_flag &= ~bit;
            break;
        default:
            break;
        }
    }
    else
    {
        ret = FS_RESULT_PROC_DEFAULT;
    }
    if (ret == FS_RESULT_PROC_DEFAULT)
    {
        ret = (*fsi_default_command[command]) (p_file);
    }
    if (ret == FS_RESULT_PROC_ASYNC)
    {
        if (FS_IsFileSyncMode(p_file))
        {
            OSIntrMode bak_psr = OS_DisableInterrupts();
            while (FSi_IsArchiveSync(p_arc))
                OS_SleepThread(&p_arc->sync_q);
            ret = p_file->error;
            (void)OS_RestoreInterrupts(bak_psr);
        }
    }
    else if (!FS_IsFileSyncMode(p_file))
    {
        p_arc->flag &= ~FS_ARCHIVE_FLAG_IS_ASYNC;
        FSi_ReleaseCommand(p_file, ret);
    }
    else
    {
        p_arc->flag &= ~FS_ARCHIVE_FLAG_IS_SYNC;
        p_file->error = ret;
    }
    return ret;
}
