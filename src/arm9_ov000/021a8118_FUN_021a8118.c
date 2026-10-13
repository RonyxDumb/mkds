/* Decompiled C draft; module arm9_ov000; ROM address 021a8118. No matching claim. */
#include "types.h"
#include "deps/021a8118_FUN_021a8118.h"

int FUN_021a8118(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x68);
  iVar1 = ((uint)*(ushort *)(iVar2 + DAT_021a8138) - (uint)*(ushort *)(iVar2 + DAT_021a8134)) + -1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + *(int *)(iVar2 + 0xf8);
  }
  return iVar1;
}

