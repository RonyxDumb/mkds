/* Decompiled C draft; module arm9; ROM address 02152ac8. No matching claim. */
#include "types.h"
#include "deps/02152ac8_FriendCode_GetSomePackedValue_from_thumb.h"

undefined8 FriendCode_GetSomePackedValue_from_thumb(uint *param_1)

{
  return CONCAT44(*param_1 & uRam02152adc,param_1[1]);
}

