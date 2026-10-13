/* Decompiled C draft; module arm7; ROM address 06009e58. No matching claim. */
#include "types.h"
#include "deps/06009e58_FUN_06009e58.h"

undefined4 FUN_06009e58(ushort param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  *DAT_06009e90 = param_2;
  *DAT_06009e94 = param_1 | 0x5000;
  iVar1 = FUN_0600f00c();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

