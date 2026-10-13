/* Decompiled C draft; module arm9; ROM address 021457ac. No matching claim. */
#include "types.h"
#include "deps/021457ac_Card_UnlockRomResource.h"

void Card_UnlockRomResource(undefined4 param_1)

{
  Os_UnlockCard();
  Card_UnlockResource(param_1,1);
  return;
}

