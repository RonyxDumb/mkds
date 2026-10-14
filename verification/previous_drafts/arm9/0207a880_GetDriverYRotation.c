/* Decompiled C draft; module arm9; ROM address 0207a880. No matching claim. */
#include "types.h"
#include "deps/0207a880_GetDriverYRotation.h"

undefined2 GetDriverYRotation(int param_1)

{
  return *(undefined2 *)
          (param_1 * iRam0207a8a0 +
           (*(uint *)(uRam0207a89c & 0xfffffffc) >> (uRam0207a89c & 3) * 8 |
           *(uint *)(uRam0207a89c & 0xfffffffc) << (uRam0207a89c & 3) * -8 + 0x20) + 0x236);
}

