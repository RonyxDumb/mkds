/* Decompiled C draft; module arm9; ROM address 0214a61c. No matching claim. */
#include "types.h"
#include "deps/0214a61c_G3X_GetMtxStackLevelPV.h"

undefined4 G3X_GetMtxStackLevelPV(uint *param_1)

{
  undefined4 uVar1;
  
  if (((*(uint *)(uRam0214a644 & 0xfffffffc) >> (uRam0214a644 & 3) * 8 |
       *(uint *)(uRam0214a644 & 0xfffffffc) << (uRam0214a644 & 3) * -8 + 0x20) & 0x4000) == 0) {
    *param_1 = ((*(uint *)(uRam0214a644 & 0xfffffffc) >> (uRam0214a644 & 3) * 8 |
                *(uint *)(uRam0214a644 & 0xfffffffc) << (uRam0214a644 & 3) * -8 + 0x20) & 0x1f00) >>
               8;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

