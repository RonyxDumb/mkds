/* Decompiled C draft; module arm9; ROM address 020866b4. No matching claim. */
#include "types.h"
#include "deps/020866b4_func_020866b4.h"

void func_020866b4(void)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar13;
  uint uVar14;
  uint uVar7;
  uint uVar12;
  
  uVar5 = uRam02086778;
  uVar4 = uRam02086774;
  iVar10 = (*(uint *)(uRam02086778 & 0xfffffffc) >> (uRam02086778 & 3) * 8 |
           *(uint *)(uRam02086778 & 0xfffffffc) << (uRam02086778 & 3) * -8 + 0x20) + 0x54;
  uVar14 = 1;
  if (1 < *(byte *)((*(uint *)(uRam02086774 & 0xfffffffc) >> (uRam02086774 & 3) * 8 |
                    *(uint *)(uRam02086774 & 0xfffffffc) << (uRam02086774 & 3) * -8 + 0x20) + 0x3d0)
     ) {
    do {
      iVar13 = uVar14 - 1;
      uVar11 = iVar10 + iVar13 * 4;
      uVar7 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar12 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
      uVar11 = iVar10 + uVar14 * 4;
      uVar7 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
      if ((int)uVar11 < (int)uVar12) {
        uVar7 = uVar5 & 3;
        uVar6 = *(uint *)(uVar5 & 0xfffffffc);
        uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
        iVar1 = uVar14 * 2;
        *(uint *)(iVar10 + iVar13 * 4) = uVar11;
        *(uint *)(iVar10 + uVar14 * 4) = uVar12;
        iVar9 = uVar7 + 0x44;
        iVar8 = uVar7 + 0x34;
        iVar13 = iVar13 * 2;
        iVar2 = (uint)*(ushort *)(iVar9 + iVar1) * 2;
        *(short *)(iVar8 + iVar2) = *(short *)(iVar8 + iVar2) + -1;
        iVar2 = (uint)*(ushort *)(iVar9 + iVar13) * 2;
        *(short *)(iVar8 + iVar2) = *(short *)(iVar8 + iVar2) + 1;
        uVar3 = *(undefined2 *)(iVar9 + iVar1);
        *(undefined2 *)(iVar9 + iVar1) = *(undefined2 *)(iVar9 + iVar13);
        *(undefined2 *)(iVar9 + iVar13) = uVar3;
      }
      uVar11 = uVar4 & 3;
      uVar7 = *(uint *)(uVar4 & 0xfffffffc);
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < *(byte *)((uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) + 0x3d0));
    return;
  }
  return;
}

