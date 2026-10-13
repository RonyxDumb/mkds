/* Decompiled C draft; module arm9; ROM address 020482ac. No matching claim. */
#include "types.h"
#include "deps/020482ac_FormatRaceCarcWithLanguage_from_thumb.h"

void FormatRaceCarcWithLanguage_from_thumb(undefined4 param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*param_2 != '\0') {
    uVar1 = GetLanguageIdentifierString_from_thumb();
    Util_SNPrintF(param_1,0x80,uRam020482ec,param_2,*(undefined4 *)(iRam020482e4 + param_3 * 4),
                  uVar1,uRam020482e8);
  }
  return;
}

