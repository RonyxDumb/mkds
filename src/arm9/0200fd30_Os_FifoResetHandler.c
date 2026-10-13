/* Decompiled C draft; module arm9; ROM address 0200fd30. No matching claim. */
#include "types.h"
#include "deps/0200fd30_Os_FifoResetHandler.h"

void Os_FifoResetHandler(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7f00) != 0x1000) {
    Os_Terminate();
    return;
  }
  *puRam0200fd70 = 1;
  return;
}

