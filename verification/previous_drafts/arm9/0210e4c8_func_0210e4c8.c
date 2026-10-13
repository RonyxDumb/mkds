/* Decompiled C draft; module arm9; ROM address 0210e4c8. No matching claim. */
#include "types.h"
#include "deps/0210e4c8_func_0210e4c8.h"

void func_0210e4c8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = Sound_Context_BackupFrameState
                    (*(uint *)(uRam0210e4e8 & 0xfffffffc) >> (uRam0210e4e8 & 3) * 8 |
                     *(uint *)(uRam0210e4e8 & 0xfffffffc) << (uRam0210e4e8 & 3) * -8 + 0x20);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return;
}

