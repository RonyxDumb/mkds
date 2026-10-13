/* Decompiled C draft; module arm9; ROM address 0200da58. No matching claim. */
#include "types.h"
#include "deps/0200da58_Util_PrintContext_AppendString.h"

void Util_PrintContext_AppendString(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0 < (int)param_3) {
    uVar4 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    uVar3 = 0;
    if (param_3 < uVar4) {
      uVar4 = param_3;
    }
    if (uVar4 != 0) {
      do {
        uVar1 = (uint)(param_1 + 1) & 3;
        uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
        *(undefined1 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + uVar3) =
             *(undefined1 *)(param_2 + uVar3);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar4);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - uVar4;
    uVar4 = (uint)(param_1 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[1] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + param_3;
    return;
  }
  return;
}

