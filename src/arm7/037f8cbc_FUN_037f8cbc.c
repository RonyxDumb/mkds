/* Decompiled C draft; module arm7; ROM address 037f8cbc. No matching claim. */
#include "types.h"
#include "deps/037f8cbc_FUN_037f8cbc.h"

void FUN_037f8cbc(void)

{
  int iVar1;
  
  if (*(uint *)((uint)DAT_037f8d24 & 0xfffffffc) >> ((uint)DAT_037f8d24 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_037f8d24 & 0xfffffffc) << ((uint)DAT_037f8d24 & 3) * -8 + 0x20 == 0) {
    *DAT_037f8d24 = 1;
    iVar1 = DAT_037f8d28;
    *(undefined2 *)(DAT_037f8d28 + 6) = 0;
    while (*(short *)(iVar1 + 4) != 0x7f) {
      FUN_037f8ae4();
    }
    *DAT_037f8d2c = 0xffffffff;
    *DAT_037f8d30 = 0xffff0000;
    *(undefined2 *)(iVar1 + 6) = 0xbf;
  }
  return;
}

