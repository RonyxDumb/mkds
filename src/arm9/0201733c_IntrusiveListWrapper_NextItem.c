/* Decompiled C draft; module arm9; ROM address 0201733c. No matching claim. */
#include "types.h"
#include "deps/0201733c_IntrusiveListWrapper_NextItem.h"

uint IntrusiveListWrapper_NextItem(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  }
  else {
    uVar2 = param_2 + (uint)*(ushort *)(param_1 + 10) + 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

