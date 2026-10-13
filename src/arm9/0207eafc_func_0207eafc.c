/* Decompiled C draft; module arm9; ROM address 0207eafc. No matching claim. */
#include "types.h"
#include "deps/0207eafc_func_0207eafc.h"

int func_0207eafc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_28;
  int local_24;
  int local_20;
  undefined1 auStack_1c [12];
  
  VecFx32_Subtract(param_1,param_2,&local_28);
  iVar2 = Vector3_DotProduct(param_3,(uint)(uintptr_t)(&local_28));
  lVar1 = (longlong)
          (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) * (longlong)iVar2;
  local_28 = local_28 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar5 = param_3 + 4 & 3;
  uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) * (longlong)iVar2;
  local_24 = local_24 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar5 = param_3 + 8 & 3;
  uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) * (longlong)iVar2;
  local_20 = local_20 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  Vector3_Cross(param_4,(uint)(uintptr_t)(&local_28),(uint *)(void *)(auStack_1c));
  uVar3 = VecFx32_Norm((uint)(uintptr_t)(auStack_1c));
  uVar4 = VecFx32_CrossProduct_0(param_4,(uint)(uintptr_t)(&local_28));
  uVar5 = func_02148538(uVar3,uVar4);
  iVar7 = ((int)uVar5 >> 0x1f) * uRam0207ebf8 +
          uVar5 * 0x39 + (int)((ulonglong)uRam0207ebf8 * (ulonglong)uVar5 >> 0x20) +
          (uint)(0x7fffffff < (uint)((ulonglong)uRam0207ebf8 * (ulonglong)uVar5));
  iVar2 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_1c),param_3);
  if (iVar2 < 0) {
    iVar7 = -iVar7;
  }
  return iVar7;
}

