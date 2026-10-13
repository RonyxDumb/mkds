/* Decompiled C draft; module arm9; ROM address 02017f24. No matching claim. */
#include "types.h"
#include "deps/02017f24_Mem_Frame_SomeFn4.h"

int Mem_Frame_SomeFn4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x1cU & 3;
  uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar3 = param_1 + 0x28U & 3;
  uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) ==
      (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    uVar1 = param_1 + 0x24U & 3;
    uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    return (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - param_1;
  }
  return 0;
}

