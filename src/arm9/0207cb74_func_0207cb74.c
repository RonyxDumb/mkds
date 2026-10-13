/* Decompiled C draft; module arm9; ROM address 0207cb74. No matching claim. */
#include "types.h"
#include "deps/0207cb74_func_0207cb74.h"

void func_0207cb74(short *param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  uint uVar12;
  uint uVar14;
  uint uVar11;
  uint uVar13;
  
  *param_1 = *param_1 + -1;
  if (0 < *param_1) {
    return;
  }
  *param_1 = 0;
  uVar4 = param_2 + 0x70 & 3;
  uVar3 = *(uint *)(param_2 + 0x70 & 0xfffffffc);
  if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 0x14000) {
    uVar4 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    func_0204360c(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,0x600);
    param_1[8] = 0;
    param_1[9] = 0;
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 == 0) {
      return;
    }
    uVar4 = (uint)*(ushort *)(uVar4 + 10);
    piVar5 = (int *)func_0208537c();
    if (uVar4 == 0) {
      sVar9 = 0;
    }
    else {
      uVar3 = (uint)(piVar5 + 2) & 3;
      uVar10 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      uVar8 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar3 = (uint)(piVar5 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar8 * (ulonglong)uVar11;
      uVar14 = (uint)lVar2;
      uVar10 = (uint)(piVar5 + 3) & 3;
      uVar7 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar1 = (uint)(piVar5 + 4) & 3;
      uVar12 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
      uVar1 = (uint)(piVar5 + 5) & 3;
      uVar12 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar13 + uVar14;
      piVar5[1] = (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) +
                  (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) * uVar8 +
                  uVar11 * (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
      if (uVar4 == 0) {
        uVar3 = (uint)(piVar5 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        uVar13 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      }
      sVar9 = (short)uVar13;
      if (uVar4 != 0) {
        uVar3 = (uint)(piVar5 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        sVar9 = (short)((ulonglong)uVar4 *
                        (ulonglong)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) >> 0x20);
      }
    }
    uVar4 = (uint)(param_1 + 2) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    *param_1 = *(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 8) + sVar9;
    return;
  }
  return;
}

