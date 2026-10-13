/* Decompiled C draft; module arm9; ROM address 02059304. No matching claim. */
#include "types.h"
#include "deps/02059304_StructZE_E7Fn_17_1_from_thumb.h"

void StructZE_E7Fn_17_1_from_thumb(void)

{
  int *piVar1;
  byte *pbVar2;
  
  piVar1 = piRam0205932c;
  *(undefined4 *)(*piRam0205932c + iRam02059330) = 0;
  pbVar2 = (byte *)(*piVar1 + iRam02059334);
  *pbVar2 = *pbVar2 & 0xfd;
  *(undefined1 *)(*piVar1 + iRam02059338) = 0;
  return;
}

