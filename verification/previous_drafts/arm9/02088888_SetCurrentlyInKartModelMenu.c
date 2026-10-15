/* Decompiled C draft; module arm9; ROM address 02088888. No matching claim. */
#include "types.h"
#include "deps/02088888_SetCurrentlyInKartModelMenu.h"

void SetCurrentlyInKartModelMenu(int param_1)

{
  if (param_1 == 0) {
    *puRam020888ac = uRam020888b0;
  }
  else {
    *puRam020888ac = uRam020888a8;
  }
  return;
}

