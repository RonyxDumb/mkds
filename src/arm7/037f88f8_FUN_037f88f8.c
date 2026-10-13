/* Decompiled C draft; module arm7; ROM address 037f88f8. No matching claim. */
#include "types.h"
#include "deps/037f88f8_FUN_037f88f8.h"

void FUN_037f88f8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc;
  *(undefined4 *)(DAT_037f8938 + iVar1) = param_2;
  *(undefined4 *)(DAT_037f893c + iVar1) = param_3;
  FUN_037f888c(1 << (param_1 + 3U & 0xff));
  *(undefined4 *)(DAT_037f8940 + iVar1) = 1;
  return;
}

