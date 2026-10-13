/* Decompiled C draft; module arm9; ROM address 02048440. No matching claim. */
#include "types.h"
#include "deps/02048440_GetSomeLanguage_from_thumb.h"

undefined4 GetSomeLanguage_from_thumb(void)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(*piRam02048464 + iRam02048468);
  if ((*(int *)*puRam0204846c == 2) && (((int *)*puRam0204846c)[1] == 1)) {
    uVar1 = uVar1 + 5;
  }
  return *(undefined4 *)(iRam02048470 + uVar1 * 4);
}

