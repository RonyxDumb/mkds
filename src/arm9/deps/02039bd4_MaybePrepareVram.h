#pragma once
/* Function-specific inferred declarations. */
void GX_DisableBankForLCDC(void);
void GX_SetBankForLCDC(ushort param_1);
void MaybePrepareVram(void);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
#define DAT_02039c6c (*(uint *)(uintptr_t)0x2039c6cu)
#define DAT_02039c70 (*(undefined4 *)(uintptr_t)0x2039c70u)
#define DAT_02039c74 (*(undefined4 *)(uintptr_t)0x2039c74u)
#define DAT_02039c78 (*(undefined4 *)(uintptr_t)0x2039c78u)
