/* Decompiled C draft; module arm9; ROM address 02142424. No matching claim. */
#include "types.h"
#include "deps/02142424_func_02142424.h"

undefined4 func_02142424(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      func_021423e4(param_2 + uVar2);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return 0;
}

