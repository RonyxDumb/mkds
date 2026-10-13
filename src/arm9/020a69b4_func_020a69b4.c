/* Decompiled C draft; module arm9; ROM address 020a69b4. No matching claim. */
#include "types.h"
#include "deps/020a69b4_func_020a69b4.h"

void func_020a69b4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  uVar3 = param_2 + 0xa8U & 3;
  uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  if (0 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    uStack_20 = 0x1e;
    func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_20),1);
    uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_01ff9048(0x19,uVar1,0xc);
    uVar3 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 != 0x1000) {
      uStack_1c = uVar3;
      uStack_18 = uVar3;
      uStack_14 = uVar3;
      func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_1c),3);
    }
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    uVar3 = param_2 + 0xb8U & 3;
    uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    StructMapObject_SomeFn_8
              ((undefined4 *)(uintptr_t)(*(uint *)(uRam020a6a8c & 0xfffffffc) >> (uRam020a6a8c & 3) * 8 |
               *(uint *)(uRam020a6a8c & 0xfffffffc) << (uRam020a6a8c & 3) * -8 + 0x20),
               uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0);
    uVar3 = param_2 + 0xb0U & 3;
    uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    StructMapObject_SetNsbtpFrame
              (*(uint *)(uRam020a6a8c & 0xfffffffc) >> (uRam020a6a8c & 3) * 8 |
               *(uint *)(uRam020a6a8c & 0xfffffffc) << (uRam020a6a8c & 3) * -8 + 0x20,
               (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xffff);
    DrawObject2D3D(param_1,*(uint *)(uRam020a6a8c & 0xfffffffc) >> (uRam020a6a8c & 3) * 8 |
                           *(uint *)(uRam020a6a8c & 0xfffffffc) << (uRam020a6a8c & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

