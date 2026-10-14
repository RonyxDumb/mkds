/* Decompiled C draft; module arm7; ROM address 03805c50. No matching claim. */
#include "types.h"
#include "deps/03805c50_FUN_03805c50.h"

bool FUN_03805c50(undefined4 param_1)

{
  bool bVar1;
  ushort local_10 [4];
  
  FUN_03805b34((undefined4)(uintptr_t)(local_10));
  bVar1 = (local_10[0] & 0xf) == 4;
  if (bVar1) {
    FUN_038057b4(6,0x10,param_1,3);
  }
  return bVar1;
}

