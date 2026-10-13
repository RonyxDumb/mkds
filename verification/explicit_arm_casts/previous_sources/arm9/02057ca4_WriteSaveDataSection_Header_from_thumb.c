/* Decompiled C draft; module arm9; ROM address 02057ca4. No matching claim. */
#include "types.h"
#include "deps/02057ca4_WriteSaveDataSection_Header_from_thumb.h"

void WriteSaveDataSection_Header_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(*piRam02057ce4 + 0x60);
  if (*(int *)(*piRam02057ce4 + 0xc) != 0) {
    Mem_CpuCopy8(param_1,puVar2,uRam02057ce8);
    uVar1 = uRam02057cf0;
    *puVar2 = uRam02057cec;
    puVar2[1] = uVar1;
    puVar2[2] = uRam02057cf4;
    SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0,uRam02057cf8,puVar2,uRam02057ce8,0,1);
  }
  return;
}

