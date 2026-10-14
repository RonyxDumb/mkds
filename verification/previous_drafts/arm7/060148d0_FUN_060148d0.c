/* Decompiled C draft; module arm7; ROM address 060148d0. No matching claim. */
#include "types.h"
#include "deps/060148d0_FUN_060148d0.h"

void FUN_060148d0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (*(uint *)(DAT_06014924 & 0xfffffffc) >> (DAT_06014924 & 3) * 8 |
          *(uint *)(DAT_06014924 & 0xfffffffc) << (DAT_06014924 & 3) * -8 + 0x20) + DAT_06014928;
  uVar1 = thunk_FUN_037f8850(0x1000000);
  *DAT_0601492c = 2;
  if (*(short *)(iVar2 + 0x3c) != 0) {
    FUN_0600db3c();
  }
  thunk_FUN_037f888c(uVar1);
  return;
}

