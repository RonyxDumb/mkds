/* Decompiled C draft; module arm9_ov001; ROM address 02180cb4. No matching claim. */
#include "types.h"
#include "deps/02180cb4_func_ov001_02180cb4.h"

void func_ov001_02180cb4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam02180cc8;
  uVar2 = 0;
  do {
    *(short *)(param_1 + uVar2 * 2) = (short)uVar2;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < uVar1);
  return;
}

