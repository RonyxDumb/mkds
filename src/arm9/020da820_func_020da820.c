/* Decompiled C draft; module arm9; ROM address 020da820. No matching claim. */
#include "types.h"
#include "deps/020da820_func_020da820.h"

void func_020da820(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint uStack_20;
  int iStack_1c;
  uint uStack_18;
  uint uVar3;
  
  uVar3 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  if (*(short *)(uVar3 + 0x2c) == 0) {
    uVar3 = param_1 + 0xe8U & 3;
    uVar4 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    uVar2 = param_1 + 0xecU & 3;
    uVar7 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
    VecFx32_Subtract(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                     uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,&iStack_2c);
    lVar1 = (longlong)iStack_24 * (longlong)iStack_24 +
            (longlong)iStack_2c * (longlong)iStack_2c + (longlong)iStack_28 * (longlong)iStack_28;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_2c),&iStack_2c);
    }
    iStack_1c = 0;
    uStack_20 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    uVar3 = param_2 + 8 & 3;
    uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uStack_18 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    iVar5 = Vector3_DotProduct(&iStack_2c);
    iStack_28 = iStack_1c -
                ((uint)((longlong)iStack_28 * (longlong)iVar5) >> 0xc |
                (int)((ulonglong)((longlong)iStack_28 * (longlong)iVar5) >> 0x20) << 0x14);
    iStack_2c = uStack_20 -
                ((uint)((longlong)iStack_2c * (longlong)iVar5) >> 0xc |
                (int)((ulonglong)((longlong)iStack_2c * (longlong)iVar5) >> 0x20) << 0x14);
    iStack_24 = uStack_18 -
                ((uint)((longlong)iStack_24 * (longlong)iVar5) >> 0xc |
                (int)((ulonglong)((longlong)iStack_24 * (longlong)iVar5) >> 0x20) << 0x14);
    lVar1 = (longlong)iStack_24 * (longlong)iStack_24 +
            (longlong)iStack_2c * (longlong)iStack_2c + (longlong)iStack_28 * (longlong)iStack_28;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_2c),&iStack_2c);
    }
    iVar5 = func_020fa3d0(3,8,param_1 + 4,uRam020daa0c);
    if (iVar5 != 0) {
      *(undefined4 *)(iVar5 + 0x68) = 0xcd;
      *(undefined4 *)(iVar5 + 0x6c) = 0xcd;
      *(undefined4 *)(iVar5 + 0x70) = 0xcd;
      iVar6 = VecFx32_Norm(param_2);
      iVar6 = iVar6 + 0x5000;
      *(uint *)(iVar5 + 0x5c) =
           (uint)((longlong)iStack_2c * (longlong)iVar6) >> 0xc |
           (int)((ulonglong)((longlong)iStack_2c * (longlong)iVar6) >> 0x20) << 0x14;
      *(uint *)(iVar5 + 0x60) =
           (uint)((longlong)iStack_28 * (longlong)iVar6) >> 0xc |
           (int)((ulonglong)((longlong)iStack_28 * (longlong)iVar6) >> 0x20) << 0x14;
      *(uint *)(iVar5 + 100) =
           (uint)((longlong)iStack_24 * (longlong)iVar6) >> 0xc |
           (int)((ulonglong)((longlong)iStack_24 * (longlong)iVar6) >> 0x20) << 0x14;
      uVar3 = iVar5 + 0x60U & 3;
      uVar2 = *(uint *)(iVar5 + 0x60U & 0xfffffffc);
      *(uint *)(iVar5 + 0x60) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0xf000;
      VecFx32_Add(iVar5 + 0x50,iVar5 + 0x5c,(int *)(uintptr_t)(iVar5 + 0x50));
      func_020f6630(iVar5,0,param_1 + 4,param_2);
      return;
    }
    return;
  }
  return;
}

