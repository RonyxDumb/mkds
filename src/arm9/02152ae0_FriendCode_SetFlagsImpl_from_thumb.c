/* Decompiled C draft; module arm9; ROM address 02152ae0. No matching claim. */
#include "types.h"
#include "deps/02152ae0_FriendCode_SetFlagsImpl_from_thumb.h"

undefined4 FriendCode_SetFlagsImpl_from_thumb(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if ((param_2 & ~param_4) != 0) {
    return 0;
  }
  *param_1 = *param_1 & ~(param_4 << (param_3 & 0xff)) | param_2 << (param_3 & 0xff);
  return 1;
}

