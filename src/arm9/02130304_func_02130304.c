/* Decompiled C draft; module arm9; ROM address 02130304. No matching claim. */
#include "types.h"
#include "deps/02130304_func_02130304.h"

undefined8 func_02130304(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = 0x41e;
  if (-1 < param_1) {
    iVar1 = LZCOUNT(param_1);
    param_1 = param_1 << iVar1;
    iVar1 = 0x41e - iVar1;
  }
  return CONCAT44((uint)(param_1 * 2) >> 0xc | iVar1 << 0x14,param_1 << 0x15);
}

