/* Decompiled C draft; module arm9; ROM address 020ffdd4. No matching claim. */
#include "types.h"
#include "deps/020ffdd4_func_020ffdd4.h"

void func_020ffdd4(uint param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar16;
  uint uVar17;
  uint uVar11;
  uint uVar15;
  
  uVar12 = (uint)*(ushort *)(param_1 + 4);
  uVar13 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar6 = 0;
  if (uVar12 != 0) {
    do {
      uVar4 = uVar13 + iVar6 * 4;
      uVar10 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (*(short *)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) + 0x8e) != 1) {
        return;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar12);
  }
  piVar5 = (int *)func_020d22d0();
  uVar4 = (uint)(piVar5 + 2) & 3;
  uVar10 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
  uVar11 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
  uVar9 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
          *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
  uVar4 = (uint)(piVar5 + 1) & 3;
  uVar7 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
  lVar3 = (ulonglong)uVar9 * (ulonglong)uVar11;
  uVar17 = (uint)lVar3;
  uVar10 = (uint)(piVar5 + 3) & 3;
  uVar8 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
  uVar2 = (uint)(piVar5 + 4) & 3;
  uVar14 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
  uVar15 = uVar14 >> uVar2 * 8 | uVar14 << uVar2 * -8 + 0x20;
  uVar2 = (uint)(piVar5 + 5) & 3;
  uVar14 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
  *piVar5 = uVar15 + uVar17;
  piVar5[1] = (uVar14 >> uVar2 * 8 | uVar14 << uVar2 * -8 + 0x20) +
              (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) * uVar9 +
              uVar11 * (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
              (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar15,uVar17);
  uVar4 = (uint)(piVar5 + 1) & 3;
  uVar10 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
  iVar6 = 0;
  if (uVar12 != 0) {
    iVar16 = (int)((ulonglong)(uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) * 6 >> 0x20) * 6 +
             iRam020ffeb4;
    do {
      iVar1 = iVar6 * 2;
      uVar4 = uVar13 + iVar6 * 4;
      uVar10 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20;
      iVar6 = iVar6 + 1;
      *(undefined2 *)(uVar4 + 0xa8) =
           *(undefined2 *)(uVar4 + (uint)*(ushort *)(iVar16 + iVar1) * 2 + 0xb4);
      *(undefined2 *)(uVar4 + 0x90) = 0;
      *(undefined2 *)(uVar4 + 0x92) = 1;
    } while (iVar6 < (int)uVar12);
    return;
  }
  return;
}

