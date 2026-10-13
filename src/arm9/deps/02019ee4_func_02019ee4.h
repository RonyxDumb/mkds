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
uint func_02019ee4(int param_1,int param_2);
#define iRam0201a344 (*(int *)(uintptr_t)0x201a344u)
#define iRam0201a348 (*(int *)(uintptr_t)0x201a348u)
#define iRam0201a34c (*(int *)(uintptr_t)0x201a34cu)
#define iRam0201a350 (*(int *)(uintptr_t)0x201a350u)
#define iRam0201a360 (*(int *)(uintptr_t)0x201a360u)
#define puRam0201a340 (*(uint **)(uintptr_t)0x201a340u)
#define puRam0201a354 (*(undefined4 **)(uintptr_t)0x201a354u)
#define puRam0201a358 (*(uint **)(uintptr_t)0x201a358u)
#define puRam0201a35c (*(uint **)(uintptr_t)0x201a35cu)
