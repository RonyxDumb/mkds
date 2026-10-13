/* Decompiled C draft; module arm9; ROM address 020ffc4c. No matching claim. */
#include "types.h"
#include "deps/020ffc4c_func_020ffc4c.h"

void func_020ffc4c(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(param_1 + 0xa6);
  *(uint *)(param_1 + 0xbc) =
       iRam020ffc94 -
       (uVar1 - iRam020ffc94 *
                ((int)(uVar1 + (int)((ulonglong)((longlong)iRam020ffc90 * (longlong)(int)uVar1) >>
                                    0x20)) >> 0xc));
  return;
}

