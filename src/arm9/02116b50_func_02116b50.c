/* Decompiled C draft; module arm9; ROM address 02116b50. No matching claim. */
#include "types.h"
#include "deps/02116b50_func_02116b50.h"

void func_02116b50(uint param_1,int param_2)

{
  if (9 < param_1) {
    FormatIntegerInString16_from_thumb();
    return;
  }
  FormatIntegerInString16_from_thumb(0);
  FormatIntegerInString16_from_thumb(param_1,param_2 + 2);
  return;
}

