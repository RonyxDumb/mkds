/* Decompiled C draft; module arm9; ROM address 020ae6ac. No matching claim. */
#include "types.h"
#include "deps/020ae6ac_OamBuffer_ResetValues16_from_thumb.h"

void OamBuffer_ResetValues16_from_thumb(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined2 *)(param_1 + iRam020ae6cc) = 0;
    *(undefined2 *)(param_1 + iRam020ae6d0) = 0;
  }
  if (param_2 != 0) {
    *(undefined2 *)(param_2 + iRam020ae6cc) = 0;
    *(undefined2 *)(param_2 + iRam020ae6d0) = 0;
  }
  return;
}

