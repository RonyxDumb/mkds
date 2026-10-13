/* Decompiled C draft; module arm9_ov000; ROM address 021834b0. No matching claim. */
#include "types.h"
#include "deps/021834b0_FUN_021834b0.h"

void FUN_021834b0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar3 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar2 = DAT_02183540 - param_1;
  do {
    iVar1 = *DAT_02183544 + iVar3;
    *(ushort *)(*DAT_02183544 + local_1c + 0x4c) =
         (ushort)((*(int *)(iVar1 + 0x60) * iVar2 + *(int *)(iVar1 + 0x9c) * param_1 >> 0xc) << 10)
         | (ushort)(*(int *)(iVar1 + 0x58) * iVar2 + *(int *)(iVar1 + 0x94) * param_1 >> 0xc) |
           (ushort)((*(int *)(iVar1 + 0x5c) * iVar2 + *(int *)(iVar1 + 0x98) * param_1 >> 0xc) << 5)
    ;
    iVar3 = iVar3 + 0xc;
    local_1c = local_1c + 2;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  func_0x02016468(0x1e,0x36,*DAT_02183544 + 0x4c,10);
  return;
}

