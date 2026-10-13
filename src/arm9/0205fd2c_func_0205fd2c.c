/* Decompiled C draft; module arm9; ROM address 0205fd2c. No matching claim. */
#include "types.h"
#include "deps/0205fd2c_func_0205fd2c.h"

undefined4 func_0205fd2c(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = CheckExtraKartUnlockFlags_from_thumb();
  uVar2 = (uint)*(byte *)(param_3 * 0xd +
                          (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + param_2 +
                         6);
  if ((uVar2 != 0) && (uVar2 <= uVar1)) {
    return 1;
  }
  return 0;
}

