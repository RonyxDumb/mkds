/* Decompiled C draft; module arm9; ROM address 020e0680. No matching claim. */
#include "types.h"
#include "deps/020e0680_func_020e0680.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020e0680(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                  undefined2 *param_5)

{
  uint uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 auStack_20 [16];
  
  if (param_4 != (int *)0x0) {
    uVar1 = param_1 + 0x10U & 3;
    uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *param_4 = -(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x14U & 3;
    uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    param_4[1] = -(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x18U & 3;
    uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    param_4[2] = -(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    VecFx32_Subtract(param_2,param_1 + 4,(int *)(void *)(auStack_20));
    uVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_20),param_1 + 0x28);
    VecFx32_AddScale1(uVar3,param_1 + 0xa0,(uint)(uintptr_t)(param_4),param_4);
    uVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_20),param_1 + 0x34);
    VecFx32_AddScale1(uVar3,param_1 + 0xac,(uint)(uintptr_t)(param_4),param_4);
    uVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_20),param_1 + 0x40);
    VecFx32_AddScale1(uVar3,param_1 + 0xb8,(uint)(uintptr_t)(param_4),param_4);
    VecFx32_Subtract((uint)(uintptr_t)(auStack_20),(uint)(uintptr_t)(param_4),param_4);
  }
  if (param_5 != (undefined2 *)0x0) {
    uVar2 = VecFx32_CrossProduct_0(param_1 + 0x124,param_3);
    *param_5 = uVar2;
    return;
  }
  return;
}

