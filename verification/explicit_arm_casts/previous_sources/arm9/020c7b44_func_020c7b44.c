/* Decompiled C draft; module arm9; ROM address 020c7b44. No matching claim. */
#include "types.h"
#include "deps/020c7b44_func_020c7b44.h"

void func_020c7b44(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020c7c04;
  uVar6 = *(uint *)(uRam020c7c04 & 0xfffffffc) >> (uRam020c7c04 & 3) * 8 |
          *(uint *)(uRam020c7c04 & 0xfffffffc) << (uRam020c7c04 & 3) * -8 + 0x20;
  iVar11 = 0;
  uVar7 = uVar6 + 8 & 3;
  uVar3 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
    iVar9 = 0;
    do {
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      uVar3 = uVar7 + 0x10 & 3;
      uVar8 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      uVar7 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar11 * 4;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      iVar4 = func_020b5ae8((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + 4,
                            (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar9,uVar2,1,1);
      if (iVar4 != 0) {
        uVar5 = GetB3C4_Cell_RaceS(0x8b);
        iVar10 = iVar10 + 1;
        uVar7 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined4 *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar9 + 8) = uVar5;
        uVar7 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined2 *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar9 + 0xc) = 2;
        iVar9 = iVar9 + 0x14;
      }
      uVar6 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar11 = iVar11 + 1;
      uVar7 = uVar6 + 8 & 3;
      uVar3 = *(uint *)(uVar6 + 8 & 0xfffffffc);
    } while (iVar11 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20));
  }
  *(int *)(uVar6 + 4) = iVar10;
  return;
}

