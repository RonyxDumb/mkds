/* Decompiled C draft; module arm9; ROM address 020b502c. No matching claim. */
#include "types.h"
#include "deps/020b502c_SomeFxProduct.h"

uint SomeFxProduct(int param_1,int param_2)

{
  return (uint)((longlong)param_1 * (longlong)param_2) >> 0xc |
         (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) << 0x14;
}

