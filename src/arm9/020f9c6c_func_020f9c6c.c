/* Decompiled C draft; module arm9; ROM address 020f9c6c. No matching claim. */
#include "types.h"
#include "deps/020f9c6c_func_020f9c6c.h"

void func_020f9c6c(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0xda) == -1) {
    uVar1 = param_1 + 0xe0U & 3;
    uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    uVar2 = FindComputeSomeCollisionEntryId
                      (param_1 + 0x50,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x4000,param_1
                      );
    *(undefined2 *)(param_1 + 0xda) = uVar2;
    return;
  }
  return;
}

