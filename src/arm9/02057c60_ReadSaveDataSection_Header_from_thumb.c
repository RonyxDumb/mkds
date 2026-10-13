/* Decompiled C draft; module arm9; ROM address 02057c60. No matching claim. */
#include "types.h"
#include "deps/02057c60_ReadSaveDataSection_Header_from_thumb.h"

void ReadSaveDataSection_Header_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam02057c90;
  if (*(int *)(*piRam02057c90 + 0xc) != 0) {
    *(undefined4 *)(*piRam02057c90 + 0x68) = param_1;
    ReadSaveChunkImpl_from_thumb
              (0,uRam02057c9c,*(undefined4 *)(*piVar1 + 0x60),uRam02057ca0,uRam02057c94,uRam02057c98
               ,1);
  }
  return;
}

