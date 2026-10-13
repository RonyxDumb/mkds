/* Decompiled C draft; module arm9; ROM address 020a2668. No matching claim. */
#include "types.h"
#include "deps/020a2668_func_020a2668.h"

uint func_020a2668(int param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_1 * (longlong)param_2 + 0x800;
  return (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
}

