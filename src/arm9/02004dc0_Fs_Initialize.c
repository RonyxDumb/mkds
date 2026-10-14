/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FSi_InitRom Fs_InitializeMountRom
#define is_init SDK_data_0216f350
#define FS_Init Fs_Initialize
#include "nitro.h"
#include "MI_byteAccess.h"
#include "FS_rom.h"
#include "FS_file.h"
#include "FSi_util.h"
#include "code32.h"
extern BOOL is_init;
#pragma thumb off
void FS_Init(u32 default_dma_no)
{
    if (!is_init)
    {
        is_init = TRUE;
        FSi_InitRom(default_dma_no);
    }
}
