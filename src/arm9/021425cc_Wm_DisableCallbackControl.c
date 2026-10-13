/* Decompiled C draft; module arm9; ROM address 021425cc. No matching claim. */
#include "types.h"
#include "deps/021425cc_Wm_DisableCallbackControl.h"

void Wm_DisableCallbackControl(void)

{
  if ((*puRam021425e4 & 1) != 0) {
    *puRam021425e4 = *puRam021425e4 & 0xfffe;
  }
  return;
}

