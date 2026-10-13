/* Decompiled C draft; module arm9; ROM address 020370d4. No matching claim. */
#include "types.h"
#include "deps/020370d4_func_020370d4.h"

void func_020370d4(short param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = psRam020371a0;
  sVar1 = *psRam020371a0;
  if ((((sVar1 != 2) && (sVar1 != 1)) && (psRam020371a0[1] = 0, sVar1 != 2)) && (sVar1 != 1)) {
    if (sVar1 == 3) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam020371a0;
    *psRam020371a0 = 1;
    psVar2[3] = param_1;
  }
  psVar2 = psRam020371a4;
  sVar1 = *psRam020371a4;
  if (sVar1 == 2) {
    return;
  }
  if (sVar1 == 1) {
    return;
  }
  psRam020371a4[1] = 0;
  if (sVar1 != 2) {
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                                 ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
      }
      else {
        psVar2[2] = 0;
      }
      psVar2 = psRam020371a4;
      *psRam020371a4 = 1;
      psVar2[3] = param_1;
      return;
    }
    return;
  }
  return;
}

