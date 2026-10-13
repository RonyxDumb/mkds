/* Decompiled C draft; module arm7; ROM address 03805d44. No matching claim. */
#include "types.h"
#include "deps/03805d44_FUN_03805d44.h"

bool FUN_03805d44(undefined4 param_1)

{
  bool bVar1;
  ushort local_10 [4];
  
  FUN_03805b34((undefined4)(uintptr_t)(local_10));
  bVar1 = (local_10[0] & 0xb) == 1;
  if (bVar1) {
    FUN_038057b4(0x86,0x10,param_1,1);
  }
  return bVar1;
}

