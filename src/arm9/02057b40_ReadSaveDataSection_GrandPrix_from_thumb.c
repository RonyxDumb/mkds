/* Decompiled C draft; module arm9; ROM address 02057b40. No matching claim. */
#include "types.h"
#include "deps/02057b40_ReadSaveDataSection_GrandPrix_from_thumb.h"

void ReadSaveDataSection_GrandPrix_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam02057b70;
  if (*(int *)(*piRam02057b70 + 0xc) != 0) {
    *(undefined4 *)(*piRam02057b70 + 0x68) = param_1;
    ReadSaveChunkImpl_from_thumb
              (uRam02057b7c,uRam02057b80,*(undefined4 *)(*piVar1 + 0x60),uRam02057b7c,uRam02057b74,
               uRam02057b78,0);
  }
  return;
}

