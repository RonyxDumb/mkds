/* Decompiled C draft; module arm7; ROM address 0600eb40. No matching claim. */
#include "types.h"
#include "deps/0600eb40_FUN_0600eb40.h"

void FUN_0600eb40(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(uint *)(DAT_0600eb94 & 0xfffffffc) >> (DAT_0600eb94 & 3) * 8 |
          *(uint *)(DAT_0600eb94 & 0xfffffffc) << (DAT_0600eb94 & 3) * -8 + 0x20) + DAT_0600eb98;
  *(ushort *)(iVar1 + 2) =
       *(ushort *)(iVar1 + 2) & ~(ushort)(1 << (param_1 & 0xff)) |
       (ushort)(param_2 << (param_1 & 0xff));
  if ((*(ushort *)(iVar1 + 2) & ~*(ushort *)(iVar1 + 6)) == 0) {
    *DAT_0600eba0 = 8;
  }
  else {
    *DAT_0600eb9c = 8;
  }
  return;
}

