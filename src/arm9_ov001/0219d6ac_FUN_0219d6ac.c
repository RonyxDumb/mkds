/* Decompiled C draft; module arm9_ov001; ROM address 0219d6ac. No matching claim. */
#include "types.h"
#include "deps/0219d6ac_FUN_0219d6ac.h"

void FUN_0219d6ac(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_0219d72c;
  iVar5 = 0;
  iVar3 = 0;
  pbVar2 = DAT_0219d728;
  do {
    iVar4 = *piVar1;
    if (*(int *)(iVar4 + 8) == 1) {
      if (*(int *)(iVar4 + iVar3 + 0x28) < 1) {
        *(undefined4 *)(*(int *)(iVar4 + 0x34) + (uint)*pbVar2 * 0x40) = 0;
        *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)pbVar2[2] * 0x40) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(iVar4 + 0x34) + (uint)*pbVar2 * 0x40) = 1;
        *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)pbVar2[2] * 0x40) = 1;
        *(int *)(*piVar1 + iVar3 + 0x28) = *(int *)(*piVar1 + iVar3 + 0x28) + -1;
      }
    }
    else {
      *(undefined4 *)(*(int *)(iVar4 + 0x34) + (uint)*pbVar2 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x34) + (uint)pbVar2[2] * 0x40) = 0;
    }
    iVar3 = iVar3 + 4;
    pbVar2 = pbVar2 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

