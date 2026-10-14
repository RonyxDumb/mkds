/* Decompiled C draft; module arm9; ROM address 0209bbd0. No matching claim. */
#include "types.h"
#include "deps/0209bbd0_StructMapObject_SomeFn_9.h"

void StructMapObject_SomeFn_9(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0xcU & 3;
  uVar2 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020e6a18();
    return;
  }
  return;
}

