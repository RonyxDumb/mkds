/* Decompiled C draft; module arm9; ROM address 020add80. No matching claim. */
#include "types.h"
#include "deps/020add80_NFTR_SomeFn_3.h"

undefined2 NFTR_SomeFn_3(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 2);
}

