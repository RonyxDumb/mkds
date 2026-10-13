/* Decompiled C draft; module arm9; ROM address 0206c094. No matching claim. */
#include "types.h"
#include "deps/0206c094_StructMQRacerEntry_SomeFn_83.h"

bool StructMQRacerEntry_SomeFn_83(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x800000) != 0;
}

