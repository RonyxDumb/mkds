/* Decompiled C draft; module arm9; ROM address 02036e20. No matching claim. */
#include "types.h"
#include "deps/02036e20_func_02036e20.h"

void func_02036e20(short param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = psRam02036f0c;
  psVar2 = psRam02036f08;
  if (param_2 == 0) {
    if (*psRam02036f0c == 0) {
      return;
    }
    if ((*psRam02036f0c == 3) && (psRam02036f0c[1] == 1)) {
      return;
    }
    sVar1 = *psRam02036f0c;
    psRam02036f0c[1] = 1;
    if (sVar1 == 1) {
      psVar3[2] = (short)((int)((int)param_1 * (int)psVar3[4] +
                               ((uint)((int)param_1 * (int)psVar3[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar3[2] = 0;
    }
    psVar2 = psRam02036f0c;
    *psRam02036f0c = 3;
    psVar2[3] = param_1;
    return;
  }
  if (*psRam02036f08 == 0) {
    return;
  }
  if ((*psRam02036f08 == 3) && (psRam02036f08[1] == 1)) {
    return;
  }
  sVar1 = *psRam02036f08;
  psRam02036f08[1] = 1;
  if (sVar1 == 1) {
    psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                             ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
  }
  else {
    psVar2[2] = 0;
  }
  psVar2 = psRam02036f08;
  *psRam02036f08 = 3;
  psVar2[3] = param_1;
  return;
}

