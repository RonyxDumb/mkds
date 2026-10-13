/* Decompiled C draft; module arm9; ROM address 020162d4. No matching claim. */
#include "types.h"
#include "deps/020162d4_AnotherPaletteHandler.h"

uint AnotherPaletteHandler(int param_1,int param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 == 0) {
    uVar3 = 8;
  }
  else {
    uVar3 = param_1 + 7U & 0xfffffff8;
  }
  uVar5 = 0;
  if (uRam02016408 <= uVar3) {
    return 0;
  }
  if (param_3 == 1) {
    uVar7 = *(uint *)((uint)piRam0201640c & 0xfffffffc) >> ((uint)piRam0201640c & 3) * 8 |
            *(uint *)((uint)piRam0201640c & 0xfffffffc) << ((uint)piRam0201640c & 3) * -8 + 0x20;
    if (param_2 == 0) {
      uVar6 = 0x10 - (uVar7 & 0xf) & 0xf;
    }
    else {
      uVar6 = 8 - (uVar7 & 7) & 7;
    }
    uVar8 = uVar3 + uVar6;
    uVar1 = (uint)(piRam0201640c + 1) & 3;
    uVar4 = *(uint *)((uint)(piRam0201640c + 1) & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - uVar7 < uVar8) {
      bVar2 = false;
    }
    else if ((param_2 == 0) || (uVar7 + uVar8 < 0x10001)) {
      uVar5 = uVar7 + uVar6;
      bVar2 = true;
      *piRam0201640c =
           (*(uint *)((uint)piRam0201640c & 0xfffffffc) >> ((uint)piRam0201640c & 3) * 8 |
           *(uint *)((uint)piRam0201640c & 0xfffffffc) << ((uint)piRam0201640c & 3) * -8 + 0x20) +
           uVar8;
    }
    else {
      bVar2 = false;
    }
  }
  else {
    uVar7 = (uint)(piRam0201640c + 1) & 3;
    uVar6 = *(uint *)((uint)(piRam0201640c + 1) & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    if (uVar3 <= uVar7) {
      if (param_2 == 0) {
        uVar6 = uVar7 - uVar3 & 0xf;
      }
      else {
        uVar6 = uVar7 - uVar3 & 7;
      }
      if (uVar3 + uVar6 <=
          uVar7 - (*(uint *)((uint)piRam0201640c & 0xfffffffc) >> ((uint)piRam0201640c & 3) * 8 |
                  *(uint *)((uint)piRam0201640c & 0xfffffffc) <<
                  ((uint)piRam0201640c & 3) * -8 + 0x20)) {
        if ((param_2 == 0) || (uVar7 < 0x10001)) {
          bVar2 = true;
          uVar5 = (uint)(piRam0201640c + 1) & 3;
          uVar7 = *(uint *)((uint)(piRam0201640c + 1) & 0xfffffffc);
          uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) - (uVar3 + uVar6);
          piRam0201640c[1] = uVar5;
        }
        else {
          bVar2 = false;
        }
        goto LAB_020163e8;
      }
    }
    bVar2 = false;
  }
LAB_020163e8:
  if (bVar2) {
    uVar3 = uRam02016410 & uVar5 >> 3 | (uVar3 >> 3) << 0x10;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

