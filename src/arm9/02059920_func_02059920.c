/* Decompiled C draft; module arm9; ROM address 02059920. No matching claim. */
#include "types.h"
#include "deps/02059920_func_02059920.h"

void func_02059920(int param_1)

{
  short sVar1;
  
  if (((*(short *)(param_1 + 2) == 0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (3 < *(ushort *)(param_1 + 0x10))) {
    DC_SomeClean();
    sVar1 = *(short *)(param_1 + 4);
    if (((sVar1 != 7) && (sVar1 != 9)) && (sVar1 == 0x15)) {
      func_02059954((byte *)(uintptr_t)(*(undefined4 *)(param_1 + 0xc)));
    }
  }
  return;
}

