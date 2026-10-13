/* Decompiled C draft; module arm9; ROM address 0200ae60. No matching claim. */
#include "types.h"
#include "deps/0200ae60_func_0200ae60.h"

void func_0200ae60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = Os_DisableIrq();
  puVar2 = (undefined4 *)(param_1 + 0x30);
  while( true ) {
    if ((undefined4 *)(param_1 + 0x70U) <= puVar2) {
      Os_Terminate();
    }
    if (puVar2[3] == 0) break;
    puVar2 = puVar2 + 4;
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  puVar2[2] = param_4;
  puVar2[3] = param_5;
  Os_RestoreIrq(uVar1);
  return;
}

