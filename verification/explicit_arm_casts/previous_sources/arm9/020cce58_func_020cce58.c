/* Decompiled C draft; module arm9; ROM address 020cce58. No matching claim. */
#include "types.h"
#include "deps/020cce58_func_020cce58.h"

void func_020cce58(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  iVar9 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020ccf54;
  uVar3 = *(uint *)(uRam020ccf54 & 0xfffffffc) >> (uRam020ccf54 & 3) * 8 |
          *(uint *)(uRam020ccf54 & 0xfffffffc) << (uRam020ccf54 & 3) * -8 + 0x20;
  iVar10 = 0;
  uVar8 = uVar3 + 8 & 3;
  uVar6 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if (0 < (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20)) {
    iVar7 = 0;
    do {
      uVar8 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar10 * 4;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      if (((*(ushort *)(uVar8 + 2) & 1) == 0) && ((*(ushort *)(uVar8 + 2) & 2) == 0)) {
        uVar6 = uVar3 + 0x10 & 3;
        uVar3 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
        iVar4 = func_020b5ae8(uVar8 + 4,(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7,
                              uVar2,1,1);
        if (iVar4 != 0) {
          uVar5 = GetB3C4_Cell_RaceS(0xad);
          iVar9 = iVar9 + 1;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined4 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7 + 8) = uVar5;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined2 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7 + 0xc) = 3;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined2 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7 + 0xe) = 0;
          uVar3 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(undefined2 *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7 + 0x10) =
               *(undefined2 *)(uVar8 + 0x7e);
          iVar7 = iVar7 + 0x14;
        }
      }
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar10 = iVar10 + 1;
      uVar8 = uVar3 + 8 & 3;
      uVar6 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    } while (iVar10 < (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20));
  }
  *(int *)(uVar3 + 4) = iVar9;
  return;
}

