/* Decompiled C draft; module arm9; ROM address 0204840c. No matching claim. */
#include "types.h"
#include "deps/0204840c_FormatCarcWithLanguage2_from_thumb.h"

void FormatCarcWithLanguage2_from_thumb(undefined4 param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 != '\0') {
    uVar1 = GetLanguageIdentifierString_from_thumb();
    Util_SNPrintF(param_1,0x80,uRam0204843c,param_2,uVar1,uRam02048438);
  }
  return;
}

