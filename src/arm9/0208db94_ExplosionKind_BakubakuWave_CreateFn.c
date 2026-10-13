/* Decompiled C draft; module arm9; ROM address 0208db94. No matching claim. */
#include "types.h"
#include "deps/0208db94_ExplosionKind_BakubakuWave_CreateFn.h"

void ExplosionKind_BakubakuWave_CreateFn(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x90U & 3;
  uVar2 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  *(undefined4 *)(param_1 + 0x9c) = 0x5800;
  *(undefined4 *)(param_1 + 0xa0) = 0x5800;
  *(undefined4 *)(param_1 + 0xa4) = 0x5800;
  *(undefined4 *)(param_1 + 0xac) = 0x27;
  uVar1 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  if (param_2 != 0) {
    func_0208b7bc(0x40,param_1 + 0x74);
    func_0208b7bc(0x41,param_1 + 0x74);
    return;
  }
  return;
}

