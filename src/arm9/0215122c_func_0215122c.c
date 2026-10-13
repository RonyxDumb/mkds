/* Decompiled C draft; module arm9; ROM address 0215122c. No matching claim. */
#include "types.h"
#include "deps/0215122c_func_0215122c.h"

undefined4 func_0215122c(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  DC_InvalidateRangeNoClean(param_3);
  do {
    iVar1 = Fifo_IsHandlerReady(4,1);
  } while (iVar1 == 0);
  Fifo_RegisterHandler(4,uRam02151280);
  while (iVar1 = FUN_02151288(1,param_1,param_2 & 0xffff,param_3), iVar1 != 1) {
    WaitByLoop(uRam02151284);
  }
  DC_InvalidateRangeNoClean(param_3,param_2);
  return 1;
}

