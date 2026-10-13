/* Decompiled C draft; module arm9; ROM address 0200ce48. No matching claim. */
#include "types.h"
#include "deps/0200ce48_SetCartOwnerArm9.h"

void SetCartOwnerArm9(void)

{
  *puRam0200ce5c = *puRam0200ce5c & 0xff7f;
  return;
}

