/* Decompiled C draft; module arm9; ROM address 02117bf8. No matching claim. */
#include "types.h"
#include "deps/02117bf8_func_02117bf8.h"

void func_02117bf8(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  short sVar5;
  short sVar6;
  undefined4 uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  ushort *puVar11;
  int local_20;
  
  piVar3 = piRam02117d70;
  *(int *)(*piRam02117d70 + 0x38) = *(int *)(*piRam02117d70 + 0x38) + 1;
  if (*psRam02117d74 != 2) {
    uVar1 = *(ushort *)(*(int *)(*piVar3 + 4) + 6);
    sVar5 = ComputeValueInterpolation_from_thumb(1,0xe0,0,*(undefined4 *)(*piVar3 + 0x38),10);
    uVar7 = ComputeValueInterpolation_from_thumb
                      (1,0xffffff40,0,*(undefined4 *)(*piRam02117d70 + 0x38),10);
    iVar8 = func_020cccb4();
    uVar2 = (undefined2)uVar7;
    if ((iVar8 != 0x18) && (iVar8 = func_020cccb4(), piVar3 = piRam02117d70, iVar8 != 0xc)) {
      *(undefined4 *)(*piRam02117d70 + 0x40) = uVar7;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam02117d78) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = uVar2;
      iVar8 = 0;
      puVar9 = puRam02117d7c;
      do {
        *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar9 * 0x40 + 6) = uVar2;
        piVar4 = piRam02117d70;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 8);
      iVar8 = 0;
      puVar9 = puRam02117d80;
      do {
        *(undefined2 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar9 * 0x40 + 6) = uVar2;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
      iVar8 = 0;
      puVar9 = puRam02117d88;
      puVar11 = puRam02117d84;
      do {
        *(undefined2 *)(*(int *)(*piRam02117d70 + 0x18) + (uint)*puVar11 * 0x40 + 6) = uVar2;
        *(undefined2 *)(*(int *)(*piRam02117d70 + 0x18) + ((uint)uVar1 + (uint)*puVar9) * 0x40 + 6)
             = uVar2;
        puVar11 = puVar11 + 1;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 4);
    }
    piVar3 = piRam02117d70;
    *(undefined2 *)(*(int *)(*piRam02117d70 + 0x18) + iRam02117d8c) = uVar2;
    sVar6 = -sVar5;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 4) = sVar6;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0x44) = sVar5;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0x84) = sVar6;
    *(short *)(*(int *)(*piVar3 + 0x1c) + 0xc4) = sVar5;
    local_20 = 0;
    puVar9 = puRam02117d90;
    do {
      iVar8 = 0;
      puVar11 = puVar9;
      do {
        *(short *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar11 * 0x40 + 4) = sVar6;
        piVar4 = piRam02117d70;
        puVar11 = puVar11 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 6);
      puVar9 = puVar9 + 6;
      local_20 = local_20 + 1;
    } while (local_20 < 4);
    iVar8 = 4;
    puVar9 = puRam02117d94;
    do {
      iVar10 = 0;
      puVar11 = puVar9;
      do {
        *(short *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar11 * 0x40 + 4) = sVar5;
        puVar11 = puVar11 + 1;
        iVar10 = iVar10 + 1;
      } while (iVar10 < 6);
      puVar9 = puVar9 + 6;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
  }
  if (9 < *(int *)(*piRam02117d70 + 0x38)) {
    func_021181cc();
  }
  return;
}

