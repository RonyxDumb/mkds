/* Decompiled C draft; module arm9; ROM address 0210d65c. No matching claim. */
#include "types.h"
#include "deps/0210d65c_func_0210d65c.h"

void func_0210d65c(undefined4 *param_1)

{
  *param_1 = 3;
  if (*(char *)((int)param_1 + 10) != '\x03') {
    return;
  }
  if (*(char *)((int)param_1 + 0xb) != -1) {
    func_0210d7dc(*(undefined1 *)(iRam0210d6c4 + 0xb),
                  *(uint *)(uRam0210d6c8 & 0xfffffffc) >> (uRam0210d6c8 & 3) * 8 |
                  *(uint *)(uRam0210d6c8 & 0xfffffffc) << (uRam0210d6c8 & 3) * -8 + 0x20,
                  uRam0210d6c0);
    return;
  }
  return;
}

