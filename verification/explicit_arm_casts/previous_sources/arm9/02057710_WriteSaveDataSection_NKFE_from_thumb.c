/* Decompiled C draft; module arm9; ROM address 02057710. No matching claim. */
#include "types.h"
#include "deps/02057710_WriteSaveDataSection_NKFE_from_thumb.h"

void WriteSaveDataSection_NKFE_from_thumb(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  param_2 = iRam02057750 * param_2;
  puVar1 = *(undefined4 **)(*piRam02057754 + 0x60);
  if (*(int *)(*piRam02057754 + 0xc) != 0) {
    Mem_CpuCopy8(param_1,puVar1);
    *puVar1 = uRam02057758;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
              (param_2 + iRam0205775c,param_2 + iRam02057760,puVar1,iRam02057750,0,0);
  }
  return;
}

