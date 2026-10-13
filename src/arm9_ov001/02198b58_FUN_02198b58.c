/* Decompiled C draft; module arm9_ov001; ROM address 02198b58. No matching claim. */
#include "types.h"
#include "deps/02198b58_FUN_02198b58.h"

void FUN_02198b58(void)

{
  byte *pbVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_18;
  
  iVar3 = 0;
  local_18 = 0;
  pbVar1 = PTR_data_ov001_02198bb4;
  puVar2 = PTR_data_ov001_02198bb0;
  do {
    iVar4 = 0;
    if (*pbVar1 != 0) {
      do {
        iVar5 = *(int *)PTR_data_ov001_02198bb8;
        if (iVar4 == *(int *)(iVar3 + iVar5 + 0xc)) {
          *(undefined4 *)(*(int *)(iVar5 + 0x58) + (uint)(byte)puVar2[iVar4] * 0x40) = 1;
        }
        else {
          *(undefined4 *)(*(int *)(iVar5 + 0x58) + (uint)(byte)puVar2[iVar4] * 0x40) = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*pbVar1);
    }
    iVar3 = iVar3 + 4;
    puVar2 = puVar2 + 3;
    pbVar1 = pbVar1 + 1;
    local_18 = local_18 + 1;
  } while (local_18 < 2);
  return;
}

