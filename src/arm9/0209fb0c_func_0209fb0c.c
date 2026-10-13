/* Decompiled C draft; module arm9; ROM address 0209fb0c. No matching claim. */
#include "types.h"
#include "deps/0209fb0c_func_0209fb0c.h"

void func_0209fb0c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_18 [2];
  
  uVar2 = param_2 + 0xa4U & 3;
  uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  local_18[0] = 0x1e;
  iVar1 = (int)(0x16c000 - (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) >> 0xc;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(local_18),1);
  uVar2 = param_2 + 0xacU & 3;
  uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  if (uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) {
    uVar3 = func_020e6c3c(param_2 + 4,iVar1,iVar1);
    func_01ff9048(0x19,uVar3,0xc);
  }
  else {
    uVar3 = func_020e6c3c(param_2 + 4,-iVar1,iVar1);
    func_01ff9048(0x19,uVar3,0xc);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam0209fbe0 & 0xfffffffc) >> (uRam0209fbe0 & 3) * 8 |
             *(uint *)(uRam0209fbe0 & 0xfffffffc) << (uRam0209fbe0 & 3) * -8 + 0x20,
             *(undefined2 *)(param_2 + 0xa0));
  StructMapObject_SomeFn_9
            (param_1,*(uint *)(uRam0209fbe0 & 0xfffffffc) >> (uRam0209fbe0 & 3) * 8 |
                     *(uint *)(uRam0209fbe0 & 0xfffffffc) << (uRam0209fbe0 & 3) * -8 + 0x20);
  DrawObject2D3D(param_1,*(uint *)(uRam0209fbe0 & 0xfffffffc) >> (uRam0209fbe0 & 3) * 8 |
                         *(uint *)(uRam0209fbe0 & 0xfffffffc) << (uRam0209fbe0 & 3) * -8 + 0x20,
                 param_2);
  return;
}

