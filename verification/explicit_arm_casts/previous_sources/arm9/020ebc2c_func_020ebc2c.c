/* Decompiled C draft; module arm9; ROM address 020ebc2c. No matching claim. */
#include "types.h"
#include "deps/020ebc2c_func_020ebc2c.h"

undefined4 func_020ebc2c(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar6;
  undefined4 local_20;
  int local_1c;
  undefined4 uStack_18;
  uint uVar5;
  
  local_20 = *(undefined4 *)(param_1 + 4);
  local_1c = *(int *)(param_1 + 8);
  uStack_18 = *(undefined4 *)(param_1 + 0xc);
  iVar6 = param_1 + 0x28;
  uVar5 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0xbc,iVar6);
  if (iVar2 < 1) {
    VecFx32_AddScale1(uVar5,iVar6,&local_20,&local_20);
  }
  else {
    VecFx32_AddScale1(-uVar5,iVar6,&local_20,&local_20);
  }
  iVar6 = param_1 + 0x34;
  uVar5 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0xbc,iVar6);
  if (iVar2 < 1) {
    VecFx32_AddScale1(uVar5,iVar6,&local_20,&local_20);
  }
  else {
    VecFx32_AddScale1(-uVar5,iVar6,&local_20,&local_20);
  }
  iVar6 = param_1 + 0x40;
  uVar5 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0xbc,iVar6);
  if (iVar2 < 1) {
    VecFx32_AddScale1(uVar5,iVar6,&local_20,&local_20);
  }
  else {
    VecFx32_AddScale1(-uVar5,iVar6,&local_20,&local_20);
  }
  VecFx32_Subtract(&local_20,param_1 + 0xb0,&local_20);
  uVar5 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  local_1c = local_1c + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  iVar2 = VecFx32_CrossProduct_0(&local_20,param_1 + 0xbc);
  uVar5 = uRam020ebe64;
  if ((iVar2 < 0) &&
     (uVar4 = param_1 + 0x14U & 3, uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc),
     (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 0)) {
    uVar4 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    *(uint *)(param_1 + 0xd0) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - iVar2;
    uVar4 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = -uVar3;
    *(uint *)(param_1 + 0x14) =
         uVar3 * -0x400 >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
    uVar4 = param_1 + 0xd8U & 3;
    uVar3 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0xe4) =
         (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
         (((int)uVar4 >> 0x1f) * uVar5 +
         ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
    uVar4 = param_1 + 0xdcU & 3;
    uVar3 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0xe8) =
         (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
         (((int)uVar4 >> 0x1f) * uVar5 +
         ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
    uVar4 = param_1 + 0xe0U & 3;
    uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0xec) =
         (uint)((ulonglong)uVar5 * (ulonglong)uVar4) >> 0xc |
         (((int)uVar4 >> 0x1f) * uVar5 +
         ((int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) - uVar4)) * 0x100000;
    uVar5 = param_1 + 0xe4U & 3;
    uVar4 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
    lVar1 = (ulonglong)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 0x9000;
    *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    uVar5 = param_1 + 0xecU & 3;
    uVar4 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
    lVar1 = (ulonglong)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 0x9000;
    *(uint *)(param_1 + 0x18) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    return 1;
  }
  return 0;
}

