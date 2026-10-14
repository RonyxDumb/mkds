/* Decompiled C draft; module arm9; ROM address 020fbd4c. No matching claim. */
#include "types.h"
#include "deps/020fbd4c_func_020fbd4c.h"

void func_020fbd4c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = VecFx32_Norm(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x27c) = uVar2;
  *(undefined4 *)(param_1 + 0x284) = 0x1e000;
  uVar1 = param_1 + 0x228U & 3;
  uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  if ((uint)*(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x1f8) ==
      (int)*(char *)((*(uint *)(uRam020fbd94 & 0xfffffffc) >> (uRam020fbd94 & 3) * 8 |
                     *(uint *)(uRam020fbd94 & 0xfffffffc) << (uRam020fbd94 & 3) * -8 + 0x20) + 0x62)
     ) {
    *(undefined4 *)(param_1 + 0x270) = 0xdd;
  }
  return;
}

