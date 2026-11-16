#include "arena_cache_init.h"

#include "cartridge_slot_access.h"
#include "interrupt_control.h"
#include "interrupt_table_init.h"
#include "lock_word_and_bus_ownership.h"
#include "thread_scheduler.h"
#include "memory_interface_init.h"
#include "exception_context_display.h"
#include "alarm_timer.h"
#include "vblank_alarm_init.h"
#include "reset_interrupts_halt.h"
#include "model_texture_bind.h"
#include "card_rom_backup_access.h"
#include "arm_fifo_messaging.h"
#include "power_management_commands.h"
#include "system_state_globals.h"
#include "thread_mutex_types.h"
#include "overlay_id_symbols.h"
#include "system_stack_size.h"
#include "extra_arena_start.h"
#include "memory_protection.h"

u32 g_MainExRegionEnabled;
u32 g_MemoryRegionsInit;

// Fills in the arena bounds on the first call only; the extra NtrMain memory arena starts out empty.
void Os_InitializeMemoryRegionAddresses(void) {
    if (g_MemoryRegionsInit != 0) {
        return;
    }
    g_MemoryRegionsInit = 1;
    Os_SetMemoryRegionEndAddress(OS_ARENA_MAIN, Os_ComputeMemoryRegionEndAddress(OS_ARENA_MAIN));
    Os_SetMemoryRegionStartAddress(OS_ARENA_MAIN, Os_ComputeMemoryRegionStartAddress(OS_ARENA_MAIN));
    Os_SetMemoryRegionStartAddress(OS_ARENA_MAINEX, NULL);
    Os_SetMemoryRegionEndAddress(OS_ARENA_MAINEX, NULL);
    Os_SetMemoryRegionEndAddress(OS_ARENA_ITCM, Os_ComputeMemoryRegionEndAddress(OS_ARENA_ITCM));
    Os_SetMemoryRegionStartAddress(OS_ARENA_ITCM, Os_ComputeMemoryRegionStartAddress(OS_ARENA_ITCM));
    Os_SetMemoryRegionEndAddress(OS_ARENA_DTCM, Os_ComputeMemoryRegionEndAddress(OS_ARENA_DTCM));
    Os_SetMemoryRegionStartAddress(OS_ARENA_DTCM, Os_ComputeMemoryRegionStartAddress(OS_ARENA_DTCM));
    Os_SetMemoryRegionEndAddress(OS_ARENA_SHARED, Os_ComputeMemoryRegionEndAddress(OS_ARENA_SHARED));
    Os_SetMemoryRegionStartAddress(OS_ARENA_SHARED, Os_ComputeMemoryRegionStartAddress(OS_ARENA_SHARED));
    Os_SetMemoryRegionEndAddress(OS_ARENA_WRAM_MAIN, Os_ComputeMemoryRegionEndAddress(OS_ARENA_WRAM_MAIN));
    Os_SetMemoryRegionStartAddress(OS_ARENA_WRAM_MAIN, Os_ComputeMemoryRegionStartAddress(OS_ARENA_WRAM_MAIN));
}

// Sets up the extra NtrMain memory arena, and the memory protection regions when that arena is off.
void Os_InitializeMainExMemoryRegionAddress(void) {
    Os_SetMemoryRegionEndAddress(OS_ARENA_MAINEX, Os_ComputeMemoryRegionEndAddress(OS_ARENA_MAINEX));
    Os_SetMemoryRegionStartAddress(OS_ARENA_MAINEX, Os_ComputeMemoryRegionStartAddress(OS_ARENA_MAINEX));
    if (g_MainExRegionEnabled != 0 && (Os_GetSystemFlags() & 3) != 1) {
        return;
    }
    Os_SetSystemRomPU(0x200002b);
    Os_SetVectorBasePU(0x23e0021);
}

// Returns the Hi bound of the arena.
void *Os_GetMemoryRegionEndAddress(OSArenaId id) {
    return SYSTEM_WORK->mArenaInfo.hi[id];
}

// Returns the Lo bound of the arena.
void *Os_GetMemoryRegionStartAddress(OSArenaId id) {
    return SYSTEM_WORK->mArenaInfo.lo[id];
}

// Returns the Hi bound an arena starts out with.
void *Os_ComputeMemoryRegionEndAddress(OSArenaId id) {
    u32 dtcmStart;
    s32 sysStackSize;
    u32 irqStackBottom;

    switch (id) {
        case OS_ARENA_MAIN:
            return (void *) 0x23e0000;
        case OS_ARENA_MAINEX:
            if (g_MainExRegionEnabled == 0 || (Os_GetSystemFlags() & 3) == 1) {
                return NULL;
            }
            return (void *) 0x2700000;
        case OS_ARENA_ITCM:
            return (void *) 0x2000000;
        case OS_ARENA_DTCM:
            dtcmStart = (u32) &g_DTCM;
            irqStackBottom = dtcmStart + 0x3f80 - (u32) SDK_IRQ_STACKSIZE;
            sysStackSize = (s32) SDK_SYS_STACKSIZE;
            if (sysStackSize == 0) {
                return (void *) (dtcmStart < 0x27e00e0 ? 0x27e00e0 : dtcmStart);
            }
            if (sysStackSize < 0) {
                return (void *) (0x27e00e0 - sysStackSize);
            }
            return (void *) (irqStackBottom - sysStackSize);
        case OS_ARENA_SHARED:
            return (void *) 0x27ff680;
        case OS_ARENA_WRAM_MAIN:
            return (void *) 0x37f8000;
    }
    return NULL;
}

// Returns the Lo bound an arena starts out with.
void *Os_ComputeMemoryRegionStartAddress(OSArenaId id) {
    switch (id) {
        case OS_ARENA_MAIN:
#ifdef version_EUR
            return (void *) 0x21da340;
#else
            return (void *) 0x21da300;
#endif
        case OS_ARENA_MAINEX:
            if (g_MainExRegionEnabled == 0 || (Os_GetSystemFlags() & 3) == 1) {
                return NULL;
            }
            return SDK_SECTION_ARENA_EX_START;
        case OS_ARENA_ITCM:
            return (void *) 0x1ffffa0;
        case OS_ARENA_DTCM:
            return (void *) 0x27e00e0;
        case OS_ARENA_SHARED:
            return (void *) 0x27ff000;
        case OS_ARENA_WRAM_MAIN:
            return (void *) 0x37f8000;
    }
    return NULL;
}

// Stores the Hi bound of the arena.
void Os_SetMemoryRegionEndAddress(OSArenaId id, void *newHi) {
    SYSTEM_WORK->mArenaInfo.hi[id] = newHi;
}

// Stores the Lo bound of the arena.
void Os_SetMemoryRegionStartAddress(OSArenaId id, void *newLo) {
    SYSTEM_WORK->mArenaInfo.lo[id] = newLo;
}

// Turns the extra NtrMain memory arena off; must run before Os_Initialize.
void Os_DisableMainExRegion(void) {
    g_MainExRegionEnabled = 0;
}

// Starts up the OS: arenas, PXI, locks, interrupts, exceptions, memory, threads, reset, cartridge, card and power
// management.
void Os_Initialize(void) {
    Os_InitializeMemoryRegionAddresses();
    j_Fifo_Initialize();
    Os_InitializeLock();
    Os_InitializeMainExMemoryRegionAddress();
    Os_InitializeIrqThreadQueue();
    Os_InitializeSvcStack();
    Os_InitializeExceptionHandler();
    Mem_Initialize();
    Os_InitializeVAlarm();
    OSi_InitVramExclusive();
    Os_InitializeThread();
    Os_InitializeResetFifoHandler();
    CTRDG_Initialize_from_thumb();
    Card_Initialize();
    PM_Initialize();
}

// clang-format off
// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_StoreAll(void) {
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_FlushAll(void) {
    mov ip, #0x0
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_InvalidateRangeNoClean(void *address, u32 size) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void DC_SomeClean(const void *address, u32 size) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void Arm_FlushRange(const void *address, int size) {
    mov ip, #0x0
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void Mem_DcDrainWriteBuffer(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void IC_InvalidateRangeNoClean(void *address, u32 size) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c5, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
// clang-format on
