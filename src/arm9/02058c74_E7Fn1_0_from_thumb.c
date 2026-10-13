/* Decompiled C draft; module arm9; ROM address 02058c74. No matching claim. */
#include "types.h"
#include "deps/02058c74_E7Fn1_0_from_thumb.h"

void E7Fn1_0_from_thumb(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)*puRam02058c98;
  if (*piVar1 == 2) {
    uVar2 = (uint)*(ushort *)((int)piVar1 + iRam02058c9c);
  }
  else {
    uVar2 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x02058c96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02058ca8)((int)piVar1 + iRam02058ca4 * uVar2 + iRam02058ca0);
  return;
}

