/* Decompiled C draft; module arm9; ROM address 0200db20. No matching claim. */
#include "types.h"
#include "deps/0200db20_Util_PrintContext_ApppendChar.h"

void Util_PrintContext_ApppendChar(int *param_1,undefined1 param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *(undefined1 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) = param_2;
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) - 1;
  }
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[1] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  return;
}

