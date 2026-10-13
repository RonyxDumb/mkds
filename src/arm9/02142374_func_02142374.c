/* Decompiled C draft; module arm9; ROM address 02142374. No matching claim. */
#include "types.h"
#include "deps/02142374_func_02142374.h"

undefined4 func_02142374(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
    if (uVar2 < 0x80) {
      uVar3 = iRam021423e0 + uVar2 & 3;
      uVar2 = *(uint *)(iRam021423e0 + uVar2 & 0xfffffffc);
      uVar2 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff;
    }
    uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff;
    if (uVar3 < 0x80) {
      uVar1 = iRam021423e0 + uVar3 & 3;
      uVar3 = *(uint *)(iRam021423e0 + uVar3 & 0xfffffffc);
      uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xff;
    }
    if (uVar2 < uVar3) {
      return 0xffffffff;
    }
    if (uVar3 < uVar2) {
      return 1;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (uVar2 != 0);
  return 0;
}

