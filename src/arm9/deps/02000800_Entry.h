#pragma once
/* Function-specific inferred declarations. */
void main(void);
int Crt0_DecompressFlushCode(int param_1);
uint Crt0_InitializePU(void);
void Crt0_MemorySet32(undefined4 param_1,undefined4 *param_2,int param_3);
void Crt0_RegionCopy(void);
void Crt0_Reset32sAndAlphaFlags(void);
void Crt0_RunInitArray(void);
void Entry(void);
void NtrStartup(void);
#define _DAT_04000208 (*(undefined4 *)(uintptr_t)0x4000208u)
#define iRam020008fc (*(int *)(uintptr_t)0x20008fcu)
#define iRam0200090c (*(int *)(uintptr_t)0x200090cu)
#define pcRam02000918 (*(__typeof__(main) **)(uintptr_t)0x2000918u)
#define puRam02000910 (*(undefined4 **)(uintptr_t)0x2000910u)
#define uRam02000904 (*(undefined4 *)(uintptr_t)0x2000904u)
#define uRam02000908 (*(undefined4 *)(uintptr_t)0x2000908u)
#define uRam02000914 (*(undefined4 *)(uintptr_t)0x2000914u)
