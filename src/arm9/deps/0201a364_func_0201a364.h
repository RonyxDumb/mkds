#pragma once
/* Function-specific inferred declarations. */
void G3_LoadMtx43(void);
void G3_MultMtx43(void);
void MTX_Concat43(uint param_1,uint *param_2,uint *param_3);
undefined4 *MTX_Scale43__from_thumb(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 * Matrix4x3_Identity(undefined4 *param_1);
void VecFx32_CrossProduct(uint param_1,uint param_2,uint *param_3);
void VecFx32_Normalize(uint param_1,int *param_2);
uint Vector3_DotProduct(uint param_1,uint param_2);
uint func_0201a364(int param_1,int param_2);
#define iRam0201a7c0 (*(int *)(uintptr_t)0x201a7c0u)
#define iRam0201a7c4 (*(int *)(uintptr_t)0x201a7c4u)
#define iRam0201a7c8 (*(int *)(uintptr_t)0x201a7c8u)
#define iRam0201a7cc (*(int *)(uintptr_t)0x201a7ccu)
#define iRam0201a7dc (*(int *)(uintptr_t)0x201a7dcu)
#define puRam0201a7bc (*(uint **)(uintptr_t)0x201a7bcu)
#define puRam0201a7d0 (*(undefined4 **)(uintptr_t)0x201a7d0u)
#define puRam0201a7d4 (*(uint **)(uintptr_t)0x201a7d4u)
#define puRam0201a7d8 (*(uint **)(uintptr_t)0x201a7d8u)
