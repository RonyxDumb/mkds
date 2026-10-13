/* Decompiled C draft; module arm9; ROM address 020918cc. No matching claim. */
#include "types.h"
#include "deps/020918cc_func_020918cc.h"

void func_020918cc(undefined4 param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_10;
  
  local_10 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_10),1);
  uVar2 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_01ff9048(0x19,uVar2,0xc);
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  uVar1 = param_2 + 0x9cU & 3;
  uVar3 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
  StructMapObject_SetNsbtpFrame
            (*(uint *)(uRam02091950 & 0xfffffffc) >> (uRam02091950 & 3) * 8 |
             *(uint *)(uRam02091950 & 0xfffffffc) << (uRam02091950 & 3) * -8 + 0x20,
             *(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x28));
  DrawObject2D3D(param_1,*(uint *)(uRam02091950 & 0xfffffffc) >> (uRam02091950 & 3) * 8 |
                         *(uint *)(uRam02091950 & 0xfffffffc) << (uRam02091950 & 3) * -8 + 0x20,
                 param_2);
  return;
}

