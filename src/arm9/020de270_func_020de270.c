/* Decompiled C draft; module arm9; ROM address 020de270. No matching claim. */
#include "types.h"
#include "deps/020de270_func_020de270.h"

void func_020de270(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  func_020ddaa0(param_2 + 0xa4,
                *(uint *)(uRam020de2d0 & 0xfffffffc) >> (uRam020de2d0 & 3) * 8 |
                *(uint *)(uRam020de2d0 & 0xfffffffc) << (uRam020de2d0 & 3) * -8 + 0x20);
  uVar1 = param_2 + 0xf4U & 3;
  uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020dda38(param_2 + 0xa4,
                  *(uint *)(uRam020de2d4 & 0xfffffffc) >> (uRam020de2d4 & 3) * 8 |
                  *(uint *)(uRam020de2d4 & 0xfffffffc) << (uRam020de2d4 & 3) * -8 + 0x20,param_2 + 4
                  ,param_3);
    return;
  }
  return;
}

