/* Decompiled C draft; module arm9; ROM address 020482f0. No matching claim. */
#include "types.h"
#include "deps/020482f0_FormatSceneArchiveWithRaceMode_from_thumb.h"

void FormatSceneArchiveWithRaceMode_from_thumb(undefined4 param_1,char *param_2,int param_3)

{
  if (*param_2 != '\0') {
    Util_SNPrintF(param_1,0x80,uRam02048320,param_2,*(undefined4 *)(iRam02048318 + param_3 * 4),
                  uRam0204831c);
  }
  return;
}

