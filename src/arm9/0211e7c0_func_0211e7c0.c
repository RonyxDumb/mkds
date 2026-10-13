/* Decompiled C draft; module arm9; ROM address 0211e7c0. No matching claim. */
#include "types.h"
#include "deps/0211e7c0_func_0211e7c0.h"

void func_0211e7c0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  
  piVar3 = piRam0211e908;
  *(int *)(*piRam0211e908 + 0x34) = *(int *)(*piRam0211e908 + 0x34) + 1;
  if (*psRam0211e90c != 2) {
    uVar5 = ComputeValueInterpolation_from_thumb(1,0,0xc0,*(undefined4 *)(*piVar3 + 0x34),10);
    uVar6 = ComputeValueInterpolation_from_thumb
                      (1,0xffffff40,0xffffffe0,*(undefined4 *)(*piRam0211e908 + 0x34),10);
    piVar3 = piRam0211e908;
    uVar1 = *(ushort *)(*(int *)(*piRam0211e908 + 4) + 6);
    *(undefined4 *)(*piRam0211e908 + 0x3c) = uVar5;
    uVar2 = (undefined2)uVar5;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211e910) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam0211e914) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = uVar2;
    *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = uVar2;
    iVar8 = 0;
    puVar7 = puRam0211e918;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar7 * 0x40 + 6) = uVar2;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    iVar8 = 0;
    puVar7 = puRam0211e920;
    puVar9 = puRam0211e91c;
    do {
      *(undefined2 *)(*(int *)(*piRam0211e908 + 0x18) + (uint)*puVar9 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piRam0211e908 + 0x18) + ((uint)uVar1 + (uint)*puVar7) * 0x40 + 6) =
           uVar2;
      puVar9 = puVar9 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
    uVar1 = *(ushort *)(*(int *)(*piRam0211e908 + 0x10) + 6);
    *(undefined4 *)(*piRam0211e908 + 0x40) = uVar6;
    uVar2 = (undefined2)uVar6;
    *(undefined2 *)(*(int *)(*piRam0211e908 + 0x1c) + iRam0211e910) = uVar2;
    *(undefined2 *)(*(int *)(*piRam0211e908 + 0x1c) + iRam0211e914) = uVar2;
    *(undefined2 *)(*(int *)(*piRam0211e908 + 0x1c) + 0x86) = uVar2;
    *(undefined2 *)(*(int *)(*piRam0211e908 + 0x1c) + 0x46) = uVar2;
    *(undefined2 *)(*(int *)(*piRam0211e908 + 0x1c) + 6) = uVar2;
    piVar3 = piRam0211e908;
    iVar8 = 0;
    puVar7 = puRam0211e918;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar7 * 0x40 + 6) = uVar2;
      piVar4 = piRam0211e908;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    iVar8 = 0;
    puVar7 = puRam0211e920;
    puVar9 = puRam0211e91c;
    do {
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar9 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + ((uint)uVar1 + (uint)*puVar7) * 0x40 + 6) = uVar2;
      puVar9 = puVar9 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 4);
  }
  return;
}

