/* Decompiled C draft; module arm9_ov003; ROM address 021c29d8. No matching claim. */
#include "types.h"
#include "deps/021c29d8_FUN_021c29d8.h"

void FUN_021c29d8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_021d283c(0xc,0xfffffffc);
  *DAT_021c2a14 = uVar1;
  iVar2 = FUN_021bb168(0xf,0x40,DAT_021c2a20,DAT_021c2a24,DAT_021c2a18,DAT_021c2a1c);
  if (iVar2 != 1) {
    func_0x0200fd1c();
  }
  func_0x0200dc3c(10);
  return;
}

