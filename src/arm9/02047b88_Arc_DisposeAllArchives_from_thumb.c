/* Decompiled C draft; module arm9; ROM address 02047b88. No matching claim. */
#include "types.h"
#include "deps/02047b88_Arc_DisposeAllArchives_from_thumb.h"

void Arc_DisposeAllArchives_from_thumb(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    Arc_DisposeArchive_from_thumb(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x14);
  return;
}

