/* Decompiled C draft; module arm9; ROM address 02039b94. No matching claim. */
#include "types.h"
#include "deps/02039b94_func_02039b94.h"

void func_02039b94(void)

{
  switch(*(uint *)(DAT_02039bd0 & 0xfffffffc) >> (DAT_02039bd0 & 3) * 8 |
         *(uint *)(DAT_02039bd0 & 0xfffffffc) << (DAT_02039bd0 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_02039bc0;
  case 2:
    break;
  case 3:
LAB_02039bc0:
    func_021492f8();
  }
  return;
}

