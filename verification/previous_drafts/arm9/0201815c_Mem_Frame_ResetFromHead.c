/* Decompiled C draft; module arm9; ROM address 0201815c. No matching claim. */
#include "types.h"
#include "deps/0201815c_Mem_Frame_ResetFromHead.h"

void Mem_Frame_ResetFromHead(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}

