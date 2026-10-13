/* Decompiled C draft; module arm9; ROM address 0204ce60. No matching claim. */
#include "types.h"
#include "deps/0204ce60_func_0204ce60.h"

void func_0204ce60(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar5;
  
  uVar1 = uRam0204cf50 + 0xc & 3;
  uVar3 = *(uint *)(uRam0204cf50 + 0xc & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  *(undefined4 *)(uRam0204cf50 + 4) = 1;
  func_0204d28c();
  uVar3 = uRam0204cf50;
  uVar1 = *(uint *)(uRam0204cf50 & 0xfffffffc) >> (uRam0204cf50 & 3) * 8;
  iVar7 = *(uint *)(uRam0204cf50 & 0xfffffffc) << (uRam0204cf50 & 3) * -8 + 0x20;
  if (uVar1 == 0 && iVar7 == 0) {
    uVar5 = uRam0204cf50 + 0x2c & 3;
    uVar4 = *(uint *)(uRam0204cf50 + 0x2c & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  else {
    uVar5 = uRam0204cf50 + 0x28 & 3;
    uVar4 = *(uint *)(uRam0204cf50 + 0x28 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  }
  uVar4 = uRam0204cf50 + 4 & 3;
  uVar6 = *(uint *)(uRam0204cf50 + 4 & 0xfffffffc);
  if (uVar6 >> uVar4 * 8 != 0 || uVar6 << uVar4 * -8 + 0x20 != 0) {
    iVar8 = uRam0204cf50 + 0x40;
    if (uVar1 == 0 && iVar7 == 0) {
      uVar2 = func_02006914(iVar8,uVar5 & 0xffff);
    }
    else {
      uVar2 = func_02006954(iVar8);
    }
    iVar7 = func_02144048(uRam0204cf58,0,iVar8,uVar2);
    uVar5 = uRam0204cf50;
    *(uint *)(uVar3 + 8) = (uint)(iVar7 == 2);
    uVar1 = uVar5 + 8 & 3;
    uVar5 = *(uint *)(uVar5 + 8 & 0xfffffffc);
    *(uint *)(uVar3 + 4) = (uint)(uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0);
    return;
  }
  return;
}

