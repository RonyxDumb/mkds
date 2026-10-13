/* Decompiled C draft; module arm9_ov000; ROM address 02182150. No matching claim. */
#include "types.h"
#include "deps/02182150_FUN_02182150.h"

void FUN_02182150(void)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int local_14;
  
  iVar2 = DAT_021821dc;
  piVar1 = DAT_021821d8;
  iVar4 = 0;
  local_14 = 0;
  pbVar3 = DAT_021821d4;
  do {
    iVar5 = *piVar1;
    if (*(int *)(iVar5 + 8) == 1) {
      if (*(int *)(iVar5 + iVar4 + 0x2c) < 1) {
        *(undefined4 *)(*(int *)(iVar5 + iVar2) + (uint)*pbVar3 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar1 + iVar2) + (uint)pbVar3[2] * 0x40) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(iVar5 + iVar2) + (uint)*pbVar3 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + iVar2) + (uint)pbVar3[2] * 0x40) = 1;
        *(int *)(*piVar1 + iVar4 + 0x2c) = *(int *)(*piVar1 + iVar4 + 0x2c) + -1;
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar5 + iVar2) + (uint)*pbVar3 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + iVar2) + (uint)pbVar3[2] * 0x40) = 0;
    }
    iVar4 = iVar4 + 4;
    pbVar3 = pbVar3 + 1;
    local_14 = local_14 + 1;
  } while (local_14 < 2);
  return;
}

