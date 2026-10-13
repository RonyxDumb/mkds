/* Decompiled C draft; module arm9; ROM address 02017f58. No matching claim. */
#include "types.h"
#include "deps/02017f58_Mem_RestoreFrameHeapState.h"

undefined4 Mem_RestoreFrameHeapState(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x2cU & 3;
  uVar2 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (param_2 != 0) {
    while ((uVar3 != 0 &&
           ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) != param_2))) {
      uVar2 = uVar3 + 0xc & 3;
      uVar3 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
      uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    }
  }
  if (uVar3 != 0) {
    uVar2 = uVar3 + 4 & 3;
    uVar1 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 8 & 3;
    uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 0xc & 3;
    uVar3 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    return 1;
  }
  return 0;
}

