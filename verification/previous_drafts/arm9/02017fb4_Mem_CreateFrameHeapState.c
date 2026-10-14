/* Decompiled C draft; module arm9; ROM address 02017fb4. No matching claim. */
#include "types.h"
#include "deps/02017fb4_Mem_CreateFrameHeapState.h"

undefined4 Mem_CreateFrameHeapState(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  puVar2 = (undefined4 *)Mem_Frame_AllocFromHead((uint *)(uintptr_t)(param_1 + 0x24),0x10,4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = param_2;
    puVar2[1] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x28U & 3;
    uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    puVar2[2] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x2cU & 3;
    uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    puVar2[3] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    *(undefined4 **)(param_1 + 0x2c) = puVar2;
    return 1;
  }
  return 0;
}

