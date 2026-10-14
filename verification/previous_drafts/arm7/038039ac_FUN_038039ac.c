/* Decompiled C draft; module arm7; ROM address 038039ac. No matching claim. */
#include "types.h"
#include "deps/038039ac_FUN_038039ac.h"

void FUN_038039ac(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 == 0 &&
      *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 == 0) {
    thunk_FUN_037f8b24();
  }
  uVar1 = param_2 + 4 & 3;
  uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
  FUN_037faf84(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

