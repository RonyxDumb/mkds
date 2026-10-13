/* Decompiled C draft; module arm9; ROM address 020b3260. No matching claim. */
#include "types.h"
#include "deps/020b3260_ComputeSomeMESize_from_thumb.h"

int ComputeSomeMESize_from_thumb(int param_1)

{
  if (param_1 < 0) {
    return 0;
  }
  if (param_1 < 2) {
    return iRam020b3274;
  }
  return param_1 << 0xb;
}

