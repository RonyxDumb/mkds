/* Decompiled C draft; module arm9; ROM address 0210d6cc. No matching claim. */
#include "types.h"
#include "deps/0210d6cc_func_0210d6cc.h"

void func_0210d6cc(undefined4 *param_1)

{
  *param_1 = 2;
  if (*(char *)((int)param_1 + 10) != '\x02') {
    return;
  }
  if (*(char *)((int)param_1 + 0xb) != -1) {
    func_0210d7dc(*(undefined1 *)(iRam0210d734 + 0xb),
                  *(uint *)(uRam0210d738 & 0xfffffffc) >> (uRam0210d738 & 3) * 8 |
                  *(uint *)(uRam0210d738 & 0xfffffffc) << (uRam0210d738 & 3) * -8 + 0x20,
                  uRam0210d730);
    return;
  }
  return;
}

