/* Decompiled C draft; module arm9; ROM address 02048284. No matching claim. */
#include "types.h"
#include "deps/02048284_FormatArchiveWithLanguage_from_thumb.h"

void FormatArchiveWithLanguage_from_thumb(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = GetLanguageIdentifierString_from_thumb();
  Util_SNPrintF(param_2,0x80,uRam020482a8,param_1,uVar1);
  return;
}

