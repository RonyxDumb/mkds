/* Decompiled C draft; module arm9; ROM address 0214a5f0. No matching claim. */
#include "types.h"
#include "deps/0214a5f0_G3X_GetMtxStackLevelPJ.h"

undefined4 G3X_GetMtxStackLevelPJ(uint *param_1)

{
  undefined4 uVar1;
  
  if (((*(uint *)(uRam0214a618 & 0xfffffffc) >> (uRam0214a618 & 3) * 8 |
       *(uint *)(uRam0214a618 & 0xfffffffc) << (uRam0214a618 & 3) * -8 + 0x20) & 0x4000) == 0) {
    *param_1 = ((*(uint *)(uRam0214a618 & 0xfffffffc) >> (uRam0214a618 & 3) * 8 |
                *(uint *)(uRam0214a618 & 0xfffffffc) << (uRam0214a618 & 3) * -8 + 0x20) & 0x2000) >>
               0xd;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

