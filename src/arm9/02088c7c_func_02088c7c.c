/* Decompiled C draft; module arm9; ROM address 02088c7c. No matching claim. */
#include "types.h"
#include "deps/02088c7c_func_02088c7c.h"

void func_02088c7c(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  uint uVar18;
  uint uVar13;
  uint uVar17;
  
  uVar4 = uRam02088d30 & 3;
  uVar5 = *(uint *)(uRam02088d30 & 0xfffffffc);
  iVar15 = 0;
  piVar6 = (int *)func_0208537c();
  uVar7 = (uint)(piVar6 + 2) & 3;
  uVar12 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
  uVar13 = uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20;
  uVar10 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
           *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
  uVar7 = (uint)(piVar6 + 1) & 3;
  uVar8 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
  lVar3 = (ulonglong)uVar10 * (ulonglong)uVar13;
  uVar18 = (uint)lVar3;
  uVar12 = (uint)(piVar6 + 3) & 3;
  uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
  uVar2 = (uint)(piVar6 + 4) & 3;
  uVar16 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
  uVar17 = uVar16 >> uVar2 * 8 | uVar16 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(piVar6 + 5) & 3;
  uVar16 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
  *piVar6 = uVar17 + uVar18;
  piVar6[1] = (uVar16 >> uVar2 * 8 | uVar16 << uVar2 * -8 + 0x20) +
              (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) * uVar10 +
              uVar13 * (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) +
              (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar17,uVar18);
  uVar7 = (uint)(piVar6 + 1) & 3;
  uVar12 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
  iVar11 = 0;
  iVar1 = (int)(short)((ushort)((ushort)((uVar12 >> uVar7 * 8) >> 0x10) |
                               (ushort)((uVar12 << uVar7 * -8 + 0x20) >> 0x10)) >> 4);
  do {
    uVar7 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0xc + iVar11 * 4;
    uVar12 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
    if (0 < (int)uVar7) {
      if (iVar1 <= (int)uVar7) {
        iVar15 = (iVar11 + 1) * 0x10000 >> 0x10;
      }
      uVar14 = (undefined2)iVar15;
      if (iVar1 <= (int)uVar7) break;
    }
    uVar14 = (undefined2)iVar15;
    iVar11 = (iVar11 + 1) * 0x10000 >> 0x10;
  } while (iVar11 < 3);
  *(undefined2 *)(param_1 + 0xc0) = uVar14;
  return;
}

