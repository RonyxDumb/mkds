/* Decompiled C draft; module arm9; ROM address 02152314. No matching claim. */
#include "types.h"
#include "deps/02152314_IsLeapYear_from_thumb.h"

undefined4 IsLeapYear_from_thumb(uint param_1)

{
  if ((param_1 & 3) == 0) {
    return 1;
  }
  return 0;
}

