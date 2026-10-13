/* Decompiled C draft; module arm9; ROM address 0200cdc8. No matching claim. */
#include "types.h"
#include "deps/0200cdc8_SetCardOwnerArm7.h"

void SetCardOwnerArm7(void)

{
  *puRam0200cddc = *puRam0200cddc | 0x800;
  return;
}

