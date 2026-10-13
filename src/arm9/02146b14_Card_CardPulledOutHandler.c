/* Decompiled C draft; module arm9; ROM address 02146b14. No matching claim. */
#include "types.h"
#include "deps/02146b14_Card_CardPulledOutHandler.h"

void Card_CardPulledOutHandler(undefined4 param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  
  if ((param_2 & 0x3f) != 0x11) {
    Os_Terminate();
    return;
  }
  pcVar2 = (code *)(*(uint *)(uRam02146b78 & 0xfffffffc) >> (uRam02146b78 & 3) * 8 |
                   *(uint *)(uRam02146b78 & 0xfffffffc) << (uRam02146b78 & 3) * -8 + 0x20);
  iVar1 = 1;
  *puRam02146b7c = 1;
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)();
  }
  if (iVar1 != 0) {
    Card_TerminateForPulledOut();
    return;
  }
  return;
}

