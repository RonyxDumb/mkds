/* Decompiled C draft; module arm9_ov000; ROM address 021a8e18. No matching claim. */
#include "types.h"
#include "deps/021a8e18_FUN_021a8e18.h"

void FUN_021a8e18(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  ushort local_20 [2];
  uint local_1c [2];
  
  iVar2 = FUN_021a7534(param_1,local_20,local_1c);
  uVar1 = DAT_021a8e64;
  if (-1 < iVar2) {
    *(ushort *)(param_2 + 2) = local_20[0] >> 8 | local_20[0] << 8 & (ushort)DAT_021a8e64;
    *(uint *)(param_2 + 4) =
         local_1c[0] << 0x18 & DAT_021a8e68 |
         local_1c[0] << 8 & DAT_021a8e6c | local_1c[0] >> 0x18 | local_1c[0] >> 8 & uVar1;
  }
  return;
}

