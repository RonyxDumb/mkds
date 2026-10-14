/* Decompiled C draft; module arm7; ROM address 03805c04. No matching claim. */
#include "types.h"
#include "deps/03805c04_FUN_03805c04.h"

bool FUN_03805c04(undefined4 param_1)

{
  bool bVar1;
  ushort local_10 [4];
  
  FUN_03805b34((undefined4)(uintptr_t)(local_10));
  bVar1 = (int)((uint)local_10[0] << 0x19) < 0;
  if (bVar1) {
    FUN_038057b4(0x86,0x50,param_1,3);
  }
  return bVar1;
}

