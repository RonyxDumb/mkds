/* Decompiled C draft; module arm9; ROM address 02057a60. No matching claim. */
#include "types.h"
#include "deps/02057a60_WriteSaveDataSection_MissionRun_from_thumb.h"

void WriteSaveDataSection_MissionRun_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam02057a98 + 0x60);
  if (*(int *)(*piRam02057a98 + 0xc) != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),puVar1,uRam02057a9c);
    *puVar1 = uRam02057aa0;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (uRam02057aa4,uRam02057aa8,(undefined4)(uintptr_t)(puVar1),uRam02057a9c,0,0);
  }
  return;
}

