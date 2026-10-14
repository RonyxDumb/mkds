/* Decompiled C draft; module arm9; ROM address 021445e0. No matching claim. */
#include "types.h"
#include "deps/021445e0_func_021445e0.h"

int func_021445e0(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = Math_CountPopulation(param_2 & (1 << (param_4 & 0xff)) - 1U);
  return (uint)*(ushort *)(param_1 + 0x810) * iVar1 + param_3;
}

