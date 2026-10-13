/* Decompiled C draft; module arm9; ROM address 0204e090. No matching claim. */
#include "types.h"
#include "deps/0204e090_StructZE_StateFn22_23_24_25_from_thumb.h"

void StructZE_StateFn22_23_24_25_from_thumb(void)

{
  int *piVar1;
  byte *pbVar2;
  
  piVar1 = piRam0204e0b0;
  *(undefined4 *)(*piRam0204e0b0 + 0xc) = 0x1b;
  *(undefined4 *)(*piVar1 + 0x10) = 1;
  pbVar2 = (byte *)(*piVar1 + iRam0204e0b4);
  *pbVar2 = *pbVar2 & 0xfd;
                    /* WARNING: Could not recover jumptable at 0x0204e0ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0204e0b8)();
  return;
}

