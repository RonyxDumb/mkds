/* Decompiled C draft; module arm9; ROM address 02125f88. No matching claim. */
#include "types.h"
#include "deps/02125f88_TextSystem_IsDialogFinished_from_thumb.h"

undefined4 TextSystem_IsDialogFinished_from_thumb(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)*puRam02125fa0 == 0) && (((int *)*puRam02125fa0)[0xd] == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

