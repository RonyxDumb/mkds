#pragma once

#include "types.h"

typedef enum {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

// Lo and Hi bound of every arena, kept in OSSystemWork.mArenaInfo.
typedef struct {
    void *lo[OS_ARENA_MAX];
    void *hi[OS_ARENA_MAX];
} OSArenaInfo;

// Writes back every data cache line by set and way (cp15 c7,c10,2) without invalidating.
void DC_StoreAll(void);
// For every set and way: drains the write buffer (c7,c10,4), then writes back and invalidates the line (c7,c14,2).
void DC_FlushAll(void);
// Invalidates the data cache lines of the range at p, length n, without writing back (c7,c6,1, 32-byte lines).
void DC_InvalidateRangeNoClean(void *address, u32 size);
// Writes back the data cache lines of the range at p, length n, without invalidating (c7,c10,1).
void DC_SomeClean(const void *address, u32 size);
// For each line of the range at p, length n: drains the write buffer (c7,c10,4), then writes back and invalidates it
// (c7,c14,1).
void Arm_FlushRange(const void *address, int size);
// Drains the write buffer (c7,c10,4).
void Mem_DcDrainWriteBuffer(void);
// Invalidates the instruction cache lines of the range at p, length n (c7,c5,1).
void IC_InvalidateRangeNoClean(void *address, u32 size);
// Starts up the OS: arenas, PXI, locks, interrupts, exceptions, memory, threads, reset, cartridge, card and power
// management.
void Os_Initialize(void);
// Turns the extra NtrMain memory arena off; must run before Os_Initialize.
void Os_DisableMainExRegion(void);
// Stores the Lo bound of the arena.
void Os_SetMemoryRegionStartAddress(OSArenaId id, void *newLo);
// Stores the Hi bound of the arena.
void Os_SetMemoryRegionEndAddress(OSArenaId id, void *newHi);
// Returns the Lo bound an arena starts out with.
void *Os_ComputeMemoryRegionStartAddress(OSArenaId id);
// Returns the Hi bound an arena starts out with.
void *Os_ComputeMemoryRegionEndAddress(OSArenaId id);
// Returns the Lo bound of the arena.
void *Os_GetMemoryRegionStartAddress(OSArenaId id);
// Returns the Hi bound of the arena.
void *Os_GetMemoryRegionEndAddress(OSArenaId id);
// Sets up the extra NtrMain memory arena, and the memory protection regions when that arena is off.
void Os_InitializeMainExMemoryRegionAddress(void);
// Fills in the arena bounds on the first call only; the extra NtrMain memory arena starts out empty.
void Os_InitializeMemoryRegionAddresses(void);
