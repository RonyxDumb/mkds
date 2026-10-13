/* Decompiled C draft; module arm9; ROM address 02134d80. No matching claim. */
#include "types.h"
#include "deps/02134d80_func_02134d80.h"

uint func_02134d80(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_1 + param_3;
  if (param_3 != 0) {
    do {
      uVar1 = uVar1 - 1;
      if (((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0xff) == (param_2 & 0xff)) {
        return uVar1;
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return 0;
}

