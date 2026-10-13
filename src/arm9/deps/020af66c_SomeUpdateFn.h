#pragma once
/* Function-specific inferred declarations. */
ushort GetCurrentPlayerRacerId(void);
void IncreaseB358Countdown(void);
undefined2 IncrementRaceIntroFrameCounter(void);
undefined2 IncrementStaffRollFrameCount(void);
void InvokeE8Handler(void);
undefined4 IsRacerFinishedRace(int param_1);
void MaybeWhenFewSecondsRemaining(void);
void MaybeWhenFinishFlagpole(void);
void MaybeWhenLapIsCompleted(void);
void SomeUpdateFn(void);
bool func_0203c174(void);
void func_020ba3ec(void);
void func_020bab54(void);
void func_020bb5cc(void);
void func_020be3e4(void);
void func_020be9d4(void);
void func_020c31c0(void);
void func_020c43c4(void);
void func_020c5940(void);
void func_020d0a18(void);
void func_020d1298(void);
void func_020d2090(void);
void func_0212b204(void);
#define DAT_020af860 (*(uint *)(uintptr_t)0x20af860u)
#define DAT_020af864 (*(uint *)(uintptr_t)0x20af864u)
#define DAT_020af868 (*(uint *)(uintptr_t)0x20af868u)
