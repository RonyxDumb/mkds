/* Decompiled C draft; module arm9; ROM address 0206d138. No matching claim. */
#include "types.h"
#include "deps/0206d138_StructMQRacerEntry_SomeFn_89.h"

void StructMQRacerEntry_SomeFn_89(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x840) == 0) {
    uVar2 = param_1 + 0x3ccU & 3;
    uVar1 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,8);
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x10) != 0) {
    if ((uVar2 & 0x30000) == 0) {
      StructMQRacerEntry_SomeFn_7(param_1,2,0);
      return;
    }
    return;
  }
  return;
}

