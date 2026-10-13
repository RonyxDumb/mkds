/* Decompiled C draft; module arm9; ROM address 0207913c. No matching claim. */
#include "types.h"
#include "deps/0207913c_ReadKartModelMenuFile_from_thumb.h"

void ReadKartModelMenuFile_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char acStack_110 [260];
  
  _snprintf(acStack_110,sRam02079164,pcRam02079168,param_2);
  ReadFileFromMountManagerHandle_from_thumb((undefined4)(uintptr_t)(acStack_110),param_1,(int *)(uintptr_t)(param_3));
  return;
}

