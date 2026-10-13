/* Decompiled C draft; module arm9; ROM address 01ffbfe4. No matching claim. */
#include "types.h"
#include "deps/01ffbfe4_func_01ffbfe4.h"

void func_01ffbfe4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x1d0U & 3;
  uVar2 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x01ffc000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01ffc004)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x400,param_1 + 0x15c,
                  param_1 + 0x98,param_1 + 0x1c4);
  return;
}

