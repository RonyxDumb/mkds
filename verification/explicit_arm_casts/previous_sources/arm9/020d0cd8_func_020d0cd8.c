/* Decompiled C draft; module arm9; ROM address 020d0cd8. No matching claim. */
#include "types.h"
#include "deps/020d0cd8_func_020d0cd8.h"

void func_020d0cd8(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_r10;
  undefined4 local_30;
  uint uVar8;
  
  iVar10 = 0;
  uVar1 = func_020c0db0();
  uVar6 = uRam020d0e24;
  uVar7 = (*(uint *)(uRam020d0e24 & 0xfffffffc) >> (uRam020d0e24 & 3) * 8 |
          *(uint *)(uRam020d0e24 & 0xfffffffc) << (uRam020d0e24 & 3) * -8 + 0x20) + 0xc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar7 = uVar8 + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(uVar8 + 4) = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 1;
  uVar7 = uVar6 & 3;
  uVar2 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0xc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar6 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar7 = uVar6 + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if (((int)uVar7 < 0) || (0x13 < (int)uVar7)) {
    *(undefined4 *)(uVar6 + 4) = 0;
  }
  uVar6 = uRam020d0e24;
  iVar11 = 0;
  uVar8 = *(uint *)(uRam020d0e24 & 0xfffffffc) >> (uRam020d0e24 & 3) * 8 |
          *(uint *)(uRam020d0e24 & 0xfffffffc) << (uRam020d0e24 & 3) * -8 + 0x20;
  uVar7 = uVar8 + 0xc & 3;
  uVar2 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if ((int)uVar7 < 10) {
    unaff_r10 = 1;
  }
  uVar2 = uVar8 + 8 & 3;
  uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (9 < (int)uVar7) {
    unaff_r10 = 0;
  }
  if (0 < (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    iVar9 = 0;
    local_30 = 0xa6;
    do {
      uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      uVar7 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar11 * 4;
      uVar2 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar3 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
      uVar7 = uVar8 + 0x10 & 3;
      uVar2 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
      iVar4 = func_020b5ae8(uVar3 + 4,(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + iVar9,
                            uVar1,1,1);
      if (iVar4 != 0) {
        uVar5 = local_30;
        if (unaff_r10 != 0) {
          uVar5 = 0xa5;
        }
        uVar5 = GetB3C4_Cell_RaceS(uVar5);
        iVar10 = iVar10 + 1;
        uVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10;
        uVar2 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined4 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar9 + 8) = uVar5;
        uVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10;
        uVar2 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined2 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar9 + 0xc) = 1;
        uVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10;
        uVar2 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined2 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar9 + 0xe) = 0;
        uVar7 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10;
        uVar2 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(undefined2 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar9 + 0x10) =
             *(undefined2 *)(uVar3 + 0x7e);
        iVar9 = iVar9 + 0x14;
      }
      uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      iVar11 = iVar11 + 1;
      uVar7 = uVar8 + 8 & 3;
      uVar2 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    } while (iVar11 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar10;
  return;
}

