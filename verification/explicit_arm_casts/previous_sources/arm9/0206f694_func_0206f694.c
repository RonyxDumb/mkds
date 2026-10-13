/* Decompiled C draft; module arm9; ROM address 0206f694. No matching claim. */
#include "types.h"
#include "deps/0206f694_func_0206f694.h"

void func_0206f694(int param_1,uint param_2,int *param_3,short param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int local_28;
  int local_24;
  int *local_20;
  
  if ((param_2 & 0x40000000) == 0) {
    if ((param_2 & uRam0206f810) != 0) {
      *(undefined4 *)(param_1 + 0x200) = 0;
    }
  }
  else {
    uVar10 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20 | 0x40000;
    *(short *)(param_1 + 0x236) = *(short *)(param_1 + 0x236) + param_4;
  }
  uVar6 = uRam0206f81c;
  uVar10 = (uint)(param_3 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  uVar4 = (uint)(param_3 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  if ((uVar8 >> uVar4 * 8 == 0 && uVar8 << uVar4 * -8 + 0x20 == 0) &&
      ((*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 == 0 &&
       *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20 == 0) &&
      (uVar2 >> uVar10 * 8 == 0 && uVar2 << uVar10 * -8 + 0x20 == 0))) {
    iVar3 = piRam0206f818[1];
    iVar5 = piRam0206f818[2];
    uVar10 = param_1 + 0x1fcU & 3;
    uVar4 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) *
            (longlong)*piRam0206f818;
    *(uint *)(param_1 + 0x1fc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar10 = param_1 + 0x200U & 3;
    uVar4 = *(uint *)(param_1 + 0x200U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) * (longlong)iVar3;
    *(uint *)(param_1 + 0x200) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar10 = param_1 + 0x204U & 3;
    uVar4 = *(uint *)(param_1 + 0x204U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) * (longlong)iVar5;
    *(uint *)(param_1 + 0x204) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar10 = param_1 + 0x200U & 3;
    uVar4 = *(uint *)(param_1 + 0x200U & 0xfffffffc);
    uVar8 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
    uVar10 = param_1 + 0x1fcU & 3;
    uVar4 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
    uVar4 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
    uVar10 = param_1 + 0x204U & 3;
    uVar2 = *(uint *)(param_1 + 0x204U & 0xfffffffc);
    uVar10 = uVar2 >> uVar10 * 8 | uVar2 << uVar10 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar10 * (longlong)(int)uVar10 +
            (longlong)(int)uVar4 * (longlong)(int)uVar4 +
            (longlong)(int)uVar8 * (longlong)(int)uVar8;
    if ((int)((ulonglong)lVar1 >> 0x20) < (int)(uint)((uint)lVar1 < uVar6)) {
      uVar7 = puRam0206f820[1];
      uVar9 = puRam0206f820[2];
      *(undefined4 *)(param_1 + 0x1fc) = *puRam0206f820;
      *(undefined4 *)(param_1 + 0x200) = uVar7;
      *(undefined4 *)(param_1 + 0x204) = uVar9;
    }
    return;
  }
  VecFx32_Subtract(param_3,param_1 + 0x1fc,&local_28);
  lVar1 = (longlong)(int)local_20 * (longlong)(int)local_20 +
          (longlong)local_28 * (longlong)local_28 + (longlong)local_24 * (longlong)local_24;
  iVar5 = (int)((ulonglong)lVar1 >> 0x20);
  uVar10 = (uint)((uint)lVar1 < 0x1000000);
  iVar3 = iVar5 - uVar10;
  if (iVar5 < (int)uVar10) {
    local_20 = (int *)(param_1 + 0x1fc);
    iVar3 = *param_3;
    lVar1 = CONCAT44(param_3[1],param_3[2]);
  }
  if (iVar5 < (int)uVar10) {
    *local_20 = iVar3;
    local_20[1] = (int)((ulonglong)lVar1 >> 0x20);
    local_20[2] = (int)lVar1;
  }
  else {
    VecFx32_AddScale1(uRam0206f814,&local_28,param_1 + 0x1fc,param_1 + 0x1fc);
  }
  uVar10 = param_1 + 0x260U & 3;
  uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  uVar4 = param_1 + 0x200U & 3;
  uVar6 = *(uint *)(param_1 + 0x200U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) =
       (uVar2 >> uVar10 * 8 | uVar2 << uVar10 * -8 + 0x20) +
       (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x200) = 0;
  return;
}

