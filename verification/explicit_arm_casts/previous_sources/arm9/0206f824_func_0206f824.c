/* Decompiled C draft; module arm9; ROM address 0206f824. No matching claim. */
#include "types.h"
#include "deps/0206f824_func_0206f824.h"

void func_0206f824(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_38 [12];
  int local_2c;
  int local_28;
  int local_24;
  
  uVar3 = func_020e73a0(*(undefined2 *)(param_1 + 0x4d8));
  iVar4 = func_020e7388(*(undefined2 *)(param_1 + 0x4d8));
  iVar4 = iVar4 * 0x96;
  uVar1 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  iVar6 = iRam0206f910;
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 2) != 0) {
    iVar4 = iVar4 >> 1;
    iVar6 = iRam0206f910 >> 1;
  }
  if (param_3 == 0) {
    VecFx32_Subtract(uVar3,param_1 + 0x80,&local_2c);
    Vector3_Cross(param_2,&local_2c,auStack_38);
    Vector3_Cross(auStack_38,param_2,&local_2c);
    lVar2 = (longlong)local_24 * (longlong)local_24 +
            (longlong)local_2c * (longlong)local_2c + (longlong)local_28 * (longlong)local_28;
    if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
      Vector3_MaybeNormalize(&local_2c,param_1 + 0x268);
    }
  }
  uVar1 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20 | 0x100000;
  uVar1 = param_1 + 0x274U & 3;
  uVar5 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  *(uint *)(param_1 + 0x274) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + iVar6;
  uVar1 = param_1 + 0x274U & 3;
  uVar5 = *(uint *)(param_1 + 0x274U & 0xfffffffc);
  if (iVar4 < (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
    *(int *)(param_1 + 0x274) = iVar4;
  }
  return;
}

