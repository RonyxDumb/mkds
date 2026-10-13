/* Decompiled C draft; module arm9; ROM address 020cde18. No matching claim. */
#include "types.h"
#include "deps/020cde18_func_020cde18.h"

void func_020cde18(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined6 uVar14;
  
  iVar11 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020cdf00;
  uVar3 = *(uint *)(uRam020cdf00 & 0xfffffffc) >> (uRam020cdf00 & 3) * 8 |
          *(uint *)(uRam020cdf00 & 0xfffffffc) << (uRam020cdf00 & 3) * -8 + 0x20;
  iVar12 = 0;
  uVar8 = uVar3 + 8 & 3;
  uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if (0 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
    iVar9 = 0;
    do {
      uVar8 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar12 * 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      if ((*(ushort *)(uVar8 + 2) & 1) == 0) {
        uVar7 = uVar3 + 0x10 & 3;
        uVar3 = *(uint *)(uVar3 + 0x10 & 0xfffffffc);
        iVar10 = uVar8 + 4;
        iVar4 = func_020b5ae8(iVar10,(int *)(uintptr_t)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar9),uVar2
                              ,1,1);
        if (iVar4 != 0) {
          uVar5 = GetB3C4_Cell_RaceS(0x8d);
          uVar8 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar8 & 3;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc);
          *(undefined4 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar9 + 8) = uVar5;
          uVar14 = CheckVectorBounds_Clock_Airship(iVar10);
          uVar6 = (undefined2)((uint6)uVar14 >> 0x20);
          bVar13 = (int)uVar14 != 0;
          if (bVar13) {
            uVar6 = 2;
          }
          uVar8 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
          uVar3 = uVar8 & 3;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc);
          if (!bVar13) {
            uVar6 = 3;
          }
          iVar11 = iVar11 + 1;
          *(undefined2 *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + iVar9 + 0xc) = uVar6;
          iVar9 = iVar9 + 0x14;
        }
      }
      uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar12 = iVar12 + 1;
      uVar8 = uVar3 + 8 & 3;
      uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    } while (iVar12 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20));
  }
  *(int *)(uVar3 + 4) = iVar11;
  return;
}

