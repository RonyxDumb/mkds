/* Decompiled C draft; module arm9; ROM address 0214f72c. No matching claim. */
#include "types.h"
#include "deps/0214f72c_PMi_SetLCDPower.h"

void PMi_SetLCDPower(int param_1)

{
  if (param_1 != 1) {
    param_1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0214f744. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0214f748)(param_1,0,0,1);
  return;
}

