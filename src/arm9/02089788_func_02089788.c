/* Decompiled C draft; module arm9; ROM address 02089788. No matching claim. */
#include "types.h"
#include "deps/02089788_func_02089788.h"

void func_02089788(int *param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  undefined2 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  int *piVar6;
  uint uVar17;
  
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0x74);
  *(ushort *)((int)param_1 + 6) = *(ushort *)(param_1 + 1) & 3;
  func_02080908(param_1 + 10,param_2 + 0x80,param_2 + 0x138,*(undefined2 *)(param_2 + 0x74));
  uVar5 = (uint)(param_1 + 10) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  piVar6 = (int *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
  iVar7 = piVar6[1];
  iVar10 = piVar6[2];
  param_1[0x11] = *piVar6;
  param_1[0x12] = iVar7;
  param_1[0x13] = iVar10;
  func_020898bc((int)(uintptr_t)(param_1));
  uVar5 = (*(uint *)(uRam020898b4 & 0xfffffffc) >> (uRam020898b4 & 3) * 8 |
          *(uint *)(uRam020898b4 & 0xfffffffc) << (uRam020898b4 & 3) * -8 + 0x20) + 0x18;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
    *(undefined2 *)(param_1 + 0x30) = 0;
    return;
  }
  iVar10 = 0;
  uVar3 = uRam020898b8 & 3;
  uVar15 = *(uint *)(uRam020898b8 & 0xfffffffc);
  piVar6 = (int *)func_0208537c();
  uVar5 = (uint)(piVar6 + 2) & 3;
  uVar4 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
  uVar13 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar11 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
           *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
  uVar5 = (uint)(piVar6 + 1) & 3;
  uVar8 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
  lVar2 = (ulonglong)uVar11 * (ulonglong)uVar13;
  uVar18 = (uint)lVar2;
  uVar4 = (uint)(piVar6 + 3) & 3;
  uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
  uVar1 = (uint)(piVar6 + 4) & 3;
  uVar16 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
  uVar17 = uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(piVar6 + 5) & 3;
  uVar16 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
  *piVar6 = uVar17 + uVar18;
  piVar6[1] = (uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20) +
              (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) * uVar11 +
              uVar13 * (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) +
              (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar17,uVar18);
  uVar5 = (uint)(piVar6 + 1) & 3;
  uVar4 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
  iVar12 = 0;
  iVar7 = (int)(short)((ushort)((ushort)((uVar4 >> uVar5 * 8) >> 0x10) |
                               (ushort)((uVar4 << uVar5 * -8 + 0x20) >> 0x10)) >> 4);
  do {
    uVar5 = (uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) + iVar12 * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (0 < (int)uVar5) {
      if (iVar7 <= (int)uVar5) {
        iVar10 = (iVar12 + 1) * 0x10000 >> 0x10;
      }
      uVar14 = (undefined2)iVar10;
      if (iVar7 <= (int)uVar5) break;
    }
    uVar14 = (undefined2)iVar10;
    iVar12 = (iVar12 + 1) * 0x10000 >> 0x10;
  } while (iVar12 < 3);
  *(undefined2 *)(param_1 + 0x30) = uVar14;
  return;
}

