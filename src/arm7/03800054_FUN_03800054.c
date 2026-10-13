/* Decompiled C draft; module arm7; ROM address 03800054. No matching claim. */
#include "types.h"
#include "deps/03800054_FUN_03800054.h"

void FUN_03800054(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = (*(uint *)(DAT_03800114 & 0xfffffffc) >> (DAT_03800114 & 3) * 8 |
          *(uint *)(DAT_03800114 & 0xfffffffc) << (DAT_03800114 & 3) * -8 + 0x20) + 0x20;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  iVar2 = FUN_038005c8();
  if (iVar2 != 0) {
    for (; param_3 != 0; param_3 = param_3 - uVar6) {
      uVar6 = uVar7 - (param_1 & uVar7 - 1);
      if (param_3 < uVar6) {
        uVar6 = param_3;
      }
      FUN_038003fc();
      uVar3 = (*(uint *)(DAT_03800114 & 0xfffffffc) >> (DAT_03800114 & 3) * 8 |
              *(uint *)(DAT_03800114 & 0xfffffffc) << (DAT_03800114 & 3) * -8 + 0x20) + 0x24;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      FUN_038006f0((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 1 + uVar6);
      FUN_03800350(param_1,10);
      FUN_03800538(param_2,0,uVar6,DAT_03800118);
      uVar5 = *(uint *)(DAT_03800114 & 0xfffffffc) >> (DAT_03800114 & 3) * 8 |
              *(uint *)(DAT_03800114 & 0xfffffffc) << (DAT_03800114 & 3) * -8 + 0x20;
      uVar3 = uVar5 + 0x2c;
      uVar1 = uVar3 & 3;
      uVar4 = *(uint *)(uVar3 & 0xfffffffc);
      uVar5 = uVar5 + 0x30;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      FUN_03800610(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
      uVar5 = *(uint *)(DAT_03800114 & 0xfffffffc) >> (DAT_03800114 & 3) * 8 |
              *(uint *)(DAT_03800114 & 0xfffffffc) << (DAT_03800114 & 3) * -8 + 0x20;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
        return;
      }
      param_2 = param_2 + uVar6;
      param_1 = param_1 + uVar6;
    }
  }
  return;
}

