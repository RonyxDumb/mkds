/* Decompiled C draft; module arm9_ov001; ROM address 021989bc. No matching claim. */
#include "types.h"
#include "deps/021989bc_FUN_021989bc.h"

void FUN_021989bc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  
  iVar3 = 0;
  local_20 = 0;
  iVar2 = DAT_02198a64;
  do {
    iVar4 = 0;
    iVar5 = iVar4;
    do {
      iVar1 = *DAT_02198a68;
      if (local_20 == *(int *)(iVar1 + 8)) {
        if (*(int *)(iVar4 + iVar3 + iVar1 + 0x40) < 1) {
          *(undefined4 *)(*(int *)(iVar1 + 0x58) + (uint)*(byte *)(iVar2 + iVar5) * 0x40) = 0;
          *(undefined4 *)
           (*(int *)(*DAT_02198a68 + 0x58) + (uint)*(byte *)(iVar2 + iVar5 + 2) * 0x40) = 1;
        }
        else {
          *(undefined4 *)(*(int *)(iVar1 + 0x58) + (uint)*(byte *)(iVar2 + iVar5) * 0x40) = 1;
          *(undefined4 *)
           (*(int *)(*DAT_02198a68 + 0x58) + (uint)*(byte *)(iVar2 + iVar5 + 2) * 0x40) = 1;
          iVar1 = iVar3 + *DAT_02198a68 + iVar4;
          *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + -1;
        }
      }
      else {
        *(undefined4 *)(*(int *)(iVar1 + 0x58) + (uint)*(byte *)(iVar2 + iVar5) * 0x40) = 0;
        *(undefined4 *)(*(int *)(*DAT_02198a68 + 0x58) + (uint)*(byte *)(iVar2 + iVar5 + 2) * 0x40)
             = 0;
      }
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    iVar3 = iVar3 + 8;
    iVar2 = iVar2 + 6;
    local_20 = local_20 + 1;
  } while (local_20 < 2);
  return;
}

