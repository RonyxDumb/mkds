/* Decompiled C draft; module arm9; ROM address 020a9cd4. No matching claim. */
#include "types.h"
#include "deps/020a9cd4_func_020a9cd4.h"

void func_020a9cd4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_38;
  undefined1 auStack_34 [40];
  uint uVar4;
  
  local_38 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_38),1);
  uVar2 = func_020e6cf8(param_2 + 4);
  func_01ff9048(0x19,uVar2,0xc);
  uVar4 = param_2 + 0xa0U & 3;
  uVar3 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    iVar1 = (int)(uVar4 & 0xffff) >> 4;
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_34),(int)*(short *)(iRam020a9d90 + iVar1 * 4),
               (int)*(short *)(iRam020a9d90 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_34),9);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  DrawObject2D3D(param_1,*(uint *)(uRam020a9d94 & 0xfffffffc) >> (uRam020a9d94 & 3) * 8 |
                         *(uint *)(uRam020a9d94 & 0xfffffffc) << (uRam020a9d94 & 3) * -8 + 0x20,
                 param_2);
  return;
}

