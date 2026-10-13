/* Decompiled C draft; module arm9; ROM address 020ae6d4. No matching claim. */
#include "types.h"
#include "deps/020ae6d4_OamBuffer_SomeFn_from_thumb.h"

void OamBuffer_SomeFn_from_thumb(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined2 *)(param_1 + iRam020ae710) = 0;
    *(undefined2 *)(param_1 + iRam020ae714) = 0;
    Mem_DmaFill32(3,param_1,0xc0);
  }
  if (param_2 != 0) {
    *(undefined2 *)(param_2 + iRam020ae710) = 0;
    *(undefined2 *)(param_2 + iRam020ae714) = 0;
    Mem_DmaFill32(3,param_2,0xc0);
  }
  return;
}

