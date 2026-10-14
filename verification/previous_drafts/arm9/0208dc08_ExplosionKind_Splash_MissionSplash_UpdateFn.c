/* Decompiled C draft; module arm9; ROM address 0208dc08. No matching claim. */
#include "types.h"
#include "deps/0208dc08_ExplosionKind_Splash_MissionSplash_UpdateFn.h"

void ExplosionKind_Splash_MissionSplash_UpdateFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0xa8U & 3;
  uVar4 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar3 = param_1 + 0xacU & 3;
  uVar2 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) <=
      (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x88) = 1;
    return;
  }
  uVar1 = param_1 + 0x90U & 3;
  uVar3 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_Update(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    Animation_Update();
    return;
  }
  return;
}

