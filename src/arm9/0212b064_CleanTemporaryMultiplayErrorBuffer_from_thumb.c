/* Decompiled C draft; module arm9; ROM address 0212b064. No matching claim. */
#include "types.h"
#include "deps/0212b064_CleanTemporaryMultiplayErrorBuffer_from_thumb.h"

void CleanTemporaryMultiplayErrorBuffer_from_thumb(void)

{
  Mem_CpuFill16(0,*piRam0212b084 + iRam0212b088,uRam0212b08c);
  return;
}

