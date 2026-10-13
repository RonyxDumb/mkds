/* Decompiled C draft; module arm9; ROM address 0207c144. No matching claim. */
#include "types.h"
#include "deps/0207c144_func_0207c144.h"

void func_0207c144(short *param_1,int param_2)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar14;
  uint uVar9;
  uint uVar13;
  
  uVar7 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207c268 & 0xfffffffc) >> (uRam0207c268 & 3) * 8 |
          *(uint *)(uRam0207c268 & 0xfffffffc) << (uRam0207c268 & 3) * -8 + 0x20) + 0x30;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(param_1 + 2) =
       (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * 0xc +
       (*(uint *)(uRam0207c26c & 0xfffffffc) >> (uRam0207c26c & 3) * 8 |
       *(uint *)(uRam0207c26c & 0xfffffffc) << (uRam0207c26c & 3) * -8 + 0x20);
  piVar2 = (int *)func_0208537c();
  uVar7 = (uint)(piVar2 + 2) & 3;
  uVar8 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
  uVar9 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar5 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
          *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
  uVar7 = (uint)(piVar2 + 1) & 3;
  uVar3 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
  lVar1 = (ulonglong)uVar5 * (ulonglong)uVar9;
  uVar11 = (uint)lVar1;
  uVar8 = (uint)(piVar2 + 3) & 3;
  uVar4 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
  uVar10 = (uint)(piVar2 + 4) & 3;
  uVar12 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
  uVar13 = uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20;
  uVar10 = (uint)(piVar2 + 5) & 3;
  uVar12 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
  *piVar2 = uVar13 + uVar11;
  piVar2[1] = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) +
              (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) * uVar5 +
              uVar9 * (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) +
              (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar11);
  uVar7 = (uint)(piVar2 + 1) & 3;
  uVar8 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
  *(int *)(param_1 + 0x10) =
       (int)(short)((ushort)((ushort)((uVar8 >> uVar7 * 8) >> 0x10) |
                            (ushort)((uVar8 << uVar7 * -8 + 0x20) >> 0x10)) >> 4);
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  if (uVar7 != 0) {
    uVar7 = (uint)*(ushort *)(uVar7 + 10);
    piVar2 = (int *)func_0208537c();
    if (uVar7 == 0) {
      sVar6 = 0;
    }
    else {
      uVar8 = (uint)(piVar2 + 2) & 3;
      uVar10 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
      uVar11 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
      uVar12 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
               *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar2 + 1) & 3;
      uVar4 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar12 * (ulonglong)uVar11;
      uVar14 = (uint)lVar1;
      uVar10 = (uint)(piVar2 + 3) & 3;
      uVar5 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
      uVar3 = (uint)(piVar2 + 4) & 3;
      uVar9 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
      uVar13 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
      uVar3 = (uint)(piVar2 + 5) & 3;
      uVar9 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
      *piVar2 = uVar13 + uVar14;
      piVar2[1] = (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                  (uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) * uVar12 +
                  uVar11 * (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
      if (uVar7 == 0) {
        uVar8 = (uint)(piVar2 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
        uVar13 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
      }
      sVar6 = (short)uVar13;
      if (uVar7 != 0) {
        uVar8 = (uint)(piVar2 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
        sVar6 = (short)((ulonglong)uVar7 *
                        (ulonglong)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) >> 0x20);
      }
    }
    uVar7 = (uint)(param_1 + 2) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    *param_1 = *(short *)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 8) + sVar6;
    return;
  }
  return;
}

