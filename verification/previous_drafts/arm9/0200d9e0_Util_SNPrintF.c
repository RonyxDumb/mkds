/* Decompiled C draft; module arm9; ROM address 0200d9e0. No matching claim. */
#include "types.h"
#include "deps/0200d9e0_Util_SNPrintF.h"

void Util_SNPrintF(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  Util_VSNPrintF((undefined1 *)(uintptr_t)(param_1),param_2,(byte *)(uintptr_t)(param_3),(ushort *)(void *)(&uStack_4));
  return;
}

