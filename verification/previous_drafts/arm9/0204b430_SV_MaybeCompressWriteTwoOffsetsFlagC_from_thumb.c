/* Decompiled C draft; module arm9; ROM address 0204b430. No matching claim. */
#include "types.h"
#include "deps/0204b430_SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb.h"

void SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  *(undefined4 *)(*piRam0204b454 + 0x18) = param_2;
  SV_MaybeCompressWriteImpl_from_thumb(param_1,param_3,param_4,param_5,1,param_6);
  return;
}

