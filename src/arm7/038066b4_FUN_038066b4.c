/* Decompiled C draft; module arm7; ROM address 038066b4. No matching claim. */
#include "types.h"
#include "deps/038066b4_FUN_038066b4.h"

void FUN_038066b4(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = *param_2;
  if (param_2 != (undefined2 *)0x0) {
    FUN_037fb24c(0,(undefined4 *)(void *)(param_2),0x100);
    *param_2 = uVar1;
    param_2[1] = 4;
    do {
      iVar2 = FUN_037fb5f4(10,(int)(uintptr_t)(param_2),0);
    } while (iVar2 < 0);
  }
  return;
}

