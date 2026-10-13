/* Decompiled C draft; module arm7; ROM address 03805f74. No matching claim. */
#include "types.h"
#include "deps/03805f74_FUN_03805f74.h"

void FUN_03805f74(void)

{
  ushort local_8 [4];
  
  FUN_037fb808(0x8000);
  local_8[0] = local_8[0] & 0xfffe | 1;
  FUN_038057b4(6,0,local_8,1);
  return;
}

