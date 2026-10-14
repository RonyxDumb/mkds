/* Decompiled C draft; module arm9; ROM address 0200dab8. No matching claim. */
#include "types.h"
#include "deps/0200dab8_Util_PrintContext_FillWith.h"

void Util_PrintContext_FillWith(int *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0 < (int)param_3) {
    uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar4 = 0;
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    if (uVar3 != 0) {
      do {
        uVar1 = (uint)(param_1 + 1) & 3;
        uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        *(undefined1 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + uVar4) = param_2;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - uVar3;
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + param_3;
    return;
  }
  return;
}

