/* Decompiled C draft; module arm9; ROM address 020c7c54. No matching claim. */
#include "types.h"
#include "deps/020c7c54_func_020c7c54.h"

void func_020c7c54(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020c7d3c;
  uVar7 = *(uint *)(uRam020c7d3c & 0xfffffffc) >> (uRam020c7d3c & 3) * 8 |
          *(uint *)(uRam020c7d3c & 0xfffffffc) << (uRam020c7d3c & 3) * -8 + 0x20;
  iVar11 = 0;
  uVar5 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) {
    iVar9 = 0;
    iVar8 = 0;
    do {
      uVar5 = uVar7 + 0xc & 3;
      uVar3 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      iVar4 = func_020b5f68((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + iVar9);
      if (iVar4 != 0) {
        uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        uVar5 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar11 * 4;
        uVar3 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
        if ((*(ushort *)(uVar5 + 2) & 2) == 0) {
          uVar3 = uVar7 + 0x10 & 3;
          uVar7 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
          iVar4 = func_020b5ae8(uVar5 + 4,(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + iVar8,
                                uVar2,0,0);
          if (iVar4 != 0) {
            uVar6 = GetB3C4_Cell_RaceS(0x89);
            iVar10 = iVar10 + 1;
            uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            *(undefined4 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + iVar8 + 8) = uVar6;
            uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
            uVar3 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            *(undefined2 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + iVar8 + 0xc) = 2;
            iVar8 = iVar8 + 0x14;
          }
        }
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar11 = iVar11 + 1;
      uVar5 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      iVar9 = iVar9 + 8;
    } while (iVar11 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar10;
  return;
}

