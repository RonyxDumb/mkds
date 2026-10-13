/* Decompiled C draft; module arm9_ov000; ROM address 021ad07c. No matching claim. */
#include "types.h"
#include "deps/021ad07c_FUN_021ad07c.h"

int FUN_021ad07c(byte *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  
  *param_2 = param_1;
  iVar2 = 0;
  while (uVar1 = *param_1 - 0x30 & 0xff, uVar1 < 10) {
    iVar2 = uVar1 + iVar2 * 10;
    param_1 = param_1 + 1;
    *param_2 = param_1;
  }
  return iVar2;
}

