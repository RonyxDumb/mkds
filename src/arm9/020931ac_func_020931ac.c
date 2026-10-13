/* Decompiled C draft; module arm9; ROM address 020931ac. No matching claim. */
#include "types.h"
#include "deps/020931ac_func_020931ac.h"

undefined1 func_020931ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xa8U & 3;
  uVar1 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (0xfff < (int)uVar2) {
    return 3;
  }
  if ((int)uVar2 < iRam020931e8) {
    return iRam020931ec <= (int)uVar2;
  }
  return 2;
}

