#pragma once
/* Function-specific inferred declarations. */
void FIFONotEmptyIRQHandler(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
#define _DAT_04100000 (*(uint *)(uintptr_t)0x4100000u)
#define iRam0214d6e0 (*(int *)(uintptr_t)0x214d6e0u)
#define puRam0214d6dc (*(ushort **)(uintptr_t)0x214d6dcu)
#define puRam0214d6e4 (*(uint **)(uintptr_t)0x214d6e4u)
