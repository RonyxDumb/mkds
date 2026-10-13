/* Decompiled C draft; module arm9; ROM address 020e5c6c. No matching claim. */
#include "types.h"
#include "deps/020e5c6c_func_020e5c6c.h"

void func_020e5c6c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *(short *)((*(uint *)(uRam020e5d08 & 0xfffffffc) >> (uRam020e5d08 & 3) * 8 |
             *(uint *)(uRam020e5d08 & 0xfffffffc) << (uRam020e5d08 & 3) * -8 + 0x20) + 0x18) =
       (short)((int)(*(ushort *)(param_2 + 0xb8) & 0x10) >> 4);
  if (*(short *)(param_2 + 0x8e) == 0) {
    uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
    func_020e67c4(*(uint *)(uRam020e5d08 & 0xfffffffc) >> (uRam020e5d08 & 3) * 8 |
                  *(uint *)(uRam020e5d08 & 0xfffffffc) << (uRam020e5d08 & 3) * -8 + 0x20,uVar1,
                  param_2 + 0x1c,0,param_4);
    return;
  }
  uVar1 = MaybeGetBBMtxAtPosition(param_2 + 4);
  func_020e66e4(*(uint *)(uRam020e5d08 & 0xfffffffc) >> (uRam020e5d08 & 3) * 8 |
                *(uint *)(uRam020e5d08 & 0xfffffffc) << (uRam020e5d08 & 3) * -8 + 0x20,uVar1,
                *(undefined2 *)(param_2 + 0xac),param_2 + 0x1c,0,param_4);
  return;
}

