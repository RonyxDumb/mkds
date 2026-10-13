/* Decompiled C draft; module arm9; ROM address 02051814. No matching claim. */
#include "types.h"
#include "deps/02051814_func_02051814.h"

void func_02051814(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = uRam0205188c;
  uVar6 = *(uint *)(uRam0205188c & 0xfffffffc) >> (uRam0205188c & 3) * 8 |
          *(uint *)(uRam0205188c & 0xfffffffc) << (uRam0205188c & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x18;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0xe) != 0) == param_1) {
    return;
  }
  *(undefined4 *)(uVar6 + 0xc) = 0xd;
  uVar2 = uRam02051890;
  uVar3 = uVar1 & 3;
  uVar5 = *(uint *)(uVar1 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x10) = 1;
  iVar4 = func_021453ec(uVar2);
  if (iVar4 != 2) {
    func_020533a0();
    return;
  }
  return;
}

