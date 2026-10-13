/* Decompiled C draft; module arm9; ROM address 020adc24. No matching claim. */
#include "types.h"
#include "deps/020adc24_StructRCTime_SmallerThan_from_thumb.h"

bool StructRCTime_SmallerThan_from_thumb(ushort *param_1,ushort *param_2)

{
  return (int)((uint)*param_1 +
              iRam020adc5c * (uint)*(byte *)((int)param_1 + 3) +
              iRam020adc60 * (uint)(byte)param_1[1]) <
         (int)((uint)*param_2 +
              iRam020adc5c * (uint)*(byte *)((int)param_2 + 3) +
              iRam020adc60 * (uint)(byte)param_2[1]);
}

