/* Decompiled C draft; module arm9; ROM address 02047950. No matching claim. */
#include "types.h"
#include "deps/02047950_FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb.h"

void FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = GetCurrentSceneId();
  if (iVar1 == 3) {
    FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(param_1);
    return;
  }
  AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb(param_1);
  return;
}

