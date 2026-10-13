/* Decompiled C draft; module arm9; ROM address 02089a24. No matching claim. */
#include "types.h"
#include "deps/02089a24_func_02089a24.h"

void func_02089a24(int param_1,int param_2)

{
  longlong lVar1;
  bool bVar2;
  undefined2 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  uint uVar14;
  
  bVar2 = false;
  *(undefined4 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *(undefined2 *)(param_2 + 0x30) = 0;
  uVar10 = *(uint *)(uRam02089b3c & 0xfffffffc) >> (uRam02089b3c & 3) * 8 |
           *(uint *)(uRam02089b3c & 0xfffffffc) << (uRam02089b3c & 3) * -8 + 0x20;
  uVar5 = (uint)*(ushort *)(param_1 + 4) * 0x30 + uVar10 + 0x70;
  uVar13 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
  if ((uVar5 < 4) && ((1 << (uVar5 & 0xff) & 0xdU) != 0)) {
    bVar2 = true;
  }
  if (bVar2) {
    return;
  }
  uVar10 = uVar10 + 0x18;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) != 1) {
    return;
  }
  piVar4 = (int *)func_0208537c();
  uVar5 = (uint)(piVar4 + 2) & 3;
  uVar10 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
  uVar11 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20;
  uVar8 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
          *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
  uVar5 = (uint)(piVar4 + 1) & 3;
  uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  lVar1 = (ulonglong)uVar8 * (ulonglong)uVar11;
  uVar15 = (uint)lVar1;
  uVar10 = (uint)(piVar4 + 4) & 3;
  uVar13 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar14 = uVar13 >> uVar10 * 8 | uVar13 << uVar10 * -8 + 0x20;
  uVar10 = (uint)(piVar4 + 3) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
  uVar13 = (uint)(piVar4 + 5) & 3;
  uVar12 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
  *piVar4 = uVar14 + uVar15;
  piVar4[1] = (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) +
              (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) * uVar8 +
              uVar11 * (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
              (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar15);
  uVar10 = (uint)(piVar4 + 1) & 3;
  uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)(uRam02089b3c & 0xfffffffc) >> (uRam02089b3c & 3) * 8 |
          *(uint *)(uRam02089b3c & 0xfffffffc) << (uRam02089b3c & 3) * -8 + 0x20) + 0x14;
  uVar13 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
  iVar9 = iRam02089b48;
  if ((uVar5 != 2) && (iVar9 = iRam02089b40, uVar5 == 3)) {
    iVar9 = iRam02089b44;
  }
  if (iVar9 < (short)((ushort)((ushort)((uVar6 >> uVar10 * 8) >> 0x10) |
                              (ushort)((uVar6 << uVar10 * -8 + 0x20) >> 0x10)) >> 4)) {
    return;
  }
  *(undefined4 *)(param_2 + 0x2c) = 1;
  uVar3 = SomeCpuModeStuff(0);
  *(undefined2 *)(param_2 + 0x30) = uVar3;
  return;
}

