/* Decompiled C draft; module arm9; ROM address 0203a440. No matching claim. */
#include "types.h"
#include "deps/0203a440_HasTouchPressed.h"

bool HasTouchPressed(int param_1)

{
  short sVar1;
  bool bVar2;
  
  sVar1 = *(short *)(iRam0203a484 + param_1 * 0x5c);
  bVar2 = false;
  if ((sVar1 == 0) && (*(ushort *)(iRam0203a488 + param_1 * 0x5c) < 5)) {
    bVar2 = true;
  }
  if (bVar2) {
    return true;
  }
  return sVar1 != 0;
}

