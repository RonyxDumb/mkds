/* Decompiled C draft; module arm9; ROM address 0210bbec. No matching claim. */
#include "types.h"
#include "deps/0210bbec_SetSomeVAVO.h"

void SetSomeVAVO(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(iRam0210bbfc + param_1 * 0x20 + param_2 * 4) = param_3;
  return;
}

