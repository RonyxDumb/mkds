/* Decompiled C draft; module arm9; ROM address 0214eadc. No matching claim. */
#include "types.h"
#include "deps/0214eadc_ComputeSomeScreenCalibrationStuff.h"

undefined4 ComputeSomeScreenCalibrationStuff(undefined2 *param_1)

{
  int iVar1;
  
  if ((((*(short *)(iRam0214eb84 + 0x58) != 0) || (*(short *)(iRam0214eb84 + 0x5e) != 0)) ||
      (*(short *)(iRam0214eb84 + 0x5a) != 0)) || (*(short *)(iRam0214eb84 + 0x60) != 0)) {
    iVar1 = MaybeCheckScreenCalibration
                      (param_1,*(short *)(iRam0214eb84 + 0x58),*(short *)(iRam0214eb84 + 0x5a),
                       *(undefined1 *)(iRam0214eb84 + 0x5c),*(undefined1 *)(iRam0214eb84 + 0x5d),
                       *(short *)(iRam0214eb84 + 0x5e),*(short *)(iRam0214eb84 + 0x60),
                       *(undefined1 *)(iRam0214eb84 + 0x62),*(undefined1 *)(iRam0214eb84 + 99));
    if (iVar1 == 0) {
      return 1;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return 1;
}

