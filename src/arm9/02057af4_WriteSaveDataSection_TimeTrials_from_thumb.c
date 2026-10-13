/* Decompiled C draft; module arm9; ROM address 02057af4. No matching claim. */
#include "types.h"
#include "deps/02057af4_WriteSaveDataSection_TimeTrials_from_thumb.h"

void WriteSaveDataSection_TimeTrials_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam02057b2c + 0x60);
  if (*(int *)(*piRam02057b2c + 0xc) != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),puVar1,uRam02057b30);
    *puVar1 = uRam02057b34;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (uRam02057b38,uRam02057b3c,(undefined4)(uintptr_t)(puVar1),uRam02057b30,0,0);
  }
  return;
}

