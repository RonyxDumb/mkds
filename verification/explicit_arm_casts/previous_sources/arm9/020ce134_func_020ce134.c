/* Decompiled C draft; module arm9; ROM address 020ce134. No matching claim. */
#include "types.h"
#include "deps/020ce134_func_020ce134.h"

void func_020ce134(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined6 uVar14;
  uint uVar10;
  
  iVar11 = 0;
  uVar2 = func_020c0db0();
  uVar1 = uRam020ce248;
  uVar7 = *(uint *)(uRam020ce248 & 0xfffffffc) >> (uRam020ce248 & 3) * 8 |
          *(uint *)(uRam020ce248 & 0xfffffffc) << (uRam020ce248 & 3) * -8 + 0x20;
  iVar12 = 0;
  uVar9 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20)) {
    iVar8 = 0;
    do {
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + iVar12 * 4;
      uVar3 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar10 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
      uVar9 = uVar7 + 0x10 & 3;
      uVar3 = *(uint *)(uVar7 + 0x10 & 0xfffffffc);
      iVar4 = func_020b5ae8(uVar10 + 4,(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + iVar8,
                            uVar2,1,1);
      if (iVar4 != 0) {
        uVar5 = GetB3C4_Cell_RaceS(0x91);
        uVar9 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        *(undefined4 *)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar8 + 8) = uVar5;
        uVar14 = CheckVectorBounds_Clock_Airship(uVar10 + 4);
        uVar6 = (undefined2)((uint6)uVar14 >> 0x20);
        bVar13 = (int)uVar14 != 0;
        if (bVar13) {
          uVar6 = 2;
        }
        uVar9 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        if (!bVar13) {
          uVar6 = 3;
        }
        *(undefined2 *)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar8 + 0xc) = uVar6;
        uVar9 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10;
        uVar3 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        *(undefined2 *)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar8 + 0x10) =
             *(undefined2 *)(uVar10 + 0x7e);
        uVar9 = uVar10 + 0x1c & 3;
        uVar3 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
        uVar7 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
        uVar9 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xc;
        uVar3 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        *(int *)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar11 * 8) =
             (int)((ulonglong)((longlong)iRam020ce24c * (longlong)(int)uVar7) >> 0x20) -
             ((int)uVar7 >> 0x1f);
        iVar8 = iVar8 + 0x14;
        iVar11 = iVar11 + 1;
      }
      uVar7 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar12 = iVar12 + 1;
      uVar9 = uVar7 + 8 & 3;
      uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    } while (iVar12 < (int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20));
  }
  *(int *)(uVar7 + 4) = iVar11;
  return;
}

