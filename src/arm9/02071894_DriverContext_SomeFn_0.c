/* Decompiled C draft; module arm9; ROM address 02071894. No matching claim. */
#include "types.h"
#include "deps/02071894_DriverContext_SomeFn_0.h"

void DriverContext_SomeFn_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x840) == 0) {
    uVar1 = param_1 + 0x3ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,7);
    return;
  }
  return;
}

