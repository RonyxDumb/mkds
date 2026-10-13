/* Decompiled C draft; module arm9; ROM address 020d0ec4. No matching claim. */
#include "types.h"
#include "deps/020d0ec4_func_020d0ec4.h"

undefined4 func_020d0ec4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*piRam020d0ee4 == 0) || (iVar1 = WorkerHasPendingTask(), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

