/* Decompiled C draft; module arm9; ROM address 02091f24. No matching claim. */
#include "types.h"
#include "deps/02091f24_Maybe_helper_091f24.h"

int Maybe_helper_091f24(int param_1)

{
  return (int)*(short *)(iRam02091f40 + ((param_1 >> 4) * 2 + 1) * 2);
}

