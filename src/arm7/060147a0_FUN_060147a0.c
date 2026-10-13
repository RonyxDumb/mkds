/* Decompiled C draft; module arm7; ROM address 060147a0. No matching claim. */
#include "types.h"
#include "deps/060147a0_FUN_060147a0.h"

void FUN_060147a0(int param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = (*(uint *)(DAT_06014810 & 0xfffffffc) >> (DAT_06014810 & 3) * 8 |
          *(uint *)(DAT_06014810 & 0xfffffffc) << (DAT_06014810 & 3) * -8 + 0x20) + DAT_06014814;
  iVar7 = iVar5 + param_1 * 0x14;
  if (*(short *)(iVar5 + param_1 * 0x14) != 0) {
    uVar1 = iVar7 + 8U & 3;
    uVar3 = *(uint *)(iVar7 + 8U & 0xfffffffc);
    sVar2 = *(short *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    if (sVar2 == 0) {
      uVar1 = iVar7 + 0xcU & 3;
      uVar3 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
      *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 8) = 2;
    }
    else {
      uVar1 = iVar7 + 0xcU & 3;
      uVar3 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
      *(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 8) = sVar2;
    }
    uVar1 = iVar7 + 0xcU & 3;
    uVar4 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
    uVar3 = iVar7 + 0x10U & 3;
    uVar6 = *(uint *)(iVar7 + 0x10U & 0xfffffffc);
    (*(code *)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20))
              (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,0);
  }
  return;
}

