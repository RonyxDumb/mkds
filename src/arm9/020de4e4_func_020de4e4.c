/* Decompiled C draft; module arm9; ROM address 020de4e4. No matching claim. */
#include "types.h"
#include "deps/020de4e4_func_020de4e4.h"

void func_020de4e4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(short *)(param_2 + 0x8e) == 0) {
    uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_020e67c4(*(uint *)(uRam020de580 & 0xfffffffc) >> (uRam020de580 & 3) * 8 |
                  *(uint *)(uRam020de580 & 0xfffffffc) << (uRam020de580 & 3) * -8 + 0x20,uVar1,
                  param_2 + 0x1c,0,param_4);
    return;
  }
  func_020e6a18(*(uint *)(uRam020de584 & 0xfffffffc) >> (uRam020de584 & 3) * 8 |
                *(uint *)(uRam020de584 & 0xfffffffc) << (uRam020de584 & 3) * -8 + 0x20);
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_020e66e4(*(uint *)(uRam020de584 & 0xfffffffc) >> (uRam020de584 & 3) * 8 |
                *(uint *)(uRam020de584 & 0xfffffffc) << (uRam020de584 & 3) * -8 + 0x20,uVar1,
                *(undefined2 *)(param_2 + 0xac),param_2 + 0x1c,0,param_4);
  func_020e6a18(*(uint *)(uRam020de580 & 0xfffffffc) >> (uRam020de580 & 3) * 8 |
                *(uint *)(uRam020de580 & 0xfffffffc) << (uRam020de580 & 3) * -8 + 0x20);
  return;
}

