/* Decompiled C draft; module arm9; ROM address 0206c0a8. No matching claim. */
#include "types.h"
#include "deps/0206c0a8_StructMQRacerEntry_SomeFn_71.h"

uint StructMQRacerEntry_SomeFn_71(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x4c0U & 3;
  uVar2 = *(uint *)(param_1 + 0x4c0U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

