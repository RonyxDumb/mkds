/* Decompiled C draft; module arm9; ROM address 02051e58. No matching claim. */
#include "types.h"
#include "deps/02051e58_func_02051e58.h"

void func_02051e58(int param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02051e94 & 0xfffffffc) >> (uRam02051e94 & 3) * 8 |
    *(uint *)(uRam02051e94 & 0xfffffffc) << (uRam02051e94 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  return;
}

