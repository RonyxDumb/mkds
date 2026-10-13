/* Decompiled C draft; module arm9; ROM address 0210300c. No matching claim. */
#include "types.h"
#include "deps/0210300c_func_0210300c.h"

undefined4 func_0210300c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar6 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  *(uint *)(param_1 + 0x138) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 1;
  uVar6 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (0x10 < (int)uVar6) {
    return 1;
  }
  iVar4 = uVar6 * 0xc;
  iVar5 = iRam02103184 + iVar4;
  *(int *)(param_1 + 0x154) = (int)*(short *)(iRam02103184 + iVar4);
  *(int *)(param_1 + 0x158) = (int)*(short *)(iVar5 + 2);
  *(int *)(param_1 + 0x164) = (int)*(short *)(iVar5 + 4);
  *(int *)(param_1 + 0x168) = (int)*(short *)(iVar5 + 6);
  *(uint *)(param_1 + 0x16c) = (uint)*(ushort *)(iVar5 + 8);
  *(uint *)(param_1 + 0x170) = (uint)*(ushort *)(iVar5 + 10);
  uVar2 = uRam021031a8;
  uVar1 = uRam02103198;
  uVar8 = uRam0210318c;
  uVar6 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if ((uVar6 == 0xc) || (uVar6 == 0xd)) {
    if (uVar6 == 0xc) {
      *(undefined4 *)(param_1 + 0x174) = uRam021031a4;
      *(undefined4 *)(param_1 + 0x178) = uVar2;
      *(undefined4 *)(param_1 + 0x18c) = 0x800;
    }
    else {
      *(undefined4 *)(param_1 + 0x174) = 0x800;
      uVar8 = uRam021031a0;
      *(undefined4 *)(param_1 + 0x178) = 0x800;
      *(undefined4 *)(param_1 + 0x18c) = uVar8;
    }
  }
  else {
    uVar3 = param_1 + 0x158U & 3;
    uVar7 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    if ((int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) < 1) {
      if (uVar6 == 4) {
        *(undefined4 *)(param_1 + 0x174) = 0x1000;
        *(undefined4 *)(param_1 + 0x178) = 0x1000;
        *(undefined4 *)(param_1 + 0x18c) = 0x1000;
      }
      else {
        *(undefined4 *)(param_1 + 0x174) = uRam02103194;
        uVar8 = uRam0210319c;
        *(undefined4 *)(param_1 + 0x178) = uVar1;
        *(undefined4 *)(param_1 + 0x18c) = uVar8;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x174) = uRam02103188;
      uVar1 = uRam02103190;
      *(undefined4 *)(param_1 + 0x178) = uVar8;
      *(undefined4 *)(param_1 + 0x18c) = uVar1;
    }
  }
  uVar6 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar8 = 1;
  if ((uVar6 != 2) && (uVar6 != 0x10)) {
    uVar8 = 0;
  }
  *(undefined4 *)(param_1 + 0x194) = uVar8;
  if ((((0 < *(short *)(iVar5 + 2)) &&
       (uVar6 = param_1 + 0x138U & 3, uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc),
       uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20, uVar6 != 0)) && (uVar6 != 0xe)) &&
     (uVar6 = param_1 + 0x198U & 3, uVar3 = *(uint *)(param_1 + 0x198U & 0xfffffffc),
     uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0)) {
    uVar6 = param_1 + 300U & 3;
    uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
    func_020f8e3c(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20,0xf1);
  }
  return 0;
}

