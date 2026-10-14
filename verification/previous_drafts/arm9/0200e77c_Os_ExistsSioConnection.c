/* Decompiled C draft; module arm9; ROM address 0200e77c. No matching claim. */
#include "types.h"
#include "deps/0200e77c_Os_ExistsSioConnection.h"

bool Os_ExistsSioConnection(void)

{
  short *psVar1;
  
  psVar1 = psRam0200e7a8;
  if (*psRam0200e7a4 != 0) {
    psVar1 = psRam0200e7ac;
  }
  return *psVar1 == 1;
}

