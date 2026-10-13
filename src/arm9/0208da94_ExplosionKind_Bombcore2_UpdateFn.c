/* Decompiled C draft; module arm9; ROM address 0208da94. No matching claim. */
#include "types.h"
#include "deps/0208da94_ExplosionKind_Bombcore2_UpdateFn.h"

void ExplosionKind_Bombcore2_UpdateFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xa8U & 3;
  uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x37) {
    uVar1 = param_1 + 0x90U & 3;
    uVar2 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
    Animation_Update(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x94U & 3;
    uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    Animation_Update(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x98U & 3;
    uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
    Animation_Update(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  return;
}

