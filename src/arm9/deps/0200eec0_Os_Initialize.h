#pragma once
/* Function-specific inferred declarations. */
void CTRDG_Initialize_from_thumb(void);
void Card_Initialize(void);
void Mem_Initialize(void);
void OSi_InitVramExclusive(void);
void Os_Initialize(void);
void Os_InitializeExceptionHandler(void);
void Os_InitializeIrqThreadQueue(void);
void Os_InitializeLock(void);
void Os_InitializeMainExMemoryRegionAddress(void);
void Os_InitializeMemoryRegionAddresses(void);
void Os_InitializeResetFifoHandler(void);
void Os_InitializeSvcStack(void);
void Os_InitializeThread(void);
void Os_InitializeVAlarm(void);
void PM_Initialize(void);
void func_0214d5b8(void);

