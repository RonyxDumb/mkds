/* Decompiled C draft; module arm9; ROM address 02128cfc. No matching claim. */
#include "types.h"
#include "deps/02128cfc_func_02128cfc.h"

void func_02128cfc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  undefined2 local_18;
  undefined2 local_16;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = iRam02128db0;
  local_20 = 0;
  local_24 = 0;
  pbVar5 = pbRam02128db4;
  do {
    local_2c = 0;
    iVar4 = local_24;
    do {
      if (*pbVar5 != 0) {
        iVar2 = local_20;
        iVar3 = local_20;
        do {
          local_16 = 0;
          iVar1 = *piRam02128db8;
          local_18 = *(undefined2 *)(iVar2 + local_3c + iVar1 + 0x2c);
          func_0212426c(iVar4,*(undefined1 *)(local_30 + iVar3),
                        *(undefined4 *)(local_34 + iVar1 + 0xac),&local_18,
                        *(undefined4 *)(local_34 + iVar1 + 0x9c),
                        *(undefined4 *)(local_38 + local_2c + iVar1 + 0x74));
          iVar2 = iVar2 + 2;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)*pbVar5);
      }
      local_2c = local_2c + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    local_3c = local_3c + 0x18;
    local_38 = local_38 + 8;
    local_34 = local_34 + 4;
    local_30 = local_30 + 0xc;
    pbVar5 = pbVar5 + 1;
    local_40 = local_40 + 1;
  } while (local_40 < 2);
  return;
}

