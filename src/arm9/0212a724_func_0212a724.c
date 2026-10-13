/* Decompiled C draft; module arm9; ROM address 0212a724. No matching claim. */
#include "types.h"
#include "deps/0212a724_func_0212a724.h"

void func_0212a724(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined1 *local_84;
  int local_80;
  int local_7c;
  int local_74;
  int local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  int local_64;
  int local_60;
  int local_58;
  int local_54 [2];
  undefined1 local_4c [8];
  undefined1 local_44 [48];
  
  local_54[0] = *piRam0212a8ac;
  local_54[1] = piRam0212a8ac[1];
  puVar5 = local_4c;
  iVar4 = 8;
  puVar6 = puRam0212a8b0;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar5 = local_44;
  iVar4 = 0x30;
  puVar6 = puRam0212a8b4;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_98 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = puRam0212a8b8;
  puVar5 = local_4c;
  local_60 = 0;
  iVar4 = local_60;
  puVar6 = puRam0212a8b8;
  local_68 = puVar5;
  iVar8 = iRam0212a8bc;
  do {
    do {
      puVar2 = (undefined4 *)*piRam0212a8c0;
      iVar3 = func_021243ac(*puVar2,*(undefined1 *)(iVar8 + iVar4),
                            *(undefined4 *)((int)puVar2 + local_70 + 0xac),*puVar5,puVar5[1],*puVar6
                            ,puVar2[0x24],*(undefined4 *)((int)puVar2 + local_70 + 0x9c),
                            *(undefined4 *)((int)puVar2 + local_74 + 0x78),local_54[1]);
      local_54[1] = local_54[1] - iVar3;
      puVar5 = puVar5 + 2;
      iVar4 = iVar4 + 1;
      puVar6 = puVar6 + 3;
    } while (iVar4 < 2);
    local_74 = local_74 + 8;
    local_70 = local_70 + 4;
    puVar6 = local_6c + 6;
    puVar5 = local_68 + 4;
    iVar8 = iVar8 + 2;
    local_98 = local_98 + 1;
    iVar4 = local_60;
    local_68 = puVar5;
    local_6c = puVar6;
  } while (local_98 < 2);
  local_64 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = iRam0212a8c4;
  local_84 = local_44;
  local_80 = iRam0212a8c8;
  local_58 = 0;
  pbVar9 = pbRam0212a8cc;
  do {
    local_94 = 0;
    piVar7 = local_54;
    local_7c = 0;
    do {
      if (*pbVar9 != 0) {
        iVar4 = local_58;
        puVar5 = local_84;
        do {
          puVar2 = (undefined4 *)*piRam0212a8c0;
          iVar8 = func_021243ac(*puVar2,*(undefined1 *)(local_80 + iVar4),
                                *(undefined4 *)((int)puVar2 + local_8c + 0xac),*puVar5,puVar5[1],
                                *(undefined1 *)(local_88 + iVar4),puVar2[0x24],
                                *(undefined4 *)((int)puVar2 + local_8c + 0x9c),
                                *(undefined4 *)((int)puVar2 + local_90 + local_7c + 0x74),*piVar7);
          *piVar7 = *piVar7 - iVar8;
          puVar5 = puVar5 + 2;
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*pbVar9);
      }
      piVar7 = piVar7 + 1;
      local_7c = local_7c + 4;
      local_94 = local_94 + 1;
    } while (local_94 < 2);
    local_90 = local_90 + 8;
    local_8c = local_8c + 4;
    local_88 = local_88 + 0xc;
    local_84 = local_84 + 0x18;
    local_80 = local_80 + 0xc;
    pbVar9 = pbVar9 + 1;
    local_64 = local_64 + 1;
  } while (local_64 < 2);
  return;
}

