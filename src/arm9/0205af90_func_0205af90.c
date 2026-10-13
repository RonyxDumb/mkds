/* Decompiled C draft; module arm9; ROM address 0205af90. No matching claim. */
#include "types.h"
#include "deps/0205af90_func_0205af90.h"

void func_0205af90(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam0205afa4 & 0xfffffffc) >> (uRam0205afa4 & 3) * 8 |
    *(uint *)(uRam0205afa4 & 0xfffffffc) << (uRam0205afa4 & 3) * -8 + 0x20) + 0x72c) = 1;
  return;
}

