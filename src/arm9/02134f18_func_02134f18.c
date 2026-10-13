/* Decompiled C draft; module arm9; ROM address 02134f18. No matching claim. */
#include "types.h"
#include "deps/02134f18_func_02134f18.h"

void func_02134f18(uint *param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_2 = param_2 & 0xff;
  if (0x1f < param_3) {
    uVar4 = -(int)param_1 & 3;
    if (uVar4 != 0) {
      param_3 = param_3 - uVar4;
      puVar1 = param_1;
      do {
        uVar3 = param_2 | (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) &
                          0xffffff00;
        uVar2 = (4 - ((uint)puVar1 & 3)) * 8 & 0x1f;
        param_1 = (uint *)((int)puVar1 + 1);
        *puVar1 = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
        uVar4 = uVar4 - 1;
        puVar1 = param_1;
      } while (uVar4 != 0);
    }
    if (param_2 != 0) {
      param_2 = param_2 | param_2 << 0x18 | param_2 << 0x10 | param_2 << 8;
    }
    for (uVar4 = param_3 >> 5; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1[4] = param_2;
      param_1[5] = param_2;
      param_1[6] = param_2;
      param_1[7] = param_2;
      param_1 = param_1 + 8;
    }
    for (uVar4 = (param_3 & 0x1f) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *param_1 = param_2;
      param_1 = param_1 + 1;
    }
    param_3 = param_3 & 3;
  }
  if (param_3 == 0) {
    return;
  }
  do {
    uVar2 = param_2 & 0xff |
            (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
    uVar4 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar2 >> uVar4 | uVar2 << 0x20 - uVar4;
    param_3 = param_3 - 1;
    param_1 = (uint *)((int)param_1 + 1);
  } while (param_3 != 0);
  return;
}

