/* Decompiled C draft; module arm9; ROM address 02057bcc. No matching claim. */
#include "types.h"
#include "deps/02057bcc_ReadSaveDataSection_Emblem_from_thumb.h"

void ReadSaveDataSection_Emblem_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam02057bfc;
  if (*(int *)(*piRam02057bfc + 0xc) != 0) {
    *(undefined4 *)(*piRam02057bfc + 0x68) = param_1;
    ReadSaveChunkImpl_from_thumb
              (uRam02057c08,uRam02057c0c,*(undefined4 *)(*piVar1 + 0x60),uRam02057c10,uRam02057c00,
               uRam02057c04,0);
  }
  return;
}

