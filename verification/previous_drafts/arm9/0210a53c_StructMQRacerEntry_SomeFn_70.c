/* Decompiled C draft; module arm9; ROM address 0210a53c. No matching claim. */
#include "types.h"
#include "deps/0210a53c_StructMQRacerEntry_SomeFn_70.h"

void StructMQRacerEntry_SomeFn_70(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x488U & 3;
  uVar2 = *(uint *)(param_1 + 0x488U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != uRam0210a574) {
    StructMQRacerEntry_SomeFn_75();
    *(uint *)(param_1 + 0x488) = uRam0210a574;
    return;
  }
  return;
}

