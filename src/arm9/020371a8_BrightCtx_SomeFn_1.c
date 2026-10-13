/* Decompiled C draft; module arm9; ROM address 020371a8. No matching claim. */
#include "types.h"
#include "deps/020371a8_BrightCtx_SomeFn_1.h"

void BrightCtx_SomeFn_1(short param_1,int param_2)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = psRam02037284;
  psVar2 = psRam02037280;
  if (param_2 == 0) {
    sVar1 = *psRam02037284;
    if (sVar1 == 2) {
      return;
    }
    if (sVar1 == 1) {
      return;
    }
    psRam02037284[1] = 0;
    if (sVar1 == 2) {
      return;
    }
    if (sVar1 != 1) {
      if (sVar1 == 3) {
        psVar3[2] = (short)((int)((int)param_1 * (int)psVar3[4] +
                                 ((uint)((int)param_1 * (int)psVar3[4] >> 3) >> 0x1c)) >> 4);
      }
      else {
        psVar3[2] = 0;
      }
      psVar2 = psRam02037284;
      *psRam02037284 = 1;
      psVar2[3] = param_1;
      return;
    }
    return;
  }
  sVar1 = *psRam02037280;
  if (sVar1 == 2) {
    return;
  }
  if (sVar1 == 1) {
    return;
  }
  psRam02037280[1] = 0;
  if (sVar1 == 2) {
    return;
  }
  if (sVar1 != 1) {
    if (sVar1 == 3) {
      psVar2[2] = (short)((int)((int)param_1 * (int)psVar2[4] +
                               ((uint)((int)param_1 * (int)psVar2[4] >> 3) >> 0x1c)) >> 4);
    }
    else {
      psVar2[2] = 0;
    }
    psVar2 = psRam02037280;
    *psRam02037280 = 1;
    psVar2[3] = param_1;
    return;
  }
  return;
}

