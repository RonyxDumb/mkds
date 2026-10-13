/* Decompiled C draft; module arm9; ROM address 02040bc0. No matching claim. */
#include "types.h"
#include "deps/02040bc0_func_02040bc0.h"

bool func_02040bc0(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(uRam02040d1c & 0xfffffffc) >> (uRam02040d1c & 3) * 8 |
          *(uint *)(uRam02040d1c & 0xfffffffc) << (uRam02040d1c & 3) * -8 + 0x20;
  bVar3 = false;
  uVar4 = (uint)*(char *)(uVar6 + 0x62);
  if (uVar4 != 0xffffffff) {
    uVar5 = (uVar4 & 0xffff) * 0x30 + uVar6 + 0x70;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    bVar2 = false;
    if ((uVar5 < 4) && ((1 << (uVar5 & 0xff) & 0xdU) != 0)) {
      bVar2 = true;
    }
    if (bVar2) goto LAB_02040c20;
  }
  bVar3 = true;
LAB_02040c20:
  if (bVar3 != false) {
    return bVar3;
  }
  uVar5 = uVar6 + 8 & 3;
  uVar6 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  if (uVar6 == 2) {
    uVar4 = (*(uint *)(uRam02040d20 & 0xfffffffc) >> (uRam02040d20 & 3) * 8 |
            *(uint *)(uRam02040d20 & 0xfffffffc) << (uRam02040d20 & 3) * -8 + 0x20) + 0x4cc;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    return uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0;
  }
  if (uVar6 != 4) {
    uVar4 = (uVar4 & 0xffff) * 0x8c +
            (*(uint *)(uRam02040d20 & 0xfffffffc) >> (uRam02040d20 & 3) * 8 |
            *(uint *)(uRam02040d20 & 0xfffffffc) << (uRam02040d20 & 3) * -8 + 0x20) + 0x14;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    bVar3 = false;
    if (((uVar4 == 1) || (uVar4 == 2)) || (uVar4 == 3)) {
      bVar3 = true;
    }
    return bVar3;
  }
  uVar6 = *(uint *)(uRam02040d20 & 0xfffffffc) >> (uRam02040d20 & 3) * 8 |
          *(uint *)(uRam02040d20 & 0xfffffffc) << (uRam02040d20 & 3) * -8 + 0x20;
  uVar4 = (uVar4 & 0xffff) * 0x8c + uVar6 + 0x14;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  bVar3 = false;
  if (((uVar4 == 1) || (uVar4 == 2)) || (uVar4 == 3)) {
    bVar3 = true;
  }
  if ((!bVar3) &&
     (uVar6 = uVar6 + 0x4e0, uVar4 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     uVar6 >> uVar4 * 8 != 0 || uVar6 << uVar4 * -8 + 0x20 != 0)) {
    return false;
  }
  return true;
}

