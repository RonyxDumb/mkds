/* Decompiled C draft; module arm9; ROM address 02152988. No matching claim. */
#include "types.h"
#include "deps/02152988_VerifyChecksumGetProfileId_from_thumb.h"

ulonglong VerifyChecksumGetProfileId_from_thumb(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 auStack_108 [256];
  
  local_110 = param_1;
  local_10c = param_2;
  GenerateFriendCrcLookupTable(auStack_108,7);
  uVar1 = ComputeFriendCrc(auStack_108,&local_110,8);
  return CONCAT44(uVar1,param_1) & 0x7fffffffff;
}

