/* Decompiled C draft; module arm9; ROM address 0209af98. No matching claim. */
#include "types.h"
#include "deps/0209af98_func_0209af98.h"

void func_0209af98(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar16;
  uint uVar15;
  
  uVar4 = uRam0209b084;
  uVar3 = uRam0209b080;
  if (param_1 == 0) {
    return;
  }
  iVar13 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar13) {
      return;
    }
    uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar12 = uVar6 + iVar13 * 4;
    uVar1 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar12 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    if (uVar12 == 0) break;
    *(undefined2 *)(uVar12 + 0xd0) = 0;
    *(undefined4 *)(uVar12 + 0xdc) = 0;
    *(undefined4 *)(uVar12 + 0xe0) = uVar3;
    *(undefined4 *)(uVar12 + 0xe4) = 0;
    *(undefined4 *)(uVar12 + 0xe8) = uVar4;
    *(undefined4 *)(uVar12 + 0xec) = 0;
    piVar5 = (int *)func_020d22d0(uVar6,param_2,param_3);
    uVar1 = (uint)(piVar5 + 2) & 3;
    uVar6 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
    uVar10 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    uVar9 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
            *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
    uVar1 = (uint)(piVar5 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar9 * (ulonglong)uVar10;
    uVar16 = (uint)lVar2;
    uVar6 = (uint)(piVar5 + 4) & 3;
    uVar14 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
    uVar15 = uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20;
    uVar6 = (uint)(piVar5 + 3) & 3;
    uVar8 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
    uVar14 = (uint)(piVar5 + 5) & 3;
    uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
    *piVar5 = uVar15 + uVar16;
    piVar5[1] = (uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20) +
                (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * uVar9 +
                uVar10 * (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar16);
    uVar1 = (uint)(piVar5 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    param_2 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    param_3 = (undefined4)((ulonglong)param_2 * 0x3c);
    *(int *)(uVar12 + 0xa4) = (int)((ulonglong)param_2 * 0x3c >> 0x20) + 0x1e;
    *(undefined4 *)(uVar12 + 0x114) = 0;
    iVar13 = iVar13 + 1;
  }
  return;
}

