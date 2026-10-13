/* Decompiled C draft; module arm9; ROM address 02146ab4. No matching claim. */
#include "types.h"
#include "deps/02146ab4_Card_TerminateForPulledOut.h"

void Card_TerminateForPulledOut(void)

{
  if ((int)(*puRam02146af0 & 0x8000) >> 0xf != 0) {
    func_0214fb54();
  }
  Card_SendToFifo(1,1);
  Os_Terminate();
  return;
}

