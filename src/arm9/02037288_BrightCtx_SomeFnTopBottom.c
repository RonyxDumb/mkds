/* Decompiled C draft; module arm9; ROM address 02037288. No matching claim. */
#include "types.h"
#include "deps/02037288_BrightCtx_SomeFnTopBottom.h"

void BrightCtx_SomeFnTopBottom(short param_1)

{
  short sVar1;
  short *psVar2;
  
  sVar1 = *psRam0203732c;
  if ((sVar1 != 2) && (sVar1 != 1)) {
    if (sVar1 == 3) {
      psRam0203732c[2] =
           (short)((int)((int)param_1 * (int)psRam0203732c[4] +
                        ((uint)((int)param_1 * (int)psRam0203732c[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psRam0203732c[2] = 0;
    }
    psVar2 = psRam0203732c;
    *psRam0203732c = 1;
    psVar2[3] = param_1;
  }
  sVar1 = *psRam02037330;
  if (sVar1 != 2) {
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        psRam02037330[2] =
             (short)((int)((int)param_1 * (int)psRam02037330[4] +
                          ((uint)((int)param_1 * (int)psRam02037330[4] >> 3) >> 0x1c)) >> 4);
      }
      else {
        psRam02037330[2] = 0;
      }
      psVar2 = psRam02037330;
      *psRam02037330 = 1;
      psVar2[3] = param_1;
      return;
    }
    return;
  }
  return;
}

