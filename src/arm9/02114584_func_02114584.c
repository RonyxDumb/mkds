/* Decompiled C draft; module arm9; ROM address 02114584. No matching claim. */
#include "types.h"
#include "deps/02114584_func_02114584.h"

uint func_02114584(undefined1 param_1)

{
  byte local_8;
  byte local_7;
  byte local_6;
  
  func_021142d4(param_1,&local_8);
  return (uint)local_6 + iRam021145b0 * (uint)local_8 + (uint)local_7 * 0x20 & 0xffff;
}

