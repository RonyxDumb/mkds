/* Decompiled C draft; module arm9; ROM address 02048324. No matching claim. */
#include "types.h"
#include "deps/02048324_FormatStaffRollCarcWithLanguage_from_thumb.h"

void FormatStaffRollCarcWithLanguage_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetLanguageIdentifierString_from_thumb();
  Util_SNPrintF(param_1,0x80,uRam0204834c,uVar1,uRam02048348);
  return;
}

