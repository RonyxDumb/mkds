/* Decompiled C draft; module arm9; ROM address 0200e260. No matching claim. */
#include "types.h"
#include "deps/0200e260_Os_Thread_Exit.h"

void Os_Thread_Exit(void)

{
  uint uVar1;
  uint uVar2;
  
  Os_DisableIrq();
  uVar1 = iRam0200e288 + 4U & 3;
  uVar2 = *(uint *)(iRam0200e288 + 4U & 0xfffffffc);
  Os_Thread_ExitImpl(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  return;
}

