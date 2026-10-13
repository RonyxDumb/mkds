/* Decompiled C draft; module arm9; ROM address 02134c94. No matching claim. */
#include "types.h"
#include "deps/02134c94_func_02134c94.h"

undefined4 func_02134c94(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != (uint *)0x0) {
    uVar2 = param_2 & 0xff |
            (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
    uVar1 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    return 1;
  }
  return 0;
}

