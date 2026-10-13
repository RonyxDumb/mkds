/* Decompiled C draft; module arm7; ROM address 03805ca0. No matching claim. */
#include "types.h"
#include "deps/03805ca0_FUN_03805ca0.h"

bool FUN_03805ca0(undefined4 param_1)

{
  bool bVar1;
  ushort local_10 [4];
  
  FUN_03805b34(local_10);
  bVar1 = (local_10[0] & 0xf) == 4;
  if (bVar1) {
    FUN_038057b4(0x86,0x10,param_1,3);
  }
  return bVar1;
}

