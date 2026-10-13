/* Decompiled C draft; module arm9; ROM address 02057b84. No matching claim. */
#include "types.h"
#include "deps/02057b84_WriteSaveDataSection_GrandPrix_from_thumb.h"

void WriteSaveDataSection_GrandPrix_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam02057bbc + 0x60);
  if (*(int *)(*piRam02057bbc + 0xc) != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),puVar1,uRam02057bc0);
    *puVar1 = uRam02057bc4;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (uRam02057bc0,uRam02057bc8,(undefined4)(uintptr_t)(puVar1),uRam02057bc0,0,0);
  }
  return;
}

