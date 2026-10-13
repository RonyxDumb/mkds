/* Decompiled C draft; module arm9; ROM address 020562b4. No matching claim. */
#include "types.h"
#include "deps/020562b4_CleanSaveDataHolderFlagBytes_from_thumb.h"

void CleanSaveDataHolderFlagBytes_from_thumb(void)

{
  int *piVar1;
  uint uVar2;
  
  piVar1 = piRam020562e4;
  uVar2 = 0;
  do {
    *(undefined1 *)(*piVar1 + uVar2 + 0x30) = 0;
    *(undefined1 *)(*piVar1 + uVar2 + 0x34) = 0;
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  *(undefined1 *)(*piVar1 + 0x38) = 0;
  *(undefined1 *)(*piVar1 + 0x39) = 0;
  return;
}

