/* Decompiled C draft; module arm9; ROM address 02125f6c. No matching claim. */
#include "types.h"
#include "deps/02125f6c_TextSystem_JustFadedIn_from_thumb.h"

undefined4 TextSystem_JustFadedIn_from_thumb(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((int *)*puRam02125f84)[2] == 1) && (*(int *)*puRam02125f84 == 2)) {
    uVar1 = 1;
  }
  return uVar1;
}

