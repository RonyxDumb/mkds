/* Decompiled C draft; module arm9; ROM address 02017328. No matching claim. */
#include "types.h"
#include "deps/02017328_IntrusiveListWrapper_GetPrevItem.h"

uint IntrusiveListWrapper_GetPrevItem(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = param_1 + 4U & 3;
    uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  else {
    uVar2 = param_2 + (uint)*(ushort *)(param_1 + 10);
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return uVar2;
}

