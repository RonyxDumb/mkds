/* Decompiled C draft; module arm9; ROM address 020968f4. No matching claim. */
#include "types.h"
#include "deps/020968f4_func_020968f4.h"

void func_020968f4(uint param_1)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
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
    uVar3 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
    if (uVar10 == 0) break;
    *(undefined4 *)(uVar10 + 0xa8) = 0x1000;
    piVar2 = (int *)func_020d22d0();
    uVar3 = (uint)(piVar2 + 2) & 3;
    uVar12 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
    uVar13 = uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20;
    uVar5 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
            *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar2 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar13;
    uVar4 = (uint)lVar1;
    uVar12 = (uint)(piVar2 + 4) & 3;
    uVar7 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
    uVar8 = uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20;
    uVar12 = (uint)(piVar2 + 5) & 3;
    uVar14 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
    uVar7 = (uint)(piVar2 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
    *piVar2 = uVar8 + uVar4;
    piVar2[1] = (uVar14 >> uVar12 * 8 | uVar14 << uVar12 * -8 + 0x20) +
                (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) * uVar5 +
                uVar13 * (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar8,uVar4);
    uVar3 = uVar10 + 0x9c & 3;
    uVar7 = *(uint *)(uVar10 + 0x9c & 0xfffffffc);
    uVar12 = (uint)(piVar2 + 1) & 3;
    uVar4 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    *(uint *)(uVar10 + 0xac) =
         ((int)*(short *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x28) +
         (int)((ulonglong)(uVar4 >> uVar12 * 8 | uVar4 << uVar12 * -8 + 0x20) * 0x3c >> 0x20)) -
         0x1eU & 0xffff;
    iVar11 = iVar11 + 1;
    uVar3 = (*(uint *)(uRam02096a00 & 0xfffffffc) >> (uRam02096a00 & 3) * 8 |
            *(uint *)(uRam02096a00 & 0xfffffffc) << (uRam02096a00 & 3) * -8 + 0x20) + 8;
    uVar12 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) == 4) {
      *(undefined4 *)(uVar10 + 0xb0) = 3;
      *(undefined4 *)(uVar10 + 0xa0) = 0x2000;
      *(undefined4 *)(uVar10 + 0xa4) = 0xffff3000;
    }
    else {
      *(undefined4 *)(uVar10 + 0xb0) = 0;
      *(undefined4 *)(uVar10 + 0xa0) = 0x2000;
      *(undefined4 *)(uVar10 + 0xa4) = 0xffff3000;
    }
  }
  return;
}

