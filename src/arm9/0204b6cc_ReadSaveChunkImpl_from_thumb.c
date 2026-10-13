/* Decompiled C draft; module arm9; ROM address 0204b6cc. No matching claim. */
#include "types.h"
#include "deps/0204b6cc_ReadSaveChunkImpl_from_thumb.h"

void ReadSaveChunkImpl_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(*piRam0204b6f4 + 0x18) = param_2;
  func_0204b714(param_1,param_3,param_4,param_5,1,param_6,param_7);
  return;
}

