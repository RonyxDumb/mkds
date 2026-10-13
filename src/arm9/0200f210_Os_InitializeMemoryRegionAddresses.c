/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_GetInitArenaHi Os_ComputeMemoryRegionEndAddress
#define OS_SetArenaHi Os_SetMemoryRegionEndAddress
#define OS_GetInitArenaLo Os_ComputeMemoryRegionStartAddress
#define OS_SetArenaLo Os_SetMemoryRegionStartAddress
#define OSi_Initialized SDK_data_021701b4
#define OS_InitArena Os_InitializeMemoryRegionAddresses
#include "OS_arena.h"

#include "nitro/types.h"
#include "OS_protectionRegion.h"
#include "OS_emulator.h"
#include "mmap.h"
#include "code32.h"
extern void* OS_GetInitArenaHi(OSArenaId id);
extern void OS_SetArenaHi(OSArenaId id, void* newHi);
extern void* OS_GetInitArenaLo(OSArenaId id);
extern void OS_SetArenaLo(OSArenaId id, void* newLo);
extern BOOL OSi_Initialized;
void OS_InitArena(void) {
    if (OSi_Initialized) {
        return;
    }
    OSi_Initialized = TRUE;

    OS_SetArenaHi(OS_ARENA_MAIN, OS_GetInitArenaHi(OS_ARENA_MAIN));
    OS_SetArenaLo(OS_ARENA_MAIN, OS_GetInitArenaLo(OS_ARENA_MAIN));

    OS_SetArenaLo(OS_ARENA_MAINEX, (void *)0);
    OS_SetArenaHi(OS_ARENA_MAINEX, (void *)0);

    OS_SetArenaHi(OS_ARENA_ITCM, OS_GetInitArenaHi(OS_ARENA_ITCM));
    OS_SetArenaLo(OS_ARENA_ITCM, OS_GetInitArenaLo(OS_ARENA_ITCM));

    OS_SetArenaHi(OS_ARENA_DTCM, OS_GetInitArenaHi(OS_ARENA_DTCM));
    OS_SetArenaLo(OS_ARENA_DTCM, OS_GetInitArenaLo(OS_ARENA_DTCM));

    OS_SetArenaHi(OS_ARENA_SHARED, OS_GetInitArenaHi(OS_ARENA_SHARED));
    OS_SetArenaLo(OS_ARENA_SHARED, OS_GetInitArenaLo(OS_ARENA_SHARED));

    OS_SetArenaHi(OS_ARENA_WRAM_MAIN, OS_GetInitArenaHi(OS_ARENA_WRAM_MAIN));
    OS_SetArenaLo(OS_ARENA_WRAM_MAIN, OS_GetInitArenaLo(OS_ARENA_WRAM_MAIN));
}
