/* Decompiled C draft; module arm9; ROM address 0210d614. No matching claim. */
#include "types.h"
#include "deps/0210d614_func_0210d614.h"

void func_0210d614(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    param_3 = iRam0210d654;
  }
  if (*(char *)(param_1 + 0xb) != -1) {
    func_0210d7dc(param_2,*(uint *)(uRam0210d658 & 0xfffffffc) >> (uRam0210d658 & 3) * 8 |
                          *(uint *)(uRam0210d658 & 0xfffffffc) << (uRam0210d658 & 3) * -8 + 0x20,
                  param_3);
    return;
  }
  return;
}

