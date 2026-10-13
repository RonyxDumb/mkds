/* Decompiled C draft; module arm9; ROM address 0208dd10. No matching claim. */
#include "types.h"
#include "deps/0208dd10_ExplosionKind_Bombcore_UpdateFn.h"

void ExplosionKind_Bombcore_UpdateFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0xa8U & 3;
  uVar1 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0x26) {
    func_0208b7bc(3,param_1 + 0x74);
    return;
  }
  if (uVar2 < 0x37) {
    uVar2 = param_1 + 0x90U & 3;
    uVar1 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
    Animation_Update(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    uVar2 = param_1 + 0x94U & 3;
    uVar1 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    Animation_Update(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    uVar2 = param_1 + 0x98U & 3;
    uVar1 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
    Animation_Update(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    return;
  }
  *(undefined4 *)(param_1 + 0x88) = 1;
  return;
}

