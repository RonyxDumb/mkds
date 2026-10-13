/* Decompiled C draft; module arm9; ROM address 02048474. No matching claim. */
#include "types.h"
#include "deps/02048474_GetLanguageIdentifierString_from_thumb.h"

undefined4 GetLanguageIdentifierString_from_thumb(void)

{
  int iVar1;
  
  iVar1 = ((int *)*piRam02048490)[1];
  if ((*(int *)*piRam02048490 == 2) && (iVar1 == 1)) {
    iVar1 = 6;
  }
  return *(undefined4 *)(iRam02048494 + iVar1 * 4);
}

