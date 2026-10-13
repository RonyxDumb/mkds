/* Decompiled C draft; module arm7; ROM address 0600bce4. No matching claim. */
#include "types.h"
#include "deps/0600bce4_FUN_0600bce4.h"

undefined4 FUN_0600bce4(ushort *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*param_1 & 1) == 0) {
    FUN_0600a954((undefined2 *)(uintptr_t)((*(uint *)(DAT_0600bd3c & 0xfffffffc) >> (DAT_0600bd3c & 3) * 8 |
                 *(uint *)(DAT_0600bd3c & 0xfffffffc) << (DAT_0600bd3c & 3) * -8 + 0x20) + 0x324),
                 param_1);
    FUN_0600a954((undefined2 *)(uintptr_t)(DAT_0600bd40),param_1);
    uVar4 = *(uint *)(DAT_0600bd3c & 0xfffffffc) >> (DAT_0600bd3c & 3) * 8 |
            *(uint *)(DAT_0600bd3c & 0xfffffffc) << (DAT_0600bd3c & 3) * -8 + 0x20;
    uVar3 = uVar4 + 0x340;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar4 + 0x340) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 2;
    uVar2 = 0;
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

