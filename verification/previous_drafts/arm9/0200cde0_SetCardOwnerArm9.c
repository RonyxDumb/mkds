/* Decompiled C draft; module arm9; ROM address 0200cde0. No matching claim. */
#include "types.h"
#include "deps/0200cde0_SetCardOwnerArm9.h"

void SetCardOwnerArm9(void)

{
  *puRam0200cdf4 = *puRam0200cdf4 & 0xf7ff;
  return;
}

