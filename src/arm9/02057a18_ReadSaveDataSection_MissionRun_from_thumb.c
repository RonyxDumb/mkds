/* Decompiled C draft; module arm9; ROM address 02057a18. No matching claim. */
#include "types.h"
#include "deps/02057a18_ReadSaveDataSection_MissionRun_from_thumb.h"

void ReadSaveDataSection_MissionRun_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam02057a48;
  if (*(int *)(*piRam02057a48 + 0xc) != 0) {
    *(undefined4 *)(*piRam02057a48 + 0x68) = param_1;
    ReadSaveChunkImpl_from_thumb
              (uRam02057a54,uRam02057a58,*(undefined4 *)(*piVar1 + 0x60),uRam02057a5c,uRam02057a4c,
               uRam02057a50,0);
  }
  return;
}

