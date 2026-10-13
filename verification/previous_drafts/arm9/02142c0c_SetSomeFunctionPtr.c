/* Decompiled C draft; module arm9; ROM address 02142c0c. No matching claim. */
#include "types.h"
#include "deps/02142c0c_SetSomeFunctionPtr.h"

void SetSomeFunctionPtr(int param_1,undefined4 param_2)

{
  *(undefined4 *)
   ((*(uint *)(uRam02142c20 & 0xfffffffc) >> (uRam02142c20 & 3) * 8 |
    *(uint *)(uRam02142c20 & 0xfffffffc) << (uRam02142c20 & 3) * -8 + 0x20) + param_1 * 4 + 0x18) =
       param_2;
  return;
}

