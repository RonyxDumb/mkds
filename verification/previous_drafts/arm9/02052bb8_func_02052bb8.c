/* Decompiled C draft; module arm9; ROM address 02052bb8. No matching claim. */
#include "types.h"
#include "deps/02052bb8_func_02052bb8.h"

void func_02052bb8(int param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam02052bf4 & 0xfffffffc) >> (uRam02052bf4 & 3) * 8 |
    *(uint *)(uRam02052bf4 & 0xfffffffc) << (uRam02052bf4 & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  return;
}

