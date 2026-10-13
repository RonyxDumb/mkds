/* Decompiled C draft; module arm9; ROM address 02077f7c. No matching claim. */
#include "types.h"
#include "deps/02077f7c_GetHeyhoColorPaletteDataForRacer_from_thumb.h"

int GetHeyhoColorPaletteDataForRacer_from_thumb(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *(int *)(*piRam02077f98 + 0x14);
  if (iVar1 != 0) {
    iVar2 = iVar1 + *(short *)(*piRam02077f98 + param_1 * 2 + 0x18) * 0x20;
  }
  return iVar2;
}

