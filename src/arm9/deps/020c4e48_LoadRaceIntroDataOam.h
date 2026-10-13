#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void CopyToOamA(undefined4 param_1,int param_2,uint param_3);
void LoadRaceIntroDataOam(void);
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define puRam020c4f04 (*(ushort **)(uintptr_t)0x20c4f04u)
#define uRam020c4f00 (*(uint *)(uintptr_t)0x20c4f00u)
