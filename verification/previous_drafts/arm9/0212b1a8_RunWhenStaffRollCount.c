/* Decompiled C draft; module arm9; ROM address 0212b1a8. No matching claim. */
#include "types.h"
#include "deps/0212b1a8_RunWhenStaffRollCount.h"

void RunWhenStaffRollCount(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam0212b1bc & 0xfffffffc) >> (uRam0212b1bc & 3) * 8 |
    *(uint *)(uRam0212b1bc & 0xfffffffc) << (uRam0212b1bc & 3) * -8 + 0x20) + 4) = 1;
  return;
}

