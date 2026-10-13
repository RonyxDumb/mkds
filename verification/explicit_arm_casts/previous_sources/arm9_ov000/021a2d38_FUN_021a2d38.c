/* Decompiled C draft; module arm9_ov000; ROM address 021a2d38. No matching claim. */
#include "types.h"
#include "deps/021a2d38_FUN_021a2d38.h"

void FUN_021a2d38(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_021a2fdc();
  *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)(iVar2 + 0x1e);
  sVar1 = *(short *)(iVar2 + 0x22);
  if (((sVar1 == 2) || (sVar1 == 3)) || (sVar1 == 4)) {
    FUN_021a18e0(param_1,sVar1,param_2);
  }
  return;
}

