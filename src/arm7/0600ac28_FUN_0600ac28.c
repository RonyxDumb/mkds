/* Decompiled C draft; module arm7; ROM address 0600ac28. No matching claim. */
#include "types.h"
#include "deps/0600ac28_FUN_0600ac28.h"

void FUN_0600ac28(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_0600ac70;
  *(undefined2 *)
   ((*(uint *)(DAT_0600ac70 & 0xfffffffc) >> (DAT_0600ac70 & 3) * 8 |
    *(uint *)(DAT_0600ac70 & 0xfffffffc) << (DAT_0600ac70 & 3) * -8 + 0x20) + 0x3ea) = 1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (*(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x468) != 0) {
    return;
  }
  *DAT_0600ac74 = *DAT_0600ac74 & 0xfffd;
  *DAT_0600ac78 = 0;
  return;
}

