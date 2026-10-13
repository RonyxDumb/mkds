/* Decompiled C draft; module arm9; ROM address 0207b6c0. No matching claim. */
#include "types.h"
#include "deps/0207b6c0_CharacterKartContext_SetNsbcaAnimAt.h"

void CharacterKartContext_SetNsbcaAnimAt(int param_1,undefined2 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    uVar1 = param_1 + 8U & 3;
    uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
    Animation_SetWithBlendAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2);
    return;
  }
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2);
  return;
}

