/* Decompiled C draft; module arm9; ROM address 02151154. No matching claim. */
#include "types.h"
#include "deps/02151154_func_02151154.h"

undefined4 func_02151154(void)

{
  undefined4 uVar1;
  int iVar2;
  
  do {
    iVar2 = Fifo_IsHandlerReady(4,1);
  } while (iVar2 == 0);
  Fifo_RegisterHandler(4,uRam02151194);
  uVar1 = uRam02151198;
  while (iVar2 = FUN_02151288(7,0,0,0), iVar2 != 1) {
    WaitByLoop(uVar1);
  }
  return 1;
}

