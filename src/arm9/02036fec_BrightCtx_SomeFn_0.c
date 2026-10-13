/* Decompiled C draft; module arm9; ROM address 02036fec. No matching claim. */
#include "types.h"
#include "deps/02036fec_BrightCtx_SomeFn_0.h"

void BrightCtx_SomeFn_0(short param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = psRam020370d0;
  psVar2 = psRam020370cc;
  if (param_2 == 0) {
    if (*psRam020370d0 == 0) {
      return;
    }
    if ((*psRam020370d0 == 3) && (psRam020370d0[1] == 0)) {
      return;
    }
    sVar1 = *psRam020370d0;
    psRam020370d0[1] = 0;
    if (sVar1 == 1) {
      psVar3[2] = (short)((int)((int)param_1 * (int)psVar3[4] +
                               ((uint)((int)param_1 * (int)psVar3[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar3[2] = 0;
    }
    psVar2 = psRam020370d0;
    *psRam020370d0 = 3;
    psVar2[3] = param_1;
    return;
  }
  if (*psRam020370cc == 0) {
    return;
  }
  if ((*psRam020370cc == 3) && (psRam020370cc[1] == 0)) {
    return;
  }
  sVar1 = *psRam020370cc;
  psRam020370cc[1] = 0;
  if (sVar1 == 1) {
    psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                             ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
  }
  else {
    psVar2[2] = 0;
  }
  psVar2 = psRam020370cc;
  *psRam020370cc = 3;
  psVar2[3] = param_1;
  return;
}

