/* Decompiled C draft; module arm9; ROM address 02116624. No matching claim. */
#include "types.h"
#include "deps/02116624_func_02116624.h"

void func_02116624(void)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  int local_4c;
  ushort *local_44;
  ushort *local_40;
  ushort *local_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  ushort *local_20;
  ushort *local_1c;
  
  uVar4 = (uint)*(ushort *)(*(int *)(*piRam02116824 + 0x30) + 6);
  sVar3 = func_02116870();
  piVar1 = piRam02116824;
  local_4c = 0;
  local_1c = puRam02116830;
  local_2c = puRam02116834;
  local_28 = puRam02116838;
  local_24 = puRam0211683c;
  local_20 = puRam02116840;
  iVar8 = 0;
  puVar7 = puRam0211682c;
  puVar9 = puRam02116828;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar9 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_1c * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_2c * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_28 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_24 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uVar4 + *local_20) * 0x40) = 0;
    piVar2 = piRam02116824;
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
    local_1c = local_1c + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    local_4c = local_4c + 1;
  } while (local_4c < 5);
  local_44 = puRam02116834;
  local_40 = puRam0211682c;
  local_3c = puRam02116830;
  local_38 = puRam02116828;
  local_34 = puRam02116838;
  local_30 = puRam0211683c;
  puVar7 = puRam02116840;
  do {
    iVar5 = func_02116844((int)(short)iVar8);
    if (iVar5 != 0) {
      if (*(short *)(*piVar2 + 0x74) == iVar8) {
        iVar5 = func_02114398(sVar3);
        if (iVar5 == 0) {
          *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_40 * 0x40) = 1;
          iVar5 = *piVar2;
          func_02124100(*puVar7,0xe,*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),
                        *(undefined4 *)(iVar5 + 0x30));
        }
        else {
          *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_44 * 0x40) = 1;
          iVar5 = *piVar2;
          func_02124100(*puVar7,0xe,*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),
                        *(undefined4 *)(iVar5 + 0x30));
        }
      }
      else {
        iVar5 = func_02114398(sVar3);
        if (iVar5 == 0) {
          *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_38 * 0x40) = 1;
          iVar5 = *piVar2;
          func_02124100(*puVar7,0xf,*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),
                        *(undefined4 *)(iVar5 + 0x30));
        }
        else {
          *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_3c * 0x40) = 1;
          iVar5 = *piVar2;
          func_02124100(*puVar7,0xe,*(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(iVar5 + 0x3c),
                        *(undefined4 *)(iVar5 + 0x30));
        }
      }
      iVar5 = func_02114398(sVar3);
      *(uint *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_34 * 0x40) = (uint)(iVar5 == 0);
      uVar6 = func_02114398(sVar3);
      *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_30 * 0x40) = uVar6;
      *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + *puVar7) * 0x40) = 1;
    }
    sVar3 = sVar3 + 1;
    local_44 = local_44 + 1;
    puVar7 = puVar7 + 1;
    local_40 = local_40 + 1;
    local_3c = local_3c + 1;
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
    local_30 = local_30 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
  return;
}

