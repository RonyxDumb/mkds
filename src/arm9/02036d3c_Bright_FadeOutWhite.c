/* Decompiled C draft; module arm9; ROM address 02036d3c. No matching claim. */
#include "types.h"
#include "deps/02036d3c_Bright_FadeOutWhite.h"

void Bright_FadeOutWhite(short param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = psRam02036e18;
  if ((*psRam02036e18 != 0) && ((*psRam02036e18 != 3 || (psRam02036e18[1] != 1)))) {
    sVar1 = *psRam02036e18;
    psRam02036e18[1] = 1;
    if (sVar1 == 1) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam02036e18;
    *psRam02036e18 = 3;
    psVar2[3] = param_1;
  }
  psVar2 = psRam02036e1c;
  if (*psRam02036e1c != 0) {
    if ((*psRam02036e1c == 3) && (psRam02036e1c[1] == 1)) {
      return;
    }
    sVar1 = *psRam02036e1c;
    psRam02036e1c[1] = 1;
    if (sVar1 == 1) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam02036e1c;
    *psRam02036e1c = 3;
    psVar2[3] = param_1;
    return;
  }
  return;
}

