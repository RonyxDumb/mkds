/* Decompiled C draft; module arm9; ROM address 02079a14. No matching claim. */
#include "types.h"
#include "deps/02079a14_StructAD00Sub_SomeFn_from_thumb.h"

void StructAD00Sub_SomeFn_from_thumb(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = Animation_GetCurrentLength(*piRam02079a34 + iRam02079a38);
  Animation_InitializeImpl(param_1 + 0x98,uVar1);
  return;
}

