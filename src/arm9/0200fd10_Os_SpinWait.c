/* Decompiled C draft; module arm9; ROM address 0200fd10. No matching claim. */
#include "types.h"
#include "deps/0200fd10_Os_SpinWait.h"

void Os_SpinWait(uint param_1)

{
  bool bVar1;
  
  do {
    bVar1 = 3 < param_1;
    param_1 = param_1 - 4;
  } while (bVar1);
  return;
}

