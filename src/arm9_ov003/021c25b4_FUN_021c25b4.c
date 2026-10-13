/* Decompiled C draft; module arm9_ov003; ROM address 021c25b4. No matching claim. */
#include "types.h"
#include "deps/021c25b4_FUN_021c25b4.h"

void FUN_021c25b4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021d285c(100,4);
  *DAT_021c25dc = iVar1;
  uVar2 = FUN_021d1d60(8,iVar1,0xc);
  *(undefined4 *)(*DAT_021c25dc + 0x60) = uVar2;
  return;
}

