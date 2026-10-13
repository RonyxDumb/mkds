/* Decompiled C draft; module arm9; ROM address 02079478. No matching claim. */
#include "types.h"
#include "deps/02079478_GetKartModelMenuKartAPalette_from_thumb.h"

undefined4 GetKartModelMenuKartAPalette_from_thumb(undefined4 param_1)

{
  undefined4 local_10;
  int local_c [3];
  
  ReadKartModelMenuFile_from_thumb(param_1,uRam02079498,&local_10);
  Gfx_ReadPalette(local_c,local_10);
  return *(undefined4 *)(local_c[0] + 0xc);
}

