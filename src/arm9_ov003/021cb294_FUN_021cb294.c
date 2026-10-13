/* Decompiled C draft; module arm9_ov003; ROM address 021cb294. No matching claim. */
#include "types.h"
#include "deps/021cb294_FUN_021cb294.h"

void FUN_021cb294(void)

{
  int iVar1;
  
  iVar1 = FUN_021d283c(0x20,4);
  *DAT_021cb2d8 = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 0;
  FUN_021cb1d8();
  FUN_021bf86c(1);
  FUN_021bf43c(0x7b,0xffffffff);
  FUN_021bf5ec(0);
  FUN_021cb11c();
  FUN_021caca8();
  FUN_021c212c(DAT_021cb2dc);
  return;
}

