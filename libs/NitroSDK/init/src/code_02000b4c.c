#include "types.h"
#include "unk_02000000.h"

// The two block list words lie inside this object.
extern u8 gRomArchiveTransfer[];
extern u8 arc_list[];

// Build information block, kept in .text after NitroStartUp: the addresses the startup code reads
// (the list of blocks to copy and clear, the range of words to clear) and the version strings.
#pragma define_section INIT_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section INIT_TEXT begin

BuildInfoLayout BuildInfo = {
    {gRomArchiveTransfer + 0x1500, gRomArchiveTransfer + 0x1518, arc_list, arc_list, (void *) 0x021804c0, 0,
     (void *) 0x030028a0, (void *) 0xdec00621, (void *) 0x2106c0de},
    "[SDK+NINTENDO:BACKUP]",
    "[SDK+NINTENDO:DWC20051007-1634_DWC20051007_NOTOUCH]",
    "[SDK+NINTENDO:WiFi1.0.10200.0510061936]",
    "[SDK+UBIQUITOUS:SSL]",
    "[SDK+UBIQUITOUS:CPS]",
};

#pragma section INIT_TEXT end
