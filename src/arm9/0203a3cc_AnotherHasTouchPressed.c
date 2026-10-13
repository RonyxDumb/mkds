/* Decompiled C draft; module arm9; ROM address 0203a3cc. No matching claim. */
#include "types.h"
#include "deps/0203a3cc_AnotherHasTouchPressed.h"

bool AnotherHasTouchPressed(int param_1)

{
  bool bVar1;
  
  param_1 = param_1 * 0x5c;
  bVar1 = false;
  if ((*(short *)(iRam0203a420 + param_1) == 0) && (*(ushort *)(iRam0203a424 + param_1) < 5)) {
    bVar1 = true;
  }
  if (bVar1) {
    return false;
  }
  if (*(short *)(iRam0203a428 + param_1) != 0) {
    return false;
  }
  return *(short *)(iRam0203a420 + param_1) != 0;
}

