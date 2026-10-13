/* Decompiled C draft; module arm9; ROM address 02146a50. No matching claim. */
#include "types.h"
#include "deps/02146a50_Card_SendToFifo.h"

void Card_SendToFifo(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Fifo_SendWord(0xe,param_1,0);
  if (iVar1 == 0) {
    return;
  }
  do {
    WaitByLoop(param_2);
    iVar1 = Fifo_SendWord(0xe,param_1,0);
  } while (iVar1 != 0);
  return;
}

