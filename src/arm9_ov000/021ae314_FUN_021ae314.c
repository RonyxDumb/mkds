/* Decompiled C draft; module arm9_ov000; ROM address 021ae314. No matching claim. */
#include "types.h"
#include "deps/021ae314_FUN_021ae314.h"

undefined4 FUN_021ae314(void)

{
  longlong *plVar1;
  longlong lVar2;
  
  lVar2 = func_0x02133048((int)DAT_021ae33c[1],*(undefined4 *)((int)DAT_021ae33c + 0xc),
                          (int)*DAT_021ae33c,*(undefined4 *)((int)DAT_021ae33c + 4));
  plVar1 = DAT_021ae33c + 2;
  *DAT_021ae33c = lVar2 + *plVar1;
  return (int)((ulonglong)(lVar2 + *plVar1) >> 0x20);
}

