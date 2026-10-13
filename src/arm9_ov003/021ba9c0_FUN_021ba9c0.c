/* Decompiled C draft; module arm9_ov003; ROM address 021ba9c0. No matching claim. */
#include "types.h"
#include "deps/021ba9c0_FUN_021ba9c0.h"

undefined4 FUN_021ba9c0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0200fca0();
  if (*DAT_021baa24 != 3) {
    iVar2 = FUN_021bac0c();
    if (iVar2 == 1) {
      *DAT_021baa24 = 2;
      func_0x0200fcb4(uVar1);
      return 1;
    }
    func_0x0200fcb4(uVar1);
    return 0;
  }
  iVar2 = func_0x021a61e4();
  if (iVar2 != 3) {
    func_0x0200fcb4(uVar1);
    return 0;
  }
  *DAT_021baa24 = 2;
  func_0x0200fcb4(uVar1);
  return 1;
}

