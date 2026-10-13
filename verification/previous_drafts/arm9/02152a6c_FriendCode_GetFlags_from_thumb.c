/* Decompiled C draft; module arm9; ROM address 02152a6c. No matching claim. */
#include "types.h"
#include "deps/02152a6c_FriendCode_GetFlags_from_thumb.h"

uint FriendCode_GetFlags_from_thumb(uint *param_1)

{
  return *param_1 >> 0xb & uRam02152a78;
}

