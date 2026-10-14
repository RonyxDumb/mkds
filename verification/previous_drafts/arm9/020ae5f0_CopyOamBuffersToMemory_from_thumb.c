/* Decompiled C draft; module arm9; ROM address 020ae5f0. No matching claim. */
#include "types.h"
#include "deps/020ae5f0_CopyOamBuffersToMemory_from_thumb.h"

void CopyOamBuffersToMemory_from_thumb(int param_1,int param_2)

{
  if (param_1 != 0) {
    Arm_FlushRange(param_1,uRam020ae62c);
    CopyToOamA(param_1,0,uRam020ae62c);
  }
  if (param_2 != 0) {
    Arm_FlushRange(param_2,uRam020ae62c);
    CopyToOamB(param_2,0,uRam020ae62c);
  }
  return;
}

