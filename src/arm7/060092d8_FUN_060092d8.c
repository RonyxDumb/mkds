/* Decompiled C draft; module arm7; ROM address 060092d8. No matching claim. */
#include "types.h"
#include "deps/060092d8_FUN_060092d8.h"

void FUN_060092d8(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_06009358 & 0xfffffffc) >> (DAT_06009358 & 3) * 8 |
          *(uint *)(DAT_06009358 & 0xfffffffc) << (DAT_06009358 & 3) * -8 + 0x20;
  if ((*(short *)(uVar2 + 0x3f4) != 0) && (iVar1 = FUN_06009138(uVar2 + 0x188,0x12), iVar1 != 0)) {
    *(short *)(iVar1 + 0xc) = (short)DAT_0600935c;
    *(undefined2 *)(iVar1 + 0xe) = 1;
    thunk_FUN_037f8850(0x1000000);
    *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(uVar2 + 0x3f4);
    *(undefined2 *)(uVar2 + 0x3f4) = 0;
    thunk_FUN_037f888c();
    FUN_0600f19c((*(uint *)(DAT_06009358 & 0xfffffffc) >> (DAT_06009358 & 3) * 8 |
                 *(uint *)(DAT_06009358 & 0xfffffffc) << (DAT_06009358 & 3) * -8 + 0x20) + 0x188,
                 iVar1);
  }
  return;
}

