/* Decompiled C draft; module arm9; ROM address 0214e31c. No matching claim. */
#include "types.h"
#include "deps/0214e31c_WaitForTPFlags.h"

void WaitForTPFlags(ushort param_1)

{
  do {
  } while ((*(ushort *)(iRam0214e330 + 0x36) & param_1) != 0);
  return;
}

