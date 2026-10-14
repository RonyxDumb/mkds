/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts Os_DisableIrq
#define OS_RestoreInterrupts Os_RestoreIrq
#define FS_CancelFile File_If1Set2AndUnk20
#include <nitro/mi.h>
#include <nitro/os.h>
#include <nitro/pxi.h>
#include <nitro/fs.h>

#include "../include/rom.h"
#include "../include/util.h"
#include "../include/command.h"

#pragma thumb off
void FS_CancelFile (FSFile *p_file)
{
	FS_ASSERT_INIT(FALSE);
	FS_ASSERT_ARG(p_file, FALSE);

	{
		OSIntrMode bak_psr = OS_DisableInterrupts();

		if (FS_IsBusy(p_file)) {
			p_file->stat |= FS_FILE_STATUS_CANCEL;
			p_file->arc->flag |= FS_ARCHIVE_FLAG_CANCELING;
		}

		(void)OS_RestoreInterrupts(bak_psr);
	}
}
