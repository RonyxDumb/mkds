/* Decompiled C draft; module arm9; ROM address 02079988. No matching claim. */
#include "types.h"
#include "deps/02079988_StructAD00Sub_SetKartIndex_from_thumb.h"

void StructAD00Sub_SetKartIndex_from_thumb(int param_1,undefined4 param_2)

{
  undefined2 extraout_r1;
  
  _s32_div_f(param_2,3);
  *(undefined2 *)(param_1 + 0x68) = extraout_r1;
  return;
}

