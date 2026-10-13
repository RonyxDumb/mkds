/* Decompiled C draft; module arm7; ROM address 06008c98. No matching claim. */
#include "types.h"
#include "deps/06008c98_FUN_06008c98.h"

void FUN_06008c98(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (*(short *)(param_1 + 8) != 0) {
    while (uVar2 != 0xffffffff) {
      uVar1 = FUN_06008e48(uVar2);
      FUN_060090b4(param_1,uVar2);
      uVar2 = uVar1;
    }
  }
  return;
}

