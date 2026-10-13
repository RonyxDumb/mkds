#pragma once
/* Function-specific inferred declarations. */
ushort GetCurrentPlayerRacerId(void);
void GetPlayerTotalTime(int param_1,undefined1 *param_2,undefined1 *param_3,undefined2 *param_4);
uint GetSomeLapCount(void);
void GetSomeMVTime(undefined1 *param_1,undefined1 *param_2,undefined2 *param_3);
uint GetSomeSndPlayer(uint param_1);
undefined4 IsRacerFinishedRace(int param_1);
void MaybeGetPlayerLapTime(int param_1,int param_2,undefined1 *param_3,undefined1 *param_4,undefined2 *param_5);
void MaybeWhenFewSecondsRemaining(void);
void NNSi_MaybeSndPlayerStartSeq(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void func_02089ef4(uint param_1);
void func_020ae7c4(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4);
uint func_020b1a20(void);
uint func_020b1dbc(void);
int func_02108ea0(int param_1);
void func_0212c6f0(uint param_1);
#define iRam020bc104 (*(int *)(uintptr_t)0x20bc104u)
#define uRam020bc0f4 (*(uint *)(uintptr_t)0x20bc0f4u)
#define uRam020bc0f8 (*(uint *)(uintptr_t)0x20bc0f8u)
#define uRam020bc0fc (*(uint *)(uintptr_t)0x20bc0fcu)
#define uRam020bc100 (*(uint *)(uintptr_t)0x20bc100u)
