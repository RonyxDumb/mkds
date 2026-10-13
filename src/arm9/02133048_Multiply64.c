/* Decompiled C draft; module arm9; ROM address 02133048. No matching claim. */
#include "types.h"
#include "deps/02133048_Multiply64.h"

undefined8 Multiply64(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44(param_3 * param_2 +
                  param_1 * param_4 + (int)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20),
                  (int)((ulonglong)param_3 * (ulonglong)param_1));
}

