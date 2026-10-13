/* Decompiled C draft; module arm9; ROM address 02060950. No matching claim. */
#include "types.h"
#include "deps/02060950_func_02060950.h"

undefined4 func_02060950(undefined4 param_1,byte *param_2)

{
  undefined1 auStack_30 [12];
  ushort uStack_24;
  byte local_e;
  
  GlobalZ_GetOI(param_1,auStack_30);
  if ((int)((uint)local_e << 0x1f) < 0) {
    *param_2 = (byte)(((uint)uStack_24 << 0x19) >> 0x19);
    param_2[1] = (byte)(((uint)uStack_24 << 0x15) >> 0x1c);
    param_2[2] = (byte)(uStack_24 >> 0xb);
    return 1;
  }
  return 0;
}

