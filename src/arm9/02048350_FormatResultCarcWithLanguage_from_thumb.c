/* Decompiled C draft; module arm9; ROM address 02048350. No matching claim. */
#include "types.h"
#include "deps/02048350_FormatResultCarcWithLanguage_from_thumb.h"

void FormatResultCarcWithLanguage_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = uRam02048390;
  if (*(int *)(*piRam02048388 + 0x78) == 1) {
    uVar2 = uRam0204838c;
  }
  uVar1 = GetLanguageIdentifierString_from_thumb();
  Util_SNPrintF(param_1,0x80,uRam02048398,*(undefined4 *)(iRam0204839c + 0x50),uVar2,uVar1,
                uRam02048394);
  return;
}

