/* Decompiled C draft; module arm9; ROM address 0210c084. No matching claim. */
#include "types.h"
#include "deps/0210c084_func_0210c084.h"

void func_0210c084(int param_1)

{
  func_0212c6f0();
  *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xfb;
  *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xf7;
  *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xfd;
  return;
}

