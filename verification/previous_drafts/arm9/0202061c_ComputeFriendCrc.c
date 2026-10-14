/* Decompiled C draft; module arm9; ROM address 0202061c. No matching claim. */
#include "types.h"
#include "deps/0202061c_ComputeFriendCrc.h"

undefined1 ComputeFriendCrc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_8 [8];
  
  local_8[0] = 0;
  Friend_ComputeCrcImpl(param_1,local_8,(byte *)(uintptr_t)(param_2),param_3);
  return local_8[0];
}

