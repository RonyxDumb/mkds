/* Decompiled C draft; module arm9; ROM address 0210d5c0. No matching claim. */
#include "types.h"
#include "deps/0210d5c0_func_0210d5c0.h"

void func_0210d5c0(int param_1)

{
  if (*(char *)(param_1 + 0xb) != -1) {
    func_0210d7dc(*(undefined1 *)(iRam0210d60c + 0xb),
                  *(uint *)(uRam0210d610 & 0xfffffffc) >> (uRam0210d610 & 3) * 8 |
                  *(uint *)(uRam0210d610 & 0xfffffffc) << (uRam0210d610 & 3) * -8 + 0x20,
                  uRam0210d608);
    return;
  }
  return;
}

