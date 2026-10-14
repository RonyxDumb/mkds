/* Decompiled C draft; module arm9; ROM address 02068b5c. No matching claim. */
#include "types.h"
#include "deps/02068b5c_StructMQRacerEntry_SomeFn_52.h"

void StructMQRacerEntry_SomeFn_52(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x40000) == 0) {
    uVar1 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x40000;
    StructMQRacerEntry_SomeFn_35(param_1,0);
    return;
  }
  return;
}

