/* Decompiled C draft; module arm9; ROM address 020f8d9c. No matching claim. */
#include "types.h"
#include "deps/020f8d9c_func_020f8d9c.h"

void func_020f8d9c(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x48) = param_2;
  AllocateNewDriverSub208(param_1 + iRam020f8dd4);
  StructMQRacerEntry_SomeFn_45
            (param_1,*(undefined4 *)(*piRam020f8dd8 + param_3 * 0xa8 + 0xa0),param_1 + 0x50);
  func_02109054(param_1);
  return;
}

