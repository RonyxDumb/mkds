/* Decompiled C draft; module arm9; ROM address 02051364. No matching claim. */
#include "types.h"
#include "deps/02051364_func_02051364.h"

void func_02051364(int param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020513a8 & 0xfffffffc) >> (uRam020513a8 & 3) * 8 |
    *(uint *)(uRam020513a8 & 0xfffffffc) << (uRam020513a8 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  func_02053fa8();
  return;
}

