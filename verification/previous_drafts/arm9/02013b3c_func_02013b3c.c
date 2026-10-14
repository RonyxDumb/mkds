/* Decompiled C draft; module arm9; ROM address 02013b3c. No matching claim. */
#include "types.h"
#include "deps/02013b3c_func_02013b3c.h"

int func_02013b3c(int param_1,undefined4 param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)func_02013b20();
  param_1 = param_1 + (uint)puVar1[3];
  uVar2 = (int)(short)puVar1[2] * param_3 >> 0xc;
  while ((uVar2 != 0 && (param_3 <= *(ushort *)(param_1 + uVar2 * 4)))) {
    uVar2 = uVar2 - 1;
  }
  while ((uVar2 + 1 < (uint)*puVar1 && (*(ushort *)(param_1 + uVar2 * 4 + 4) <= param_3))) {
    uVar2 = uVar2 + 1;
  }
  return param_1 + uVar2 * 4;
}

