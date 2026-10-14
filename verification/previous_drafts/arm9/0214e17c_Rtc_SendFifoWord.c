/* Decompiled C draft; module arm9; ROM address 0214e17c. No matching claim. */
#include "types.h"
#include "deps/0214e17c_Rtc_SendFifoWord.h"

bool Rtc_SendFifoWord(uint param_1)

{
  int iVar1;
  
  iVar1 = Fifo_SendWord(5,(param_1 & 0x7f) << 8,0);
  return -1 < iVar1;
}

