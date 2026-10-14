/* Decompiled C draft; module arm9; ROM address 02142c24. No matching claim. */
#include "types.h"
#include "deps/02142c24_func_02142c24.h"

int func_02142c24(void)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = Wm_CheckInitialized();
  if (iVar2 != 0) {
    return 3;
  }
  iVar2 = func_02142988(1,0);
  if (iVar2 == 0) {
    Wm_DisableCallbackControl();
    Fifo_RegisterHandler(10,0);
    puVar1 = puRam02142c94;
    *puRam02142c90 = 0;
    *puVar1 = 0;
    return 0;
  }
  return iVar2;
}

