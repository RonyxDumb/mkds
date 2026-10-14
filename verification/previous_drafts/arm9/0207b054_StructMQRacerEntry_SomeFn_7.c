/* Decompiled C draft; module arm9; ROM address 0207b054. No matching claim. */
#include "types.h"
#include "deps/0207b054_StructMQRacerEntry_SomeFn_7.h"

void StructMQRacerEntry_SomeFn_7(int param_1,undefined2 param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  uVar2 = param_1 + 0x590U & 3;
  uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 0x38 & 3;
  uVar1 = *(uint *)(uVar4 + 0x38 & 0xfffffffc);
  uVar3 = uVar4 + 8 & 3;
  uVar5 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if ((uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0) &&
     (*(short *)(uVar3 + 0x1a) != 0)) {
    Animation_SetLoop((undefined2 *)(uintptr_t)(uVar3),*(short *)(uVar3 + 0x1a),1);
  }
  *(undefined4 *)(uVar4 + 0x38) = 1;
  *(undefined2 *)(uVar4 + 0x3c) = param_3;
  uVar2 = param_1 + 0x590U & 3;
  uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  Animation_SetWithBlendAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2);
  Animation_SetLoop((undefined2 *)(uintptr_t)(uVar3),param_2,0);
  return;
}

