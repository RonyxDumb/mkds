/* Decompiled C draft; module arm9; ROM address 0211756c. No matching claim. */
#include "types.h"
#include "deps/0211756c_func_0211756c.h"

void func_0211756c(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  short sVar5;
  short sVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  int local_20;
  
  piVar3 = piRam021176d8;
  *(int *)(*piRam021176d8 + 0x38) = *(int *)(*piRam021176d8 + 0x38) + 1;
  if (*psRam021176dc != 2) {
    uVar1 = *(ushort *)(*(int *)(*piVar3 + 4) + 6);
    sVar5 = ComputeValueInterpolation_from_thumb(1,0,0xe0,*(undefined4 *)(*piVar3 + 0x38),10);
    uVar7 = ComputeValueInterpolation_from_thumb
                      (1,0,0xffffff40,*(undefined4 *)(*piRam021176d8 + 0x38),10);
    iVar9 = *piRam021176d8;
    uVar2 = (undefined2)uVar7;
    if (((*(int *)(iVar9 + 0x88) == 2) || (*(int *)(iVar9 + 0x88) == 3)) ||
       (*(int *)(iVar9 + 0x3c) == 0)) {
      *(undefined4 *)(iVar9 + 0x40) = uVar7;
      piVar3 = piRam021176d8;
      *(undefined2 *)(*(int *)(*piRam021176d8 + 0x18) + iRam021176e0) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = uVar2;
      iVar9 = 0;
      puVar10 = puRam021176e4;
      do {
        *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar10 * 0x40 + 6) = uVar2;
        piVar4 = piRam021176d8;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 8);
      iVar9 = 0;
      puVar10 = puRam021176e8;
      do {
        *(undefined2 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar10 * 0x40 + 6) = uVar2;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
      iVar9 = 0;
      puVar10 = puRam021176f0;
      puVar11 = puRam021176ec;
      do {
        *(undefined2 *)(*(int *)(*piRam021176d8 + 0x18) + (uint)*puVar11 * 0x40 + 6) = uVar2;
        *(undefined2 *)(*(int *)(*piRam021176d8 + 0x18) + ((uint)uVar1 + (uint)*puVar10) * 0x40 + 6)
             = uVar2;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
    }
    piVar3 = piRam021176d8;
    *(undefined2 *)(*(int *)(*piRam021176d8 + 0x18) + iRam021176f4) = uVar2;
    sVar6 = -sVar5;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 4) = sVar6;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0x44) = sVar5;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0x84) = sVar6;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0xc4) = sVar5;
    local_20 = 0;
    puVar10 = puRam021176f8;
    do {
      iVar9 = 0;
      puVar11 = puVar10;
      do {
        *(short *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar11 * 0x40 + 4) = sVar6;
        piVar4 = piRam021176d8;
        puVar11 = puVar11 + 1;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 6);
      puVar10 = puVar10 + 6;
      local_20 = local_20 + 1;
    } while (local_20 < 4);
    iVar9 = 4;
    puVar10 = puRam021176fc;
    do {
      iVar8 = 0;
      puVar11 = puVar10;
      do {
        *(short *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar11 * 0x40 + 4) = sVar5;
        puVar11 = puVar11 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 6);
      puVar10 = puVar10 + 6;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 8);
  }
  return;
}

