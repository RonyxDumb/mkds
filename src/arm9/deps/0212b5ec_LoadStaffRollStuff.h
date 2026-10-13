#pragma once
/* Function-specific inferred declarations. */
undefined4 AllocateReserveTEQSub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
void G2d_Sprite_CreateFromTiles(void);
int GetAnotherSubEngineBGOffset(void);
undefined4 GetLoadedFont_from_thumb(int param_1);
int GetVramBg0BaseOffset_Bottom(void);
void Gfx_ReadPalette(int *param_1,int param_2);
void InitializeGlobalTEQ(undefined4 param_1,undefined4 param_2);
void LoadStaffRollStuff(undefined4 param_1);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
int find_buf_fn_from_thumb(undefined4 param_1);
#define piRam0212b7c0 (*(int **)(uintptr_t)0x212b7c0u)
#define puRam0212b7c8 (*(uint **)(uintptr_t)0x212b7c8u)
#define puRam0212b7cc (*(ushort **)(uintptr_t)0x212b7ccu)
#define uRam0212b7bc (*(undefined4 *)(uintptr_t)0x212b7bcu)
#define uRam0212b7c4 (*(undefined4 *)(uintptr_t)0x212b7c4u)
#define uRam0212b7d0 (*(undefined4 *)(uintptr_t)0x212b7d0u)
#define uRam0212b7d4 (*(undefined4 *)(uintptr_t)0x212b7d4u)
