/* Decompiled C draft; module arm9; ROM address 0207e088. No matching claim. */
#include "types.h"
#include "deps/0207e088_func_0207e088.h"

void func_0207e088(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint uVar17;
  uint uVar15;
  uint uVar18;
  
  uVar9 = (uint)*(ushort *)(param_2 + 4) * 0x30 +
          (*(uint *)(uRam0207e1c8 & 0xfffffffc) >> (uRam0207e1c8 & 3) * 8 |
          *(uint *)(uRam0207e1c8 & 0xfffffffc) << (uRam0207e1c8 & 3) * -8 + 0x20) + 0x70;
  uVar14 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20;
  bVar12 = false;
  if ((uVar9 < 4) && ((1 << (uVar9 & 0xff) & 0xdU) != 0)) {
    bVar12 = true;
  }
  if (bVar12) {
    return;
  }
  bVar12 = false;
  piVar4 = (int *)func_0208537c();
  uVar9 = (uint)(piVar4 + 2) & 3;
  uVar14 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
  uVar15 = uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20;
  uVar13 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
           *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
  uVar9 = (uint)(piVar4 + 1) & 3;
  uVar10 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  lVar2 = (ulonglong)uVar13 * (ulonglong)uVar15;
  uVar16 = (uint)lVar2;
  uVar14 = (uint)(piVar4 + 3) & 3;
  uVar11 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
  uVar1 = (uint)(piVar4 + 4) & 3;
  uVar17 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar18 = uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20;
  uVar1 = (uint)(piVar4 + 5) & 3;
  uVar17 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
  *piVar4 = uVar18 + uVar16;
  piVar4[1] = (uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20) +
              (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) * uVar13 +
              uVar15 * (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) +
              (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar18,uVar16);
  uVar9 = (uint)(piVar4 + 1) & 3;
  uVar14 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  iVar8 = (int)(short)((ushort)((ushort)((uVar14 >> uVar9 * 8) >> 0x10) |
                               (ushort)((uVar14 << uVar9 * -8 + 0x20) >> 0x10)) >> 4);
  iVar5 = func_020853f0(*(undefined2 *)(param_2 + 4));
  iVar6 = GetDriverEntry(*(undefined2 *)(param_2 + 4));
  uVar9 = iVar6 + 0x310U & 3;
  uVar14 = *(uint *)(iVar6 + 0x310U & 0xfffffffc);
  uVar14 = uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20;
  uVar9 = uVar14 + 0x154;
  uVar1 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (uVar9 >> uVar1 * 8 != 0 || uVar9 << uVar1 * -8 + 0x20 != 0) {
    iVar5 = 0;
  }
  uVar9 = (*(uint *)(uRam0207e1cc & 0xfffffffc) >> (uRam0207e1cc & 3) * 8 |
          *(uint *)(uRam0207e1cc & 0xfffffffc) << (uRam0207e1cc & 3) * -8 + 0x20) + iVar5 * 4;
  uVar1 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  if ((iVar8 < (int)uVar9) || (0xfff < (int)uVar9)) {
    *(undefined4 *)(param_1 + 0x2c) = 1;
    uVar14 = uVar14 + 0x154;
    uVar9 = uVar14 & 3;
    uVar14 = *(uint *)(uVar14 & 0xfffffffc);
    uVar3 = SomeCpuModeStuff(uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20);
    *(undefined2 *)(param_1 + 0x30) = uVar3;
    bVar12 = true;
  }
  if (!bVar12) {
    uVar9 = (*(uint *)(uRam0207e1d0 & 0xfffffffc) >> (uRam0207e1d0 & 3) * 8 |
            *(uint *)(uRam0207e1d0 & 0xfffffffc) << (uRam0207e1d0 & 3) * -8 + 0x20) + iVar5 * 4;
    uVar14 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    if ((int)(uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) <= iVar8) {
      uVar7 = FUN_02132440();
      iVar8 = FUN_0213189c(uVar7,0x3f800000);
      if (iVar8 == 0) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x28) = 1;
    return;
  }
  return;
}

