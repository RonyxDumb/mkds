/* Decompiled C draft; module arm9; ROM address 0208dd6c. No matching claim. */
#include "types.h"
#include "deps/0208dd6c_ExplosionKind_Bombcore_CreateFn.h"

void ExplosionKind_Bombcore_CreateFn(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x90U & 3;
  uVar3 = *(uint *)(param_1 + 0x90U & 0xfffffffc);
  Animation_SetAt(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0);
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  Animation_SetAt(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0);
  uVar1 = param_1 + 0x98U & 3;
  uVar3 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  Animation_SetAt(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0);
  uVar2 = uRam0208ddf0;
  *(undefined4 *)(param_1 + 0x9c) = uRam0208ddf0;
  *(undefined4 *)(param_1 + 0xa0) = uVar2;
  *(undefined4 *)(param_1 + 0xa4) = uVar2;
  if (param_2 != 0) {
    func_0208b7bc(0x22,param_1 + 0x74);
    func_0208b7bc(1,param_1 + 0x74);
    func_0208b7bc(2,param_1 + 0x74);
    return;
  }
  return;
}

