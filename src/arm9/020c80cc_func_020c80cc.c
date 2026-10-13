/* Decompiled C draft; module arm9; ROM address 020c80cc. No matching claim. */
#include "types.h"
#include "deps/020c80cc_func_020c80cc.h"

void func_020c80cc(void)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar12;
  int iVar13;
  bool bVar14;
  undefined6 uVar15;
  ushort *local_2c [2];
  ushort *puVar11;
  
  iVar12 = 0;
  uVar3 = func_020c0db0();
  uVar2 = uRam020c8234;
  uVar8 = *(uint *)(uRam020c8234 & 0xfffffffc) >> (uRam020c8234 & 3) * 8 |
          *(uint *)(uRam020c8234 & 0xfffffffc) << (uRam020c8234 & 3) * -8 + 0x20;
  iVar13 = 0;
  uVar10 = uVar8 + 8 & 3;
  uVar4 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (0 < (int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20)) {
    iVar9 = 0;
    do {
      uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      uVar10 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
               *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar13 * 4;
      uVar4 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      puVar11 = (ushort *)(uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20);
      local_2c[0] = puVar11 + 2;
      uVar10 = uVar8 + 0x10 & 3;
      uVar4 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
      iVar5 = func_020b5ae8((uint)(uintptr_t)(local_2c[0]),(int *)(uintptr_t)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + iVar9),
                            uVar3,1,1);
      if (iVar5 != 0) {
        uVar10 = (uint)*puVar11;
        uVar1 = puVar11[0x3f];
        if (uVar10 == uRam020c8238) {
          uVar6 = GetB3C4_Cell_RaceS(0x93);
          uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar4 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          *(undefined4 *)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + iVar9 + 8) = uVar6;
        }
        else if (uVar10 == uRam020c823c) {
          uVar6 = GetB3C4_Cell_RaceS(puVar11[0x98] + 0x95);
          uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar4 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          *(undefined4 *)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + iVar9 + 8) = uVar6;
        }
        else if (uVar10 == 0x19c) {
          uVar6 = GetB3C4_Cell_RaceS(0x94);
          uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar4 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          *(undefined4 *)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + iVar9 + 8) = uVar6;
        }
        uVar15 = CheckVectorBounds_Clock_Airship((uint)(uintptr_t)(local_2c));
        uVar7 = (undefined2)((uint6)uVar15 >> 0x20);
        bVar14 = (int)uVar15 != 0;
        if (bVar14) {
          uVar7 = 2;
        }
        uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
        uVar4 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        if (!bVar14) {
          uVar7 = 3;
        }
        *(undefined2 *)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + iVar9 + 0xc) = uVar7;
        iVar12 = iVar12 + 1;
        uVar10 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
        uVar4 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        *(ushort *)((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) + iVar9 + 0x10) = uVar1;
        iVar9 = iVar9 + 0x14;
      }
      uVar8 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      iVar13 = iVar13 + 1;
      uVar10 = uVar8 + 8 & 3;
      uVar4 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    } while (iVar13 < (int)(uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar12;
  return;
}

