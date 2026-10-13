/* Decompiled C draft; module arm9; ROM address 020579d0. No matching claim. */
#include "types.h"
#include "deps/020579d0_WriteSaveDataSection_PersonalGhost_from_thumb.h"

void WriteSaveDataSection_PersonalGhost_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  param_1 = iRam02057a08 * param_1;
  puVar1 = *(undefined4 **)(*piRam02057a0c + 0x60);
  if (*(int *)(*piRam02057a0c + 0xc) != 0) {
    Mem_CpuCopy8(param_2,puVar1);
    *puVar1 = uRam02057a10;
    SV_MaybeCompressWriteNoFlagsBC_from_thumb(param_1 + iRam02057a14,puVar1,iRam02057a08,0);
  }
  return;
}

