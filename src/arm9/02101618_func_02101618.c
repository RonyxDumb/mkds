/* Decompiled C draft; module arm9; ROM address 02101618. No matching claim. */
#include "types.h"
#include "deps/02101618_func_02101618.h"

undefined4 func_02101618(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort uVar8;
  uint uVar7;
  
  uVar2 = param_1 + 0x15cU & 3;
  uVar1 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  uVar7 = param_1 + 0x130U & 3;
  uVar6 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    if (param_3 < 7) {
      uVar2 = param_1 + 0x17cU & 3;
      uVar1 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      iVar5 = 0x1c;
      *(uint *)(param_1 + 0x17c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + iRam02101744;
      uVar8 = 6;
    }
    else {
      uVar2 = param_1 + 0x17cU & 3;
      uVar1 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      iVar5 = 0x14;
      iVar3 = 0;
      if ((int)uVar2 < 0) {
        iVar3 = iRam02101748;
      }
      uVar8 = 2;
      if ((int)uVar2 < 0) {
        *(uint *)(param_1 + 0x17c) = uVar2 + iVar3;
      }
      else {
        *(uint *)(param_1 + 0x17c) = uVar2 + 0x8f;
      }
    }
    uVar2 = param_1 + 0x170U & 3;
    uVar4 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
    uVar1 = param_1 + 0x17cU & 3;
    uVar6 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
    *(uint *)(param_1 + 0x170) =
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) +
         (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  }
  else {
    iVar5 = -7;
    uVar2 = func_02061f90();
    uVar8 = (ushort)(2 < uVar2);
    func_0210174c(param_1);
  }
  func_02101964(param_1,param_2);
  if (iVar5 < (int)uVar7) {
    if (0 < *(short *)(param_1 + 0xd8)) {
      *(ushort *)(param_1 + 0xd8) = *(short *)(param_1 + 0xd8) - uVar8;
    }
    uVar2 = param_1 + 0x15cU & 3;
    uVar1 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
    if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
      iVar3 = 0x28;
    }
    else {
      iVar3 = 0x37;
    }
    if (iVar3 <= (int)uVar7) {
      if (param_3 < 7) {
        if (*(short *)(param_1 + 0x13a) == 0) {
          uVar2 = param_1 + 0x170U & 3;
          uVar7 = *(uint *)(param_1 + 0x170U & 0xfffffffc);
          *(uint *)(param_1 + 0x14c) = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
          uVar2 = param_1 + 0x17cU & 3;
          uVar7 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
          *(uint *)(param_1 + 0x150) = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
        }
        *(short *)(param_1 + 0x13c) = (short)param_3;
        *(undefined2 *)(param_1 + 0x13e) = 1;
      }
      return 1;
    }
  }
  return 0;
}

