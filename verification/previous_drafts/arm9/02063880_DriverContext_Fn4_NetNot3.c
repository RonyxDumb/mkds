/* Decompiled C draft; module arm9; ROM address 02063880. No matching claim. */
#include "types.h"
#include "deps/02063880_DriverContext_Fn4_NetNot3.h"

void DriverContext_Fn4_NetNot3(undefined4 param_1)

{
  func_01ffcb58();
  if ((*(ushort *)
        ((*(uint *)(uRam020638bc & 0xfffffffc) >> (uRam020638bc & 3) * 8 |
         *(uint *)(uRam020638bc & 0xfffffffc) << (uRam020638bc & 3) * -8 + 0x20) + 0x75c) & 2) != 0)
  {
    func_020636f8(param_1);
  }
  func_020641f0(param_1);
  return;
}

