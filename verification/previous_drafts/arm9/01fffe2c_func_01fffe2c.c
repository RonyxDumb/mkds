/* Decompiled C draft; module arm9; ROM address 01fffe2c. No matching claim. */
#include "types.h"
#include "deps/01fffe2c_func_01fffe2c.h"

uint func_01fffe2c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = uRam01fffe84;
  *(undefined4 *)(&DAT_040000b0 + param_1 * 0xc) = param_2;
  puVar2 = (undefined4 *)(param_1 * 0xc + uVar1);
  puVar2[1] = param_3;
  puVar2[2] = param_4;
  uVar1 = uRam01fffe84;
  if (param_1 == 0) {
    *puVar2 = 0;
    puVar2[1] = 0;
    uVar1 = uRam01fffe84;
    puVar2[2] = uRam01fffe88;
  }
  return *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
}

