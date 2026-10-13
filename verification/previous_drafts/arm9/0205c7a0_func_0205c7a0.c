/* Decompiled C draft; module arm9; ROM address 0205c7a0. No matching claim. */
#include "types.h"
#include "deps/0205c7a0_func_0205c7a0.h"

void func_0205c7a0(uint param_1)

{
  int iVar1;
  
  if (param_1 == 0xffffffff) {
    return;
  }
  param_1 = param_1 & 0xff;
  if (((uint)*(byte *)((*(uint *)(uRam0205c7fc & 0xfffffffc) >> (uRam0205c7fc & 3) * 8 |
                       *(uint *)(uRam0205c7fc & 0xfffffffc) << (uRam0205c7fc & 3) * -8 + 0x20) +
                      0x749) & 1 << param_1) != 0) {
    iVar1 = func_0205c340(param_1,1,8);
    if (iVar1 != 0) {
      *(short *)((*(uint *)(uRam0205c7fc & 0xfffffffc) >> (uRam0205c7fc & 3) * 8 |
                 *(uint *)(uRam0205c7fc & 0xfffffffc) << (uRam0205c7fc & 3) * -8 + 0x20) + 0xf8) =
           (short)param_1;
    }
    return;
  }
  return;
}

