/* Decompiled C draft; module arm9; ROM address 02020f50. No matching claim. */
#include "types.h"
#include "deps/02020f50_SoundInternal_RequestCommandProc.h"

void SoundInternal_RequestCommandProc(void)

{
  int iVar1;
  
  do {
    iVar1 = Fifo_SendWord(7,0,0);
  } while (iVar1 < 0);
  return;
}

