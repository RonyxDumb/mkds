/* Decompiled C draft; module arm9; ROM address 020d6d8c. No matching claim. */
#include "types.h"
#include "deps/020d6d8c_func_020d6d8c.h"

undefined1 func_020d6d8c(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = param_3 * 0x38 + iRam020d6dbc + param_2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = *(undefined1 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + param_4);
  if (param_1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

