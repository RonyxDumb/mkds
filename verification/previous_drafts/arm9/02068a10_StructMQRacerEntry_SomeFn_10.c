/* Decompiled C draft; module arm9; ROM address 02068a10. No matching claim. */
#include "types.h"
#include "deps/02068a10_StructMQRacerEntry_SomeFn_10.h"

void StructMQRacerEntry_SomeFn_10(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10) != 0) {
    StructMQRacerEntry_SomeFn_7(param_1,1,0);
    uVar1 = param_1 + 0x590U & 3;
    uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SetNsbtpAnimationProgress
              (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,1);
  }
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x840) == 0) {
    uVar1 = param_1 + 0x3ccU & 3;
    uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
    return;
  }
  return;
}

