/* Decompiled C draft; module arm9; ROM address 0204cc94. No matching claim. */
#include "types.h"
#include "deps/0204cc94_func_0204cc94.h"

void func_0204cc94(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = uRam0204ce54;
  uVar9 = uRam0204ce54 + 0xc & 3;
  uVar6 = *(uint *)(uRam0204ce54 + 0xc & 0xfffffffc);
  if (uVar6 >> uVar9 * 8 == 0 && uVar6 << uVar9 * -8 + 0x20 == 0) {
    return;
  }
  sVar1 = *(short *)(param_1 + 4);
  if (sVar1 == 7) {
    uVar9 = *(uint *)(uRam0204ce54 & 0xfffffffc) >> (uRam0204ce54 & 3) * 8;
    iVar5 = *(uint *)(uRam0204ce54 & 0xfffffffc) << (uRam0204ce54 & 3) * -8 + 0x20;
    if (uVar9 == 0 && iVar5 == 0) {
      return;
    }
    uVar6 = uRam0204ce54 + 8 & 3;
    uVar3 = *(uint *)(uRam0204ce54 + 8 & 0xfffffffc);
    if (uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0) {
      if (uVar9 == 0 && iVar5 == 0) {
        uVar6 = uRam0204ce54 + 0x2c & 3;
        uVar3 = *(uint *)(uRam0204ce54 + 0x2c & 0xfffffffc);
        uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      }
      else {
        uVar6 = uRam0204ce54 + 0x28 & 3;
        uVar3 = *(uint *)(uRam0204ce54 + 0x28 & 0xfffffffc);
        uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      }
      uVar3 = uRam0204ce54 + 4 & 3;
      uVar4 = *(uint *)(uRam0204ce54 + 4 & 0xfffffffc);
      if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
        iVar7 = uRam0204ce54 + 0x40;
        if (uVar9 == 0 && iVar5 == 0) {
          uVar2 = func_02006914(iVar7,uVar6 & 0xffff);
        }
        else {
          uVar2 = func_02006954(iVar7);
        }
        iVar5 = func_02144048(uRam0204ce5c,0,iVar7,uVar2);
        uVar6 = uRam0204ce54;
        *(uint *)(uVar8 + 8) = (uint)(iVar5 == 2);
        uVar9 = uVar6 + 8 & 3;
        uVar6 = *(uint *)(uVar6 + 8 & 0xfffffffc);
        *(uint *)(uVar8 + 4) = (uint)(uVar6 >> uVar9 * 8 == 0 && uVar6 << uVar9 * -8 + 0x20 == 0);
        return;
      }
      return;
    }
    return;
  }
  if (sVar1 == 9) {
    if (*(uint *)(uRam0204ce54 & 0xfffffffc) >> (uRam0204ce54 & 3) * 8 != 0 ||
        *(uint *)(uRam0204ce54 & 0xfffffffc) << (uRam0204ce54 & 3) * -8 + 0x20 != 0) {
      uVar9 = uRam0204ce54 + 0x4b18 & 3;
      uVar8 = *(uint *)(uRam0204ce54 + 0x4b18 & 0xfffffffc);
      *(uint *)(uRam0204ce54 + 0x4b18) =
           (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) &
           ~(1 << (*(ushort *)(param_1 + 0x12) & 0xff));
      return;
    }
    return;
  }
  if (sVar1 == 0x15) {
    uVar9 = param_1 + 0xcU & 3;
    uVar8 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    if (*(uint *)(uRam0204ce54 & 0xfffffffc) >> (uRam0204ce54 & 3) * 8 == 0 &&
        *(uint *)(uRam0204ce54 & 0xfffffffc) << (uRam0204ce54 & 3) * -8 + 0x20 == 0) {
      func_020068f4(uVar9,*(undefined2 *)(param_1 + 0x10));
      return;
    }
    uVar8 = uRam0204ce54 + 0x4b18 & 3;
    uVar6 = *(uint *)(uRam0204ce54 + 0x4b18 & 0xfffffffc);
    *(uint *)(uRam0204ce54 + 0x4b18) =
         uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20 | 1 << (*(ushort *)(param_1 + 0x12) & 0xff)
    ;
    func_0200692c(uVar9);
    return;
  }
  return;
}

