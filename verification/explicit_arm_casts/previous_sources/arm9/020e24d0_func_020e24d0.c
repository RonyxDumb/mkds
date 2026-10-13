/* Decompiled C draft; module arm9; ROM address 020e24d0. No matching claim. */
#include "types.h"
#include "deps/020e24d0_func_020e24d0.h"

void func_020e24d0(int param_1,undefined4 param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  int local_18;
  int local_14;
  int local_10;
  uint uVar5;
  
  local_18 = *(int *)(param_1 + 4);
  local_14 = *(undefined4 *)(param_1 + 8);
  local_10 = *(undefined4 *)(param_1 + 0xc);
  VecFx32_Subtract(&local_18,param_2);
  iVar2 = VecFx32_CrossProduct_0(param_1 + 0x28,&local_18);
  iVar3 = VecFx32_CrossProduct_0(param_1 + 0x40,&local_18);
  if (iVar2 < 1) {
    uVar5 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar5 = -(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  else {
    uVar5 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  if (iVar3 < 1) {
    uVar4 = param_1 + 0x40U & 3;
    uVar6 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar4 = -(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  }
  else {
    uVar4 = param_1 + 0x40U & 3;
    uVar6 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  }
  local_18 = uVar5 * 2 + uVar4;
  if (iVar2 < 1) {
    uVar5 = param_1 + 0x30U & 3;
    uVar4 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    uVar5 = -(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  else {
    uVar5 = param_1 + 0x30U & 3;
    uVar4 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  if (iVar3 < 1) {
    uVar4 = param_1 + 0x48U & 3;
    uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar4 = -(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  }
  else {
    uVar4 = param_1 + 0x48U & 3;
    uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  }
  local_10 = uVar5 * 2 + uVar4;
  uVar5 = param_1 + 0x118U & 3;
  uVar4 = *(uint *)(param_1 + 0x118U & 0xfffffffc);
  local_14 = ((int)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - 0x14000) >> 4) + 0x2000;
  lVar1 = (longlong)local_10 * (longlong)local_10 +
          (longlong)local_18 * (longlong)local_18 + (longlong)local_14 * (longlong)local_14;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(&local_18,&local_18);
  }
  func_020d7b88(&local_18,param_1 + 0xc4);
  *(undefined2 *)(param_1 + 0x152) = 900;
  if ((0xf < *(short *)(param_1 + 0xfe)) ||
     (uVar5 = param_1 + 0x14U & 3, uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc),
     uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20, (int)uVar5 < 1)) {
    uVar5 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar5 + 0x7000;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e262c;
  *(undefined2 *)(param_1 + 0xfe) = 0x14;
  return;
}

