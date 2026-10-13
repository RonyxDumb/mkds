/* Decompiled C draft; module arm9; ROM address 02091fd8. No matching claim. */
#include "types.h"
#include "deps/02091fd8_func_02091fd8.h"

void func_02091fd8(uint param_1)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar14;
  uint uVar8;
  uint uVar13;
  
  if (param_1 == 0) {
    return;
  }
  iVar11 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar11) {
      return;
    }
    uVar10 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar11 * 4;
    uVar1 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20;
    if (uVar10 == 0) break;
    if ((*(ushort *)(uVar10 + 2) & 0x800) != 0) {
      piVar3 = (int *)func_020d22d0();
      uVar1 = (uint)(piVar3 + 2) & 3;
      uVar7 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
      uVar8 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
      uVar6 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
              *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
      uVar1 = (uint)(piVar3 + 1) & 3;
      uVar4 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar6 * (ulonglong)uVar8;
      uVar14 = (uint)lVar2;
      uVar7 = (uint)(piVar3 + 4) & 3;
      uVar12 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
      uVar13 = uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20;
      uVar7 = (uint)(piVar3 + 3) & 3;
      uVar5 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
      uVar12 = (uint)(piVar3 + 5) & 3;
      uVar9 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
      *piVar3 = uVar13 + uVar14;
      piVar3[1] = (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) +
                  (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * uVar6 +
                  uVar8 * (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar14);
      uVar1 = (uint)(piVar3 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
      *(int *)(uVar10 + 0xa4) =
           (int)((ulonglong)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) * 0x19 >> 0x20) + 200;
    }
    iVar11 = iVar11 + 1;
  }
  return;
}

