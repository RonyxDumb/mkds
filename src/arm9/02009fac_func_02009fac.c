/* Decompiled C draft; module arm9; ROM address 02009fac. No matching claim. */
#include "types.h"
#include "deps/02009fac_func_02009fac.h"

undefined4 func_02009fac(uint param_1,uint param_2,int param_3)

{
  if ((uRam02009fe8 < param_1) || (param_1 < 0xe4)) {
    return 0;
  }
  if ((param_2 < 0x11) && (7 < param_2)) {
    if ((int)((param_1 + 0x26) * 4 + iRam02009fec + ((param_2 + 0x20) * 4 + 0x70) * param_3) <
        iRam02009ff0) {
      return 1;
    }
    return 0;
  }
  return 0;
}

