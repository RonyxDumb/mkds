/* Decompiled C draft; module arm9; ROM address 0202b2bc. No matching claim. */
#include "types.h"
#include "deps/0202b2bc_func_0202b2bc.h"

void func_0202b2bc(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int local_30;
  
  iVar8 = *piRam0202b3d0;
  uVar10 = (uint)*(ushort *)(*(int *)(iVar8 + 0x54) + 6);
  uVar3 = func_02121d94();
  uVar4 = GetBmgIndexFromCircuitIndex_from_thumb();
  puVar5 = (undefined2 *)
           Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202b3d0 + 0x88),uVar4);
  local_30 = 0;
  iVar9 = 0;
  psVar6 = psRam0202b3d4;
  do {
    *(undefined4 *)(*(int *)(iVar8 + 0x60) + psVar6[3] * 0x40) = 0;
    *(undefined4 *)(*(int *)(iVar8 + 0x60) + (uVar10 + (int)*psVar6) * 0x40) =
         *(undefined4 *)(*(int *)(iVar8 + 0x60) + psVar6[3] * 0x40);
    *(undefined2 *)(*(int *)(iVar8 + 0x60) + psVar6[3] * 0x40 + 4) = 0;
    *(undefined2 *)(*(int *)(iVar8 + 0x60) + (uVar10 + (int)*psVar6) * 0x40 + 4) =
         *(undefined2 *)(*(int *)(iVar8 + 0x60) + psVar6[3] * 0x40 + 4);
    func_02025f14(*piRam0202b3d0 + 0xfc + iVar9,1);
    iVar7 = iRam0202b3d8;
    psVar6 = psVar6 + 4;
    iVar9 = iVar9 + 0x10;
    local_30 = local_30 + 1;
  } while (local_30 < 4);
  *(undefined4 *)(*(int *)(iVar8 + 0x60) + iRam0202b3d8) = 1;
  sVar1 = *psRam0202b3d4;
  iVar9 = ((int)sVar1 + uVar10) * 0x40;
  *(undefined4 *)(*(int *)(iVar8 + 0x60) + iVar9) = *(undefined4 *)(*(int *)(iVar8 + 0x60) + iVar7);
  iVar7 = *(int *)(iVar8 + 0x60) + 6;
  *(short *)(iVar7 + iVar9) = *(short *)(iVar7 + iVar9) + 2;
  func_0212426c(0,(int)sVar1,*(undefined4 *)(iVar8 + 0x5c),puVar5,*(undefined4 *)(iVar8 + 0x54),
                *(undefined4 *)(iVar8 + 0x60));
  *(undefined4 *)(*piRam0202b3d0 + iRam0202b3dc) = uVar3;
  uVar3 = GetBmgIndexFromCircuitIndex_from_thumb();
  piVar2 = piRam0202b3d0;
  *(undefined4 *)(*piRam0202b3d0 + iRam0202b3e0) = uVar3;
  *(undefined2 *)(*piVar2 + iRam0202b3e4) = *puVar5;
  *(undefined2 *)(*piVar2 + iRam0202b3e8) = puVar5[1];
  *(undefined2 *)(*piVar2 + iRam0202b3ec) = puVar5[2];
  *(undefined2 *)(*piVar2 + iRam0202b3f0) = puVar5[3];
  return;
}

