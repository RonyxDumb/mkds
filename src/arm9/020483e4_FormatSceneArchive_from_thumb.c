/* Decompiled C draft; module arm9; ROM address 020483e4. No matching claim. */
#include "types.h"
#include "deps/020483e4_FormatSceneArchive_from_thumb.h"

void FormatSceneArchive_from_thumb(undefined4 param_1,char *param_2)

{
  if (*param_2 != '\0') {
    Util_SNPrintF(param_1,0x80,uRam02048408,param_2,uRam02048404);
  }
  return;
}

