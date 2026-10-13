/* Decompiled C draft; module arm9; ROM address 0200ce30. No matching claim. */
#include "types.h"
#include "deps/0200ce30_SetCartOwnerArm7.h"

void SetCartOwnerArm7(void)

{
  *puRam0200ce44 = *puRam0200ce44 | 0x80;
  return;
}

