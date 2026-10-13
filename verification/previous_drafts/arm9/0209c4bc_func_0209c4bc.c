/* Decompiled C draft; module arm9; ROM address 0209c4bc. No matching claim. */
#include "types.h"
#include "deps/0209c4bc_func_0209c4bc.h"

uint func_0209c4bc(int param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_1 * (longlong)param_2 + 0x800;
  return (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
}

