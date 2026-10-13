/* Decompiled C draft; module arm9; ROM address 020b31e4. No matching claim. */
#include "types.h"
#include "deps/020b31e4_ClearRaceOptionMenuEntries_from_thumb.h"

void ClearRaceOptionMenuEntries_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam020b3208;
  iVar2 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar2 * 0x1c + 0x50) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}

