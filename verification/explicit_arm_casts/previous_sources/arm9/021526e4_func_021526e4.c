/* Decompiled C draft; module arm9; ROM address 021526e4. No matching claim. */
#include "types.h"
#include "deps/021526e4_func_021526e4.h"

undefined4 func_021526e4(undefined4 param_1)

{
  longlong lVar1;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  StructDW_SomeFn_GetSomething_from_thumb(&local_20);
  if (local_10 == 0) {
    lVar1 = FriendCode_GetSomePackedValue_from_thumb(param_1);
    if (lVar1 == CONCAT44(local_14,local_18)) {
      return 1;
    }
    return 0;
  }
  lVar1 = FriendCode_GetSomePackedValue_from_thumb(param_1);
  if (lVar1 == CONCAT44(local_1c,local_20)) {
    return 1;
  }
  return 0;
}

