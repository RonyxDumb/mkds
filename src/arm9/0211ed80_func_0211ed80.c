/* Decompiled C draft; module arm9; ROM address 0211ed80. No matching claim. */
#include "types.h"
#include "deps/0211ed80_func_0211ed80.h"

void func_0211ed80(void)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  ushort *puVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  int local_1c;
  
  piVar3 = piRam0211efbc;
  if (*psRam0211efb8 != 2) {
    uVar1 = *(ushort *)(*(int *)(*piRam0211efbc + 4) + 6);
    uVar2 = *(ushort *)(*(int *)(*piRam0211efbc + 0x10) + 6);
    iVar9 = 0;
    iVar5 = 0;
    puVar7 = puRam0211efc0;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar7 * 0x40) = 0;
      piVar4 = piRam0211efbc;
      puVar7 = puVar7 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 8);
    iVar9 = 0;
    puVar7 = puRam0211efc4;
    do {
      *(undefined4 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar4 + 0x1c) + (uint)*puVar7 * 0x40) = 0;
      piVar3 = piRam0211efbc;
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + 1;
      puVar8 = puRam0211efcc;
      puVar10 = puRam0211efc8;
    } while (iVar5 < 4);
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar10 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x18) + ((uint)uVar1 + (uint)*puVar8) * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar10 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + ((uint)uVar2 + (uint)*puVar8) * 0x40) = 1;
      iVar5 = iRam0211efd0;
      iVar9 = iVar9 + 1;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    } while (iVar9 < 4);
    *(undefined4 *)(*(int *)(*piVar3 + 0x18) + iRam0211efd0) = 0;
    iVar9 = iRam0211efd4;
    *(undefined4 *)(*(int *)(*piVar3 + 0x18) + iRam0211efd4) = 1;
    *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + iVar5) = 0;
    *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + iVar9) = 1;
    puVar11 = (undefined4 *)*piVar3;
    iVar5 = GetSelectedCup_from_thumb();
    func_0211de00(*(undefined4 *)(iRam0211efd8 + iVar5 * 4),*puVar11,puVar11[1],0x13,0);
    iVar9 = *piRam0211efbc;
    iVar5 = GetSelectedCup_from_thumb();
    func_0211de00(*(undefined4 *)(iRam0211efd8 + iVar5 * 4),*(undefined4 *)(iVar9 + 0xc),
                  *(undefined4 *)(iVar9 + 0x10),0x13,1);
    piVar3 = piRam0211efbc;
    iVar5 = 0;
    local_1c = 0;
    puVar7 = puRam0211efcc;
    do {
      iVar13 = *piVar3;
      iVar9 = GetSelectedCup_from_thumb();
      uVar6 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(*piVar3 + 0x24),
                         *(undefined2 *)
                          (iVar5 + iRam0211efdc + *(int *)(iRam0211efd8 + iVar9 * 4) * 8));
      func_0212426c(0,*puVar7,*(undefined4 *)(*piVar3 + 8),uVar6,*(undefined4 *)(iVar13 + 4),
                    *(undefined4 *)(iVar13 + 0x18));
      iVar13 = *piVar3;
      iVar9 = GetSelectedCup_from_thumb();
      uVar6 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(*piVar3 + 0x24),
                         *(undefined2 *)
                          (iVar5 + iRam0211efdc + *(int *)(iRam0211efd8 + iVar9 * 4) * 8));
      func_0212426c(1,*puVar7,*(undefined4 *)(*piVar3 + 0x14),uVar6,*(undefined4 *)(iVar13 + 0x10),
                    *(undefined4 *)(iVar13 + 0x1c));
      piVar4 = piRam0211efbc;
      iVar5 = iVar5 + 2;
      puVar7 = puVar7 + 1;
      local_1c = local_1c + 1;
    } while (local_1c < 4);
    uVar1 = *puRam0211efc8;
    *(undefined4 *)(*(int *)(*piRam0211efbc + 0x18) + (uint)uVar1 * 0x40) = 1;
    uVar2 = *puRam0211efcc;
    iVar5 = *piVar4;
    func_02124100(uVar2,0xe,*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0x18),
                  *(undefined4 *)(iVar5 + 4));
    piVar3 = piRam0211efbc;
    *(undefined4 *)(*(int *)(*piRam0211efbc + 0x1c) + (uint)uVar1 * 0x40) = 1;
    iVar5 = *piVar3;
    func_02124100(uVar2,0xe,*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x1c),
                  *(undefined4 *)(iVar5 + 0x10));
    piVar3 = piRam0211efbc;
    iVar5 = 1;
    puVar12 = puRam0211efe4;
    puVar7 = puRam0211efe0;
    do {
      *(undefined4 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar7 * 0x40) = 0;
      iVar9 = *piVar3;
      func_02124100(*puVar12,0xf,*(undefined4 *)(iVar9 + 8),*(undefined4 *)(iVar9 + 0x18),
                    *(undefined4 *)(iVar9 + 4));
      *(undefined4 *)(*(int *)(*piVar3 + 0x1c) + (uint)*puVar7 * 0x40) = 0;
      iVar9 = *piVar3;
      func_02124100(*puVar12,0xf,*(undefined4 *)(iVar9 + 0x14),*(undefined4 *)(iVar9 + 0x1c),
                    *(undefined4 *)(iVar9 + 0x10));
      puVar7 = puVar7 + 1;
      puVar12 = puVar12 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    iVar5 = GetSelectedCup_from_thumb();
    func_020d0efc(*(undefined4 *)(iRam0211efe8 + *(int *)(iRam0211efd8 + iVar5 * 4) * 0x10));
    *(undefined4 *)(*piRam0211efbc + 0x38) = 1;
  }
  return;
}

