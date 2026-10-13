/* Decompiled C draft; module arm9; ROM address 02125ee8. No matching claim. */
#include "types.h"
#include "deps/02125ee8_TextSystem_SetSomeValues_from_thumb.h"

void TextSystem_SetSomeValues_from_thumb(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = piRam02125f20;
  if (param_1 < -0x96) {
    param_1 = -0x96;
  }
  if (0x96 < param_1) {
    param_1 = 0x96;
  }
  if (param_2 < -0x96) {
    param_2 = -0x96;
  }
  if (0x96 < param_2) {
    param_2 = 0x96;
  }
  *(int *)(*piRam02125f20 + iRam02125f24) = param_1;
  *(int *)(*piVar1 + iRam02125f28) = param_2;
  return;
}

