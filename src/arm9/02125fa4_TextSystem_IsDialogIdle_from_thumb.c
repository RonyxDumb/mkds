/* Decompiled C draft; module arm9; ROM address 02125fa4. No matching claim. */
#include "types.h"
#include "deps/02125fa4_TextSystem_IsDialogIdle_from_thumb.h"

undefined4 TextSystem_IsDialogIdle_from_thumb(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)*puRam02125fbc == 2) && (((int *)*puRam02125fbc)[0xe] == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}

