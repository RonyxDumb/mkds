/* Decompiled C draft; module arm9; ROM address 0213a038. No matching claim. */
#include "types.h"
#include "deps/0213a038_func_0213a038.h"

int func_0213a038(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    do {
      uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff;
      uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
      if (uVar1 != uVar2) {
        return uVar1 - uVar2;
      }
    } while ((uVar1 != 0) &&
            (param_3 = param_3 + -1, param_1 = param_1 + 1, param_2 = param_2 + 1, param_3 != 0));
  }
  return 0;
}

