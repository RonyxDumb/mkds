/* Decompiled C draft; module arm9; ROM address 020f91c4. No matching claim. */
#include "types.h"
#include "deps/020f91c4_func_020f91c4.h"

bool func_020f91c4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  return param_2 * param_2 < (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffe0);
}

