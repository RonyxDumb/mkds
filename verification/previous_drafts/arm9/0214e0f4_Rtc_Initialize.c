/* Decompiled C draft; module arm9; ROM address 0214e0f4. No matching claim. */
#include "types.h"
#include "deps/0214e0f4_Rtc_Initialize.h"

void Rtc_Initialize(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = puRam0214e174;
  if (*psRam0214e170 == 0) {
    *psRam0214e170 = 1;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[7] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    func_0214d5b8();
    do {
      iVar2 = Fifo_IsHandlerReady(5,1);
    } while (iVar2 == 0);
    Fifo_RegisterHandler(5,uRam0214e178);
    return;
  }
  return;
}

