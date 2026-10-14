/* Decompiled C draft; module arm9; ROM address 02057c14. No matching claim. */
#include "types.h"
#include "deps/02057c14_WriteSaveDataSection_Emblem_from_thumb.h"

void WriteSaveDataSection_Emblem_from_thumb(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*piRam02057c4c + 0x60);
  if (*(int *)(*piRam02057c4c + 0xc) != 0) {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),puVar1,uRam02057c50);
    *puVar1 = uRam02057c54;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (uRam02057c58,uRam02057c5c,(undefined4)(uintptr_t)(puVar1),uRam02057c50,0,0);
  }
  return;
}

