/* Decompiled C draft; module arm9; ROM address 0207949c. No matching claim. */
#include "types.h"
#include "deps/0207949c_GetKartAPaletteData_from_thumb.h"

undefined4 GetKartAPaletteData_from_thumb(void)

{
  undefined4 uVar1;
  int local_8 [2];
  
  uVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam020794b8);
  Gfx_ReadPalette(local_8,uVar1);
  return *(undefined4 *)(local_8[0] + 0xc);
}

