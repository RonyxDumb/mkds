/* Decompiled C draft; module arm9; ROM address 0211a100. No matching claim. */
#include "types.h"
#include "deps/0211a100_func_0211a100.h"

void func_0211a100(void)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  ushort *puVar14;
  undefined4 *puVar15;
  int iVar16;
  int iVar17;
  
  piVar2 = piRam0211a390;
  if (*psRam0211a38c != 2) {
    uVar4 = (uint)*(ushort *)(*(int *)(*piRam0211a390 + 4) + 6);
    uVar1 = *(ushort *)(*(int *)(*piRam0211a390 + 0x10) + 6);
    iVar13 = 0;
    iVar11 = 0;
    puVar5 = puRam0211a394;
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x20) + (uint)*puVar5 * 0x40) = 0;
      piVar3 = piRam0211a390;
      puVar5 = puVar5 + 1;
      iVar13 = iVar13 + 1;
    } while (iVar13 < 8);
    iVar13 = 0;
    puVar5 = puRam0211a398;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x20) + (uint)*puVar5 * 0x40) = 0;
      piVar2 = piRam0211a390;
      puVar5 = puVar5 + 1;
      iVar11 = iVar11 + 1;
      puVar12 = puRam0211a3a0;
      puVar14 = puRam0211a39c;
    } while (iVar11 < 4);
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x20) + (uint)*puVar14 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar2 + 0x20) + ((uint)uVar1 + (uint)*puVar12) * 0x40) = 1;
      iVar13 = iVar13 + 1;
      puVar12 = puVar12 + 1;
      puVar14 = puVar14 + 1;
    } while (iVar13 < 4);
    **(undefined4 **)(*piVar2 + 0x1c) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + 0x80) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iRam0211a3a4) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + 0xc0) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iRam0211a3a8) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + uVar4 * 0x40) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + (uVar4 + 1) * 0x40) = 1;
    iVar11 = (uVar4 + 2) * 0x40;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar11) = 1;
    iVar13 = (uVar4 + 3) * 0x40;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar13) = 1;
    iVar6 = (uVar4 + 4) * 0x40;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar6) = 1;
    iVar7 = (uVar4 + 5) * 0x40;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar7) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x20) + iRam0211a3ac) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x20) + iRam0211a3b0) = 1;
    puVar15 = (undefined4 *)*piVar2;
    iVar8 = GetSelectedCup_from_thumb();
    func_0211de00(*(undefined4 *)(iRam0211a3b4 + iVar8 * 4),*puVar15,puVar15[1],0,0);
    iVar16 = *piRam0211a390;
    iVar8 = GetSelectedCup_from_thumb();
    func_0211de00(*(undefined4 *)(iRam0211a3b4 + iVar8 * 4),*(undefined4 *)(iVar16 + 0xc),
                  *(undefined4 *)(iVar16 + 0x10),0x13,1);
    puVar15 = (undefined4 *)*piRam0211a390;
    iVar8 = GetSelectedCup_from_thumb();
    uVar9 = func_02124a68(5,*puVar15,puVar15[1]);
    func_0211ded0(*(undefined4 *)(iRam0211a3b4 + iVar8 * 4),*puVar15,puVar15[1],5,uVar9,0);
    iVar16 = 0;
    iVar8 = 0;
    puVar5 = puRam0211a3a0;
    do {
      iVar17 = *piRam0211a390;
      iVar10 = GetSelectedCup_from_thumb();
      uVar9 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(*piRam0211a390 + 0x28),
                         *(undefined2 *)
                          (iVar8 + iRam0211a3b8 + *(int *)(iRam0211a3b4 + iVar10 * 4) * 8));
      func_0212426c(1,*puVar5,*(undefined4 *)(*piRam0211a390 + 0x18),uVar9,
                    *(undefined4 *)(iVar17 + 0x10),*(undefined4 *)(iVar17 + 0x20));
      iVar8 = iVar8 + 2;
      puVar5 = puVar5 + 1;
      iVar16 = iVar16 + 1;
    } while (iVar16 < 4);
    iVar8 = *piRam0211a390;
    uVar9 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar8 + 0x28),0x73);
    func_0212426c(0,2,*(undefined4 *)(*piRam0211a390 + 8),uVar9,*(undefined4 *)(iVar8 + 4),
                  *(undefined4 *)(iVar8 + 0x1c));
    iVar8 = *piRam0211a390;
    uVar9 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar8 + 0x28),0x74);
    func_0212426c(0,4,*(undefined4 *)(*piRam0211a390 + 8),uVar9,*(undefined4 *)(iVar8 + 4),
                  *(undefined4 *)(iVar8 + 0x1c));
    iVar8 = *piRam0211a390;
    func_02124140(0,0,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0x1c),
                  *(undefined4 *)(iVar8 + 4));
    iVar8 = *piRam0211a390;
    func_02124140(1,0,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0x1c),
                  *(undefined4 *)(iVar8 + 4));
    iVar8 = *piRam0211a390;
    func_02124140(2,0,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0x1c),
                  *(undefined4 *)(iVar8 + 4));
    iVar8 = *piRam0211a390;
    func_02124140(4,0,*(undefined4 *)(iVar8 + 8),*(undefined4 *)(iVar8 + 0x1c),
                  *(undefined4 *)(iVar8 + 4));
    iVar8 = *(int *)(*piRam0211a390 + 0x40);
    if (((iVar8 == 1) || (iVar8 == 2)) || (iVar8 == 3)) {
      *(undefined4 *)(*(int *)(*piRam0211a390 + 0x1c) + iVar11) = 0;
      piVar2 = piRam0211a390;
      *(undefined4 *)(*(int *)(*piRam0211a390 + 0x1c) + iVar13) = 0;
      *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar6) = 0;
      *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + iVar7) = 0;
    }
  }
  return;
}

