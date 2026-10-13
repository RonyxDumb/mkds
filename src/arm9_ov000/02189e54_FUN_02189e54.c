/* Decompiled C draft; module arm9_ov000; ROM address 02189e54. No matching claim. */
#include "types.h"
#include "deps/02189e54_FUN_02189e54.h"

void FUN_02189e54(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_02188584(0x10);
  if (0xd < param_1) {
    param_1 = 0xd;
  }
  *(ushort *)(iVar1 + DAT_02189e7c) =
       *(ushort *)(iVar1 + DAT_02189e7c) | (ushort)(1 << (param_1 - 1 & 0xff));
  return;
}

