/* Decompiled C draft; module arm9; ROM address 020938c0. No matching claim. */
#include "types.h"
#include "deps/020938c0_func_020938c0.h"

void func_020938c0(void)

{
  int iVar1;
  
  iVar1 = func_0209bf70(uRam0209390c,0,0,1,1,uRam02093908);
  *(undefined4 *)(iVar1 + 0x38) = 0x32000;
  *(undefined4 *)(iVar1 + 0x3c) = 0xfff9c000;
  return;
}

