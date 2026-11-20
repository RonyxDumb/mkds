#pragma once

#include "types.h"

typedef enum {
    MEM_REGION_MAIN_RAM = 0,
    MEM_REGION_1 = 1,
    MEM_REGION_MAIN_RAM_EXTRA = 2,
    MEM_REGION_ITCM = 3,
    MEM_REGION_DTCM = 4,
    MEM_REGION_SHARED = 5,
    MEM_REGION_WRAM = 6,
    MEM_REGION_7 = 7,
    MEM_REGION_8 = 8,
    MEM_REGION_COUNT = 9
} OSArenaId;

// Lo and Hi bound of every arena, kept in OSSystemWork.mArenaInfo.
typedef struct {
    void *lo[MEM_REGION_COUNT];
    void *hi[MEM_REGION_COUNT];
} OSArenaInfo;

// Writes back every data cache line by set and way (cp15 c7,c10,2) without invalidating.
void DC_StoreAll(void);
// For every set and way: drains the write buffer (c7,c10,4), then writes back and invalidates the line (c7,c14,2).
void DC_FlushAll(void);
// Invalidates the data cache lines of the range at p, length n, without writing back (c7,c6,1, 32-byte lines).
void DC_InvalidateRange(void *address, u32 size);
// Writes back the data cache lines of the range at p, length n, without invalidating (c7,c10,1).
void DC_StoreRange(const void *address, u32 size);
// For each line of the range at p, length n: drains the write buffer (c7,c10,4), then writes back and invalidates it
// (c7,c14,1).
void DC_FlushRange(const void *address, int size);
// Drains the write buffer (c7,c10,4).
void DC_WaitWriteBufferEmpty(void);
// Invalidates the instruction cache lines of the range at p, length n (c7,c5,1).
void IC_InvalidateRange(void *address, u32 size);
// Starts up the OS: arenas, PXI, locks, interrupts, exceptions, memory, threads, reset, cartridge, card and power
// management.
void OS_Init(void);
// Turns the extra main memory arena off; must run before OS_Init.
void OS_DisableMainExArena(void);
// Stores the Lo bound of the arena.
void OS_SetArenaLo(OSArenaId id, void *newLo);
// Stores the Hi bound of the arena.
void OS_SetArenaHi(OSArenaId id, void *newHi);
// Returns the Lo bound an arena starts out with.
void *OS_GetInitArenaLo(OSArenaId id);
// Returns the Hi bound an arena starts out with.
void *OS_GetInitArenaHi(OSArenaId id);
// Returns the Lo bound of the arena.
void *OS_GetArenaLo(OSArenaId id);
// Returns the Hi bound of the arena.
void *OS_GetArenaHi(OSArenaId id);
// Sets up the extra main memory arena, and the memory protection regions when that arena is off.
void OS_InitArenaEx(void);
// Fills in the arena bounds on the first call only; the extra main memory arena starts out empty.
void OS_InitArena(void);
