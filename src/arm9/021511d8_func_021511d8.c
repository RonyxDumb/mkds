/* Decompiled C draft; module arm9; ROM address 021511d8. No matching claim. */
#include "types.h"
#include "deps/021511d8_func_021511d8.h"

void func_021511d8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  do {
    iVar1 = Fifo_IsHandlerReady(4,1);
  } while (iVar1 == 0);
  Fifo_RegisterHandler(4,uRam02151224);
  DC_SomeClean(param_3,param_2);
  while (iVar1 = FUN_02151288(2,param_1,param_2,param_3), iVar1 != 1) {
    WaitByLoop(uRam02151228);
  }
  return;
}

