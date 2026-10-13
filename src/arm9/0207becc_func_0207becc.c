/* Decompiled C draft; module arm9; ROM address 0207becc. No matching claim. */
#include "types.h"
#include "deps/0207becc_func_0207becc.h"

void func_0207becc(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar14;
  uint uVar11;
  uint uVar13;
  
  uVar9 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207bfa4 & 0xfffffffc) >> (uRam0207bfa4 & 3) * 8 |
          *(uint *)(uRam0207bfa4 & 0xfffffffc) << (uRam0207bfa4 & 3) * -8 + 0x20) + 0x58;
  uVar3 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) * 0xc +
       (*(uint *)(uRam0207bfa8 & 0xfffffffc) >> (uRam0207bfa8 & 3) * 8 |
       *(uint *)(uRam0207bfa8 & 0xfffffffc) << (uRam0207bfa8 & 3) * -8 + 0x20);
  *(undefined4 *)(param_1 + 0xc) = 0;
  uVar9 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar9 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  if (uVar9 != 0) {
    uVar9 = (uint)*(ushort *)(uVar9 + 10);
    piVar4 = (int *)func_0208537c();
    if (uVar9 == 0) {
      sVar8 = 0;
    }
    else {
      uVar3 = (uint)(piVar4 + 2) & 3;
      uVar10 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      uVar7 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
              *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      uVar3 = (uint)(piVar4 + 1) & 3;
      uVar5 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar7 * (ulonglong)uVar11;
      uVar14 = (uint)lVar2;
      uVar10 = (uint)(piVar4 + 3) & 3;
      uVar6 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar1 = (uint)(piVar4 + 4) & 3;
      uVar12 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      uVar13 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
      uVar1 = (uint)(piVar4 + 5) & 3;
      uVar12 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      *piVar4 = uVar13 + uVar14;
      piVar4[1] = (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20) +
                  (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) * uVar7 +
                  uVar11 * (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
      if (uVar9 == 0) {
        uVar3 = (uint)(piVar4 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
        uVar13 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
      }
      sVar8 = (short)uVar13;
      if (uVar9 != 0) {
        uVar3 = (uint)(piVar4 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
        sVar8 = (short)((ulonglong)uVar9 *
                        (ulonglong)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) >> 0x20);
      }
    }
    uVar9 = param_1 + 8U & 3;
    uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(short *)(param_1 + 2) =
         *(short *)((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + 8) + sVar8;
    return;
  }
  return;
}

