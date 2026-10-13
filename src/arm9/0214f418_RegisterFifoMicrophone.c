/* Decompiled C draft; module arm9; ROM address 0214f418. No matching claim. */
#include "types.h"
#include "deps/0214f418_RegisterFifoMicrophone.h"

void RegisterFifoMicrophone(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = puRam0214f498;
  if (*psRam0214f494 == 0) {
    *psRam0214f494 = 1;
    *puVar1 = 0;
    puVar1[1] = 0;
    func_0214d5b8();
    do {
      iVar3 = Fifo_IsHandlerReady(9,1);
      uVar2 = uRam0214f4a0;
    } while (iVar3 == 0);
    *puRam0214f49c = 0;
    Fifo_RegisterHandler(9,uVar2);
    return;
  }
  return;
}

