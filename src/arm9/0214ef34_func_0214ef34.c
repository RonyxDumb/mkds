/* Decompiled C draft; module arm9; ROM address 0214ef34. No matching claim. */
#include "types.h"
#include "deps/0214ef34_func_0214ef34.h"

bool func_0214ef34(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = Fifo_SendWord(9,param_4 | uRam0214f054,0);
  if (iVar1 < 0) {
    return false;
  }
  iVar1 = Fifo_SendWord(9,param_1 >> 0x10 | 0x10000,0);
  if (iVar1 < 0) {
    return false;
  }
  iVar1 = Fifo_SendWord(9,param_1 & uRam0214f058 | 0x20000,0);
  if (iVar1 < 0) {
    return false;
  }
  iVar1 = Fifo_SendWord(9,param_2 >> 0x10 | 0x30000,0);
  if (-1 < iVar1) {
    iVar1 = Fifo_SendWord(9,param_2 & uRam0214f058 | 0x40000,0);
    if (iVar1 < 0) {
      return false;
    }
    iVar1 = Fifo_SendWord(9,param_3 >> 0x10 | 0x50000,0);
    if (-1 < iVar1) {
      iVar1 = Fifo_SendWord(9,param_3 & uRam0214f058 | uRam0214f05c,0);
      return -1 < iVar1;
    }
    return false;
  }
  return false;
}

