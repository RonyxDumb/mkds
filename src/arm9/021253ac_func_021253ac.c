/* Decompiled C draft; module arm9; ROM address 021253ac. No matching claim. */
#include "types.h"
#include "deps/021253ac_func_021253ac.h"

int func_021253ac(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & uRam021253f0) == 0) {
    if ((param_1 & uRam021253f4) != 0) {
      iVar1 = param_3 - param_4;
    }
  }
  else {
    iVar1 = param_3 - param_4 >> 1;
  }
  if (param_2 == 1) {
    iVar1 = iVar1 + (param_4 - param_5 >> 1);
  }
  else if (param_2 == 2) {
    iVar1 = iVar1 + (param_4 - param_5);
  }
  return iVar1;
}

