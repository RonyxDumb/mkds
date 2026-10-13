/* Decompiled C draft; module arm7; ROM address 0380011c. No matching claim. */
#include "types.h"
#include "deps/0380011c_FUN_0380011c.h"

void FUN_0380011c(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (*(uint *)(DAT_038001dc & 0xfffffffc) >> (DAT_038001dc & 3) * 8 |
          *(uint *)(DAT_038001dc & 0xfffffffc) << (DAT_038001dc & 3) * -8 + 0x20) + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  iVar1 = FUN_038005c8();
  if (iVar1 != 0) {
    for (; param_3 != 0; param_3 = param_3 - uVar4) {
      uVar4 = uVar5 - (param_1 & uVar5 - 1);
      if (param_3 < uVar4) {
        uVar4 = param_3;
      }
      FUN_038003fc();
      uVar2 = (*(uint *)(DAT_038001dc & 0xfffffffc) >> (DAT_038001dc & 3) * 8 |
              *(uint *)(DAT_038001dc & 0xfffffffc) << (DAT_038001dc & 3) * -8 + 0x20) + 0x24;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      FUN_038006f0((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1 + uVar4);
      FUN_03800350(param_1,2);
      FUN_03800538(param_2,0,uVar4,DAT_038001e0);
      uVar2 = (*(uint *)(DAT_038001dc & 0xfffffffc) >> (DAT_038001dc & 3) * 8 |
              *(uint *)(DAT_038001dc & 0xfffffffc) << (DAT_038001dc & 3) * -8 + 0x20) + 0x28;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      FUN_03800610(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,0);
      uVar3 = *(uint *)(DAT_038001dc & 0xfffffffc) >> (DAT_038001dc & 3) * 8 |
              *(uint *)(DAT_038001dc & 0xfffffffc) << (DAT_038001dc & 3) * -8 + 0x20;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0) {
        return;
      }
      param_2 = param_2 + uVar4;
      param_1 = param_1 + uVar4;
    }
  }
  return;
}

