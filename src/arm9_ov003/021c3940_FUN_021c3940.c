/* Decompiled C draft; module arm9_ov003; ROM address 021c3940. No matching claim. */
#include "types.h"
#include "deps/021c3940_FUN_021c3940.h"

void FUN_021c3940(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (param_1 == 1) {
    bVar1 = func_0x02147cd8(*DAT_021c3990 + 2,3);
    *DAT_021c3990 = bVar1;
  }
  else {
    bVar1 = func_0x02147cd8(*DAT_021c3990 + 1,3);
    *DAT_021c3990 = bVar1;
  }
  FUN_021cdc10(8);
  iVar2 = (uint)*DAT_021c3990 * 8;
  FUN_021bf6c8(*(undefined2 *)(DAT_021c3994 + iVar2),*(undefined2 *)(DAT_021c3998 + iVar2),
               *(undefined2 *)(DAT_021c399c + iVar2),*(undefined2 *)(DAT_021c39a0 + iVar2));
  return;
}

