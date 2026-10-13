/* Decompiled C draft; module arm9; ROM address 020483a0. No matching claim. */
#include "types.h"
#include "deps/020483a0_FormatResultCarc_from_thumb.h"

void FormatResultCarc_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = uRam020483d4;
  if (*(int *)(*piRam020483cc + 0x78) == 1) {
    uVar1 = uRam020483d0;
  }
  Util_SNPrintF(param_1,0x80,uRam020483dc,*(undefined4 *)(iRam020483e0 + 0x50),uVar1,uRam020483d8);
  return;
}

