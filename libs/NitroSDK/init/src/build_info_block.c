#include "types.h"
#include "build_info_layout.h"
#include "build_info_block.h"
#include "file_archive_access.h"


// Build information block, kept in .text after NtrStartup: the addresses the startup code reads
// (the list of blocks to copy and clear, the range of words to clear) and the version strings.
// End of the NtrMain module's .bss, the end of the range the startup code clears.
#ifdef version_EUR
#define BSS_END 0x021804e0
#else
#define BSS_END 0x021804c0
#endif

#pragma define_section INIT_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section INIT_TEXT begin

BuildInfoLayout g_StartModuleParams = {
    {gRomArchiveTransfer + 0x1500, gRomArchiveTransfer + 0x1518, &g_ArchiveList, &g_ArchiveList, (void *) BSS_END, 0,
     (void *) 0x030028a0, (void *) 0xdec00621, (void *) 0x2106c0de},
    "[SDK+NINTENDO:BACKUP]",
    "[SDK+NINTENDO:DWC20051007-1634_DWC20051007_NOTOUCH]",
    "[SDK+NINTENDO:WiFi1.0.10200.0510061936]",
    "[SDK+UBIQUITOUS:SSL]",
    "[SDK+UBIQUITOUS:CPS]",
};

#pragma section INIT_TEXT end
