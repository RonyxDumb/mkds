/* Decompiled C draft; module arm9; ROM address 0206c0e0. No matching claim. */
#include "types.h"
#include "deps/0206c0e0_StructMQRacerEntry_SomeFn_86.h"

undefined4 StructMQRacerEntry_SomeFn_86(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam0206c118) == 0) &&
      (uVar1 = param_1 + 0x4cU & 3, uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
      ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x800) == 0)) &&
     (uVar1 = param_1 + 0x180U & 3, uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc),
     uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0)) {
    return 0;
  }
  return 1;
}

