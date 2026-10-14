/* Decompiled C draft; module arm7; ROM address 0600d51c. No matching claim. */
#include "types.h"
#include "deps/0600d51c_FUN_0600d51c.h"

void FUN_0600d51c(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600d588 & 0xfffffffc) >> (DAT_0600d588 & 3) * 8 |
          *(uint *)(DAT_0600d588 & 0xfffffffc) << (DAT_0600d588 & 3) * -8 + 0x20;
  *DAT_0600d58c = 0x2000;
  *DAT_0600d590 = 0xd;
  if (*(short *)(uVar1 + 0x35e) == 1) {
    *(undefined2 *)(uVar1 + 0x35e) = 2;
    return;
  }
  if (*(short *)(uVar1 + 0x35e) != 2) {
    if (*(short *)(uVar1 + 0x350) == 2) {
      if (*(short *)(uVar1 + 0x34c) != 0x40) {
        *DAT_0600d594 = 0;
      }
      return;
    }
    return;
  }
  *(undefined2 *)(uVar1 + 0x35e) = 0;
  return;
}

