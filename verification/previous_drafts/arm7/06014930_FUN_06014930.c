/* Decompiled C draft; module arm7; ROM address 06014930. No matching claim. */
#include "types.h"
#include "deps/06014930_FUN_06014930.h"

void FUN_06014930(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (*(uint *)(DAT_060149a4 & 0xfffffffc) >> (DAT_060149a4 & 3) * 8 |
          *(uint *)(DAT_060149a4 & 0xfffffffc) << (DAT_060149a4 & 3) * -8 + 0x20) + DAT_060149a8;
  uVar1 = thunk_FUN_037f8850(0x1000000);
  if (-1 < (int)((uint)*(ushort *)
                        ((*(uint *)(DAT_060149a4 & 0xfffffffc) >> (DAT_060149a4 & 3) * 8 |
                         *(uint *)(DAT_060149a4 & 0xfffffffc) << (DAT_060149a4 & 3) * -8 + 0x20) +
                        0x33a) << 0x18)) {
    FUN_0600aa0c(0);
  }
  *DAT_060149ac = 0xc0;
  *(undefined2 *)(iVar2 + 0x50) = 0;
  *(undefined2 *)(iVar2 + 100) = 0;
  thunk_FUN_037f888c(uVar1);
  return;
}

