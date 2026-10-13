/* Decompiled C draft; module arm9; ROM address 02008934. No matching claim. */
#include "types.h"
#include "deps/02008934_func_02008934.h"

int func_02008934(uint param_1)

{
  if (((uint)*(ushort *)(*piRam02008954 + 2) & 1 << (param_1 & 0xff)) == 0) {
    return 0;
  }
  return *piRam02008954 + 0x10 + iRam02008958 * param_1;
}

