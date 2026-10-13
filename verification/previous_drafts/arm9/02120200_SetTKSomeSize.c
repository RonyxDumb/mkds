/* Decompiled C draft; module arm9; ROM address 02120200. No matching claim. */
#include "types.h"
#include "deps/02120200_SetTKSomeSize.h"

void SetTKSomeSize(int param_1,undefined2 param_2)

{
  *(undefined2 *)
   (param_1 * 0x244 +
    (*(uint *)(uRam0212021c & 0xfffffffc) >> (uRam0212021c & 3) * 8 |
    *(uint *)(uRam0212021c & 0xfffffffc) << (uRam0212021c & 3) * -8 + 0x20) + 0x43e) = param_2;
  return;
}

