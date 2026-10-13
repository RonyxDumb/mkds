#pragma once
/* Function-specific inferred declarations. */
void FillPersonalGhostData_from_thumb(undefined4 param_1,int param_2);
int GetCourseIdFromInternalId(uint param_1);
void GetCurrentDate(undefined4 *param_1);
uint GetCurrentLapCount(void);
void GetPlayerTotalTime(int param_1,undefined1 *param_2,undefined1 *param_3,undefined2 *param_4);
undefined4 GetWorstStarRank_from_thumb(void);
void MaybeGetPlayerLapTime(int param_1,int param_2,undefined1 *param_3,undefined1 *param_4,undefined2 *param_5);
void MaybeHasPersonalGhostForCourse_from_thumb(undefined4 param_1);
void MaybeSetPersonalGhostForCoursePresent_from_thumb(undefined4 param_1);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void WriteSaveDataHeader_from_thumb(void);
void WriteSaveDataSection_PersonalGhost_from_thumb(int param_1,undefined4 param_2);
#define iRam020569a0 (*(int *)(uintptr_t)0x20569a0u)
#define piRam0205696c (*(int **)(uintptr_t)0x205696cu)
#define piRam02056970 (*(int **)(uintptr_t)0x2056970u)
#define puRam0205698c (*(undefined4 **)(uintptr_t)0x205698cu)
#define uRam02056974 (*(undefined4 *)(uintptr_t)0x2056974u)
#define uRam02056978 (*(uint *)(uintptr_t)0x2056978u)
#define uRam0205697c (*(uint *)(uintptr_t)0x205697cu)
#define uRam02056980 (*(uint *)(uintptr_t)0x2056980u)
#define uRam02056984 (*(uint *)(uintptr_t)0x2056984u)
#define uRam02056988 (*(uint *)(uintptr_t)0x2056988u)
#define uRam02056990 (*(uint *)(uintptr_t)0x2056990u)
#define uRam02056994 (*(uint *)(uintptr_t)0x2056994u)
#define uRam02056998 (*(uint *)(uintptr_t)0x2056998u)
#define uRam0205699c (*(uint *)(uintptr_t)0x205699cu)
#define uRam020569a4 (*(undefined4 *)(uintptr_t)0x20569a4u)
