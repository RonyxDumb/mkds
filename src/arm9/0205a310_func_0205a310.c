/* Decompiled C draft; module arm9; ROM address 0205a310. No matching claim. */
#include "types.h"
#include "deps/0205a310_func_0205a310.h"

bool func_0205a310(int param_1)

{
  return ((uint)*(ushort *)
                 (param_1 * 0x88 +
                  (*(uint *)(uRam0205a348 & 0xfffffffc) >> (uRam0205a348 & 3) * 8 |
                  *(uint *)(uRam0205a348 & 0xfffffffc) << (uRam0205a348 & 3) * -8 + 0x20) + 0x178) +
          iRam0205a34c & 0xffff) < 2;
}

