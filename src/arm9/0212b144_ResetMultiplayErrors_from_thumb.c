/* Decompiled C draft; module arm9; ROM address 0212b144. No matching claim. */
#include "types.h"
#include "deps/0212b144_ResetMultiplayErrors_from_thumb.h"

void ResetMultiplayErrors_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam0212b154;
  *(undefined4 *)(*piRam0212b154 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0xffffffff;
  return;
}

