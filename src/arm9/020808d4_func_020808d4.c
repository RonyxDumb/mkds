/* Decompiled C draft; module arm9; ROM address 020808d4. No matching claim. */
#include "types.h"
#include "deps/020808d4_func_020808d4.h"

void func_020808d4(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  param_1[1] = param_2;
  puVar1 = puRam02080904;
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = puVar1[1];
  uVar2 = puVar1[2];
  param_1[2] = *puVar1;
  param_1[3] = uVar3;
  param_1[4] = uVar2;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}

