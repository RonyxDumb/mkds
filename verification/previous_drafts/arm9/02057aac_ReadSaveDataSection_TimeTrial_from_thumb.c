/* Decompiled C draft; module arm9; ROM address 02057aac. No matching claim. */
#include "types.h"
#include "deps/02057aac_ReadSaveDataSection_TimeTrial_from_thumb.h"

void ReadSaveDataSection_TimeTrial_from_thumb(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = piRam02057adc;
  if (*(int *)(*piRam02057adc + 0xc) != 0) {
    *(undefined4 *)(*piRam02057adc + 0x68) = param_1;
    ReadSaveChunkImpl_from_thumb
              (uRam02057ae8,uRam02057aec,*(undefined4 *)(*piVar1 + 0x60),uRam02057af0,uRam02057ae0,
               uRam02057ae4,0);
  }
  return;
}

