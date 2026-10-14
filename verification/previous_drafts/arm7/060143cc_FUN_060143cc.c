/* Decompiled C draft; module arm7; ROM address 060143cc. No matching claim. */
#include "types.h"
#include "deps/060143cc_FUN_060143cc.h"

void FUN_060143cc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(DAT_06014460 & 0xfffffffc) >> (DAT_06014460 & 3) * 8 |
          *(uint *)(DAT_06014460 & 0xfffffffc) << (DAT_06014460 & 3) * -8 + 0x20) + param_1 * 0xc +
          0x194;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  while (uVar1 = uVar2, uVar1 != 0xffffffff) {
    uVar2 = FUN_06008e48(uVar1);
    if (param_1 != 2) {
      FUN_0600ec88(uVar1 + 0x10);
    }
    *(undefined2 *)(uVar1 + 0x18) = 2;
    if (param_2 != 0) {
      FUN_060125a8((*(uint *)(DAT_06014460 & 0xfffffffc) >> (DAT_06014460 & 3) * 8 |
                   *(uint *)(DAT_06014460 & 0xfffffffc) << (DAT_06014460 & 3) * -8 + 0x20) + 0x194 +
                   param_1 * 0xc,uVar1);
    }
  }
  return;
}

