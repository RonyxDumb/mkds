/* Decompiled C draft; module arm9; ROM address 0201812c. No matching claim. */
#include "types.h"
#include "deps/0201812c_Mem_Frame_ResetFromTail.h"

void Mem_Frame_ResetFromTail(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x2cU & 3;
  uVar2 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  for (uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20; uVar3 != 0;
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) {
    uVar2 = param_1 + 0x1cU & 3;
    uVar1 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(uVar3 + 8) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 0xc & 3;
    uVar3 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  }
  uVar3 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  return;
}

