/* Decompiled C draft; module arm9; ROM address 02036f10. No matching claim. */
#include "types.h"
#include "deps/02036f10_Bright_FadeOutBlack.h"

void Bright_FadeOutBlack(short param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = psRam02036fe4;
  if ((*psRam02036fe4 != 0) && ((*psRam02036fe4 != 3 || (psRam02036fe4[1] != 0)))) {
    sVar1 = *psRam02036fe4;
    psRam02036fe4[1] = 0;
    if (sVar1 == 1) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam02036fe4;
    *psRam02036fe4 = 3;
    psVar2[3] = param_1;
  }
  psVar2 = psRam02036fe8;
  if (*psRam02036fe8 != 0) {
    if ((*psRam02036fe8 == 3) && (psRam02036fe8[1] == 0)) {
      return;
    }
    sVar1 = *psRam02036fe8;
    psRam02036fe8[1] = 0;
    if (sVar1 == 1) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam02036fe8;
    *psRam02036fe8 = 3;
    psVar2[3] = param_1;
    return;
  }
  return;
}

