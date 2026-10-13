/* Decompiled C draft; module arm9; ROM address 02037334. No matching claim. */
#include "types.h"
#include "deps/02037334_func_02037334.h"

void func_02037334(short param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  
  if (param_2 == 0) {
    sVar1 = *psRam020373e8;
    if (sVar1 == 2) {
      return;
    }
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        psRam020373e8[2] =
             (short)((int)((int)param_1 * (int)psRam020373e8[4] +
                          ((uint)((int)param_1 * (int)psRam020373e8[4] >> 3) >> 0x1c)) >> 4);
      }
      else {
        psRam020373e8[2] = 0;
      }
      psVar2 = psRam020373e8;
      *psRam020373e8 = 1;
      psVar2[3] = param_1;
      return;
    }
    return;
  }
  sVar1 = *psRam020373e4;
  if (sVar1 == 2) {
    return;
  }
  if (sVar1 != 1) {
    if (sVar1 == 3) {
      psRam020373e4[2] =
           (short)((int)((int)param_1 * (int)psRam020373e4[4] +
                        ((uint)((int)param_1 * (int)psRam020373e4[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psRam020373e4[2] = 0;
    }
    psVar2 = psRam020373e4;
    *psRam020373e4 = 1;
    psVar2[3] = param_1;
    return;
  }
  return;
}

