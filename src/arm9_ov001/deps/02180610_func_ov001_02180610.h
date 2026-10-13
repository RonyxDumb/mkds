#pragma once
/* Function-specific inferred declarations. */
void func_ov001_02180610(void);
void func_ov001_02180728(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void func_ov001_02180740(int param_1);
void func_ov001_02180774(int param_1);
void func_ov001_021807a8(int param_1);
void func_ov001_021807e4(void);
void func_ov001_02180cb4(int param_1);
void func_ov001_02180ccc(int param_1);
#define iRam02180724 (*(int *)(uintptr_t)0x2180724u)
#define piRam02180720 (*(int **)(uintptr_t)0x2180720u)
#define puRam02180718 (*(undefined2 **)(uintptr_t)0x2180718u)
#define uRam0218071c (*(undefined4 *)(uintptr_t)0x218071cu)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
#define func_0x02036bec Mem_AllocateHeap
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
#define func_0x02038d88 CreateDisplayConfig
void SetGlobalDisplayConfig(int param_1);
#define func_0x02037abc SetGlobalDisplayConfig
undefined4 GetLoadedFont_from_thumb(int param_1);
#define func_0x020b403c GetLoadedFont_from_thumb
void G2d_Sprite_CreateFromTiles(void);
#define func_0x02023408 G2d_Sprite_CreateFromTiles
void InitializeTestContent(void);
#define func_0x020ca6c4 InitializeTestContent
