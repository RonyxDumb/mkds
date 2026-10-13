/* Decompiled C draft; module arm9; ROM address 0208dc50. No matching claim. */
#include "types.h"
#include "deps/0208dc50_ExplosionKind_MissionSplash_CreateFn.h"

void ExplosionKind_MissionSplash_CreateFn(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = uRam0208dcb0;
  *(undefined4 *)(param_1 + 0x9c) = uRam0208dcb0;
  *(undefined4 *)(param_1 + 0xa0) = uVar1;
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  uVar3 = param_1 + 0x90U & 3;
  uVar2 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0);
  *(undefined4 *)(param_1 + 0xac) = 0x20;
  uVar3 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    Animation_SetAt(uVar3,0);
  }
  func_0208b7bc(uRam0208dcb4,param_1 + 0x74);
  func_0208b7bc(uRam0208dcb8,param_1 + 0x74);
  return;
}

