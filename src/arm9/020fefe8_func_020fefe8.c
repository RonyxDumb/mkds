/* Decompiled C draft; module arm9; ROM address 020fefe8. No matching claim. */
#include "types.h"
#include "deps/020fefe8_func_020fefe8.h"

char * func_020fefe8(char *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uStack_8;
  
  if (param_2 == (int *)0x0) {
    return param_1 + 1;
  }
  if (param_3 != 0) {
    uStack_8 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
  }
  if (param_3 != 0) {
    iVar1 = (int)uStack_8 >> 9;
    *param_1 = (char)iVar1;
  }
  else {
    iVar1 = (int)*param_1;
  }
  if (param_3 == 0) {
    *param_2 = iVar1 << 9;
  }
  return param_1 + 1;
}

