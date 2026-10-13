/* Decompiled C draft; module arm7; ROM address 0600ae2c. No matching claim. */
#include "types.h"
#include "deps/0600ae2c_FUN_0600ae2c.h"

undefined4 FUN_0600ae2c(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600ae98 & 0xfffffffc) >> (DAT_0600ae98 & 3) * 8 |
          *(uint *)(DAT_0600ae98 & 0xfffffffc) << (DAT_0600ae98 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x352) = (short)param_1;
  if ((param_1 == 0) || (*(short *)(uVar1 + 0x32e) == 1)) {
    *DAT_0600ae9c = *DAT_0600ae9c & 0xffbf;
    FUN_0600b908(*(undefined2 *)(uVar1 + 0x33c),0);
  }
  else {
    *DAT_0600ae9c = *DAT_0600ae9c | 0x40;
  }
  return 0;
}

