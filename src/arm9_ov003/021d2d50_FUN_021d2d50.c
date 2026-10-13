/* Decompiled C draft; module arm9_ov003; ROM address 021d2d50. No matching claim. */
#include "types.h"
#include "deps/021d2d50_FUN_021d2d50.h"

void FUN_021d2d50(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  uVar1 = FUN_021d283c(0x3a,4);
  *DAT_021d2da0 = uVar1;
  iVar2 = func_0x0214eadc((undefined2 *)(void *)(auStack_10));
  if (iVar2 == 0) {
    func_0x0200fd1c();
  }
  func_0x0214e994((short *)(void *)(auStack_10));
  func_0x0214e788(0,4,*DAT_021d2da0,5);
  func_0x0214e31c(2);
  iVar2 = func_0x0214e308(2);
  if (iVar2 != 0) {
    func_0x0200fd1c();
  }
  FUN_021d2d14();
  return;
}

