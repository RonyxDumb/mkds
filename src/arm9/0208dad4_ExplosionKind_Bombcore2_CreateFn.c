/* Decompiled C draft; module arm9; ROM address 0208dad4. No matching claim. */
#include "types.h"
#include "deps/0208dad4_ExplosionKind_Bombcore2_CreateFn.h"

void ExplosionKind_Bombcore2_CreateFn(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x90U & 3;
  uVar2 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  uVar1 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  uVar1 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  Animation_SetAt(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  *(undefined4 *)(param_1 + 0x9c) = 0x1000;
  *(undefined4 *)(param_1 + 0xa0) = 0x1000;
  *(undefined4 *)(param_1 + 0xa4) = 0x1000;
  if (param_2 != 0) {
    func_0208b7bc(8,param_1 + 0x74);
    func_0208b7bc(9,param_1 + 0x74);
    func_0208b7bc(10,param_1 + 0x74);
    return;
  }
  return;
}

