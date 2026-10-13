#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
int Crt0_DecompressFlushCode(int param_1);
bool Fs_ComputeCompareDigest(int param_1,undefined4 param_2,undefined4 param_3);
uint Fs_OverlayInfo_GetBinarySize(int param_1);
void Fs_OverlayInfo_Start(uint param_1);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void Os_Terminate(void);
#define iRam02005408 (*(int *)(uintptr_t)0x2005408u)
#define iRam0200540c (*(int *)(uintptr_t)0x200540cu)
#define iRam02005410 (*(int *)(uintptr_t)0x2005410u)
#define psRam02005404 (*(short **)(uintptr_t)0x2005404u)
