/* Decompiled C draft; module arm9; ROM address 020fe488. No matching claim. */
#include "types.h"
#include "deps/020fe488_func_020fe488.h"

void func_020fe488(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  *param_1 = 0xff;
  *param_2 = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 + 1 & 0xff;
    *(char *)(param_3 + uVar2 * 2) = (char)(uVar2 + 1);
    uVar2 = uVar1;
  } while (uVar1 < 0x20);
  *(undefined1 *)(param_3 + (uVar1 - 1) * 2) = 0xff;
  return;
}

