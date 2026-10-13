/* Decompiled C draft; module arm9; ROM address 02039378. No matching claim. */
#include "types.h"
#include "deps/02039378_func_02039378.h"

void func_02039378(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = uRam02039408 + 0x14 & 3;
  uVar4 = *(uint *)(uRam02039408 + 0x14 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (param_2 == 0) {
    param_4 = param_1 * uVar5 +
              (*(uint *)(uRam02039408 & 0xfffffffc) >> (uRam02039408 & 3) * 8 |
              *(uint *)(uRam02039408 & 0xfffffffc) << (uRam02039408 & 3) * -8 + 0x20);
  }
  else if (param_2 == 1) {
    uVar4 = uRam02039408 + 8 & 3;
    uVar1 = *(uint *)(uRam02039408 + 8 & 0xfffffffc);
    param_4 = param_1 * uVar5 + (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20);
  }
  else if (param_2 == 2) {
    uVar4 = uRam02039408 + 0xc & 3;
    uVar1 = *(uint *)(uRam02039408 + 0xc & 0xfffffffc);
    param_4 = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) - param_1 * uVar5;
  }
  uVar4 = *(uint *)(uRam02039408 & 0xfffffffc) >> (uRam02039408 & 3) * 8 |
          *(uint *)(uRam02039408 & 0xfffffffc) << (uRam02039408 & 3) * -8 + 0x20;
  if (param_4 < uVar4) {
    param_4 = uVar4;
  }
  uVar1 = uRam02039408 + 4 & 3;
  uVar2 = *(uint *)(uRam02039408 + 4 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar1 < param_4 + uVar5) {
    iVar3 = MaybeBoundsCheck(uVar1 - uVar4,uVar5);
    param_4 = uVar5 * iVar3 + uVar4;
  }
  *(uint *)(uRam02039408 + 8) = param_4;
  return;
}

