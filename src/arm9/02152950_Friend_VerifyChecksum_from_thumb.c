/* Decompiled C draft; module arm9; ROM address 02152950. No matching claim. */
#include "types.h"
#include "deps/02152950_Friend_VerifyChecksum_from_thumb.h"

bool Friend_VerifyChecksum_from_thumb(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 auStack_108 [256];
  
  local_110 = param_1;
  local_10c = param_3;
  GenerateFriendCrcLookupTable((int)(uintptr_t)(auStack_108),7);
  uVar1 = ComputeFriendCrc((undefined4)(uintptr_t)(auStack_108),(undefined4)(uintptr_t)(&local_110),8);
  return (uVar1 & 0x7f) == param_2;
}

