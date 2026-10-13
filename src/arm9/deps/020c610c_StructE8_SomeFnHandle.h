#pragma once
/* Function-specific inferred declarations. */
undefined4 CheckHandleSaveTimeTrialRecord2(int param_1);
undefined4 CheckHandleSaveTimeTrialRecord_LeastLap(int param_1);
void FillPersonalGhostData_from_thumb(undefined4 param_1,int param_2);
ushort GetCurrentPlayerRacerId(void);
uint GetLeastTimeLap(int param_1,undefined1 *param_2,undefined1 *param_3,ushort *param_4);
void GetPlayerTotalTime(int param_1,undefined1 *param_2,undefined1 *param_3,undefined2 *param_4);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void StructE8_SomeFnHandle(void);
bool StructRCTime_SmallerThan_from_thumb(ushort *param_1,ushort *param_2);
void WriteTimeTrialsSaveDataSection_from_thumb(void);
uint func_020b1a20(void);
uint func_020ba620(void);
#define iRam020c6418 (*(int *)(uintptr_t)0x20c6418u)
#define iRam020c6424 (*(int *)(uintptr_t)0x20c6424u)
#define uRam020c6408 (*(uint *)(uintptr_t)0x20c6408u)
#define uRam020c640c (*(uint *)(uintptr_t)0x20c640cu)
#define uRam020c6410 (*(uint *)(uintptr_t)0x20c6410u)
#define uRam020c6414 (*(undefined4 *)(uintptr_t)0x20c6414u)
#define uRam020c641c (*(undefined4 *)(uintptr_t)0x20c641cu)
#define uRam020c6420 (*(undefined4 *)(uintptr_t)0x20c6420u)
