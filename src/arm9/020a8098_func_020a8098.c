/* Decompiled C draft; module arm9; ROM address 020a8098. No matching claim. */
#include "types.h"
#include "deps/020a8098_func_020a8098.h"

void func_020a8098(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int local_2c;
  int local_28;
  uint uVar10;
  
  iVar14 = 0;
  if (*(short *)(param_1 + 0x1d0) != 0) {
    iVar12 = 0;
    local_28 = -1;
    local_2c = 1;
    iVar13 = param_1;
    do {
      piVar3 = (int *)func_020d22d0();
      uVar8 = (uint)(piVar3 + 2) & 3;
      uVar9 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
      uVar10 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      uVar7 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
              *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar3 + 1) & 3;
      uVar4 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar7 * (ulonglong)uVar10;
      uVar15 = (uint)lVar2;
      uVar9 = (uint)(piVar3 + 3) & 3;
      uVar11 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
      uVar1 = (uint)(piVar3 + 4) & 3;
      uVar5 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
      uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      uVar1 = (uint)(piVar3 + 5) & 3;
      uVar16 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
      *piVar3 = uVar5 + uVar15;
      piVar3[1] = (uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20) +
                  (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) * uVar7 +
                  uVar10 * (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar5,uVar15);
      uVar8 = (uint)(piVar3 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      iVar6 = (int)((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) >> 0x10) >> 4;
      uVar8 = param_1 + 4U & 3;
      uVar9 = *(uint *)(param_1 + 4U & 0xfffffffc);
      *(uint *)(iVar13 + 0xb0) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      uVar8 = param_1 + 8U & 3;
      uVar9 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(uint *)(iVar13 + 0xb4) = (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + iVar12;
      uVar8 = param_1 + 0xcU & 3;
      uVar9 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(iVar13 + 0xb8) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      uVar8 = (uint)*(short *)(iRam020a8244 + iVar6 * 4);
      *(uint *)(iVar13 + 0xbc) = (uVar8 << 0xd) >> 0xc | (uVar8 >> 0x13) << 0x14;
      *(undefined4 *)(iVar13 + 0xc0) = 0x4000;
      uVar8 = (uint)*(short *)(iRam020a8244 + (iVar6 * 2 + 1) * 2);
      *(uint *)(iVar13 + 0xc4) = (uVar8 << 0xd) >> 0xc | (uVar8 >> 0x13) << 0x14;
      piVar3 = (int *)func_020d22d0();
      uVar8 = (uint)(piVar3 + 2) & 3;
      uVar9 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
      uVar16 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      uVar4 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
              *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar3 + 1) & 3;
      uVar15 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar4 * (ulonglong)uVar16;
      uVar7 = (uint)lVar2;
      uVar9 = (uint)(piVar3 + 3) & 3;
      uVar5 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
      uVar1 = (uint)(piVar3 + 4) & 3;
      uVar10 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
      uVar11 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
      uVar1 = (uint)(piVar3 + 5) & 3;
      uVar10 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
      *piVar3 = uVar11 + uVar7;
      piVar3[1] = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) +
                  (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) * uVar4 +
                  uVar16 * (uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar11,uVar7);
      uVar8 = (uint)(piVar3 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      iVar6 = local_2c;
      if (-1 < (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20)) {
        iVar6 = local_28;
      }
      iVar14 = iVar14 + 1;
      *(int *)(iVar13 + 0xf0) = iVar6 * iRam020a8248;
      iVar13 = iVar13 + 0x48;
      iVar12 = iVar12 + 0x14000;
    } while (iVar14 < (int)(uint)*(ushort *)(param_1 + 0x1d0));
  }
  *(undefined4 *)(param_1 + 0xa8) = 300;
  *(undefined4 *)(param_1 + 0x1fc) = 2;
  return;
}

