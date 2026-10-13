/* Decompiled C draft; module arm9; ROM address 020e5370. No matching claim. */
#include "types.h"
#include "deps/020e5370_func_020e5370.h"

void func_020e5370(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam020e53a8;
  if (param_4 <= param_3) {
    param_3 = param_4;
  }
  *(short *)((*(uint *)(uRam020e53a8 & 0xfffffffc) >> (uRam020e53a8 & 3) * 8 |
             *(uint *)(uRam020e53a8 & 0xfffffffc) << (uRam020e53a8 & 3) * -8 + 0x20) + 0x6e) =
       (short)param_3;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_0207aec8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2,param_1);
  return;
}

