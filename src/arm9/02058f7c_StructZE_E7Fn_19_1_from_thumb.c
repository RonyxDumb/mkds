/* Decompiled C draft; module arm9; ROM address 02058f7c. No matching claim. */
#include "types.h"
#include "deps/02058f7c_StructZE_E7Fn_19_1_from_thumb.h"

void StructZE_E7Fn_19_1_from_thumb(void)

{
  int *piVar1;
  byte *pbVar2;
  
  piVar1 = piRam02058fa4;
  *(undefined4 *)(*piRam02058fa4 + iRam02058fa8) = 0;
  pbVar2 = (byte *)(*piVar1 + iRam02058fac);
  *pbVar2 = *pbVar2 & 0xfd;
  *(undefined1 *)(*piVar1 + iRam02058fb0) = 0;
  return;
}

