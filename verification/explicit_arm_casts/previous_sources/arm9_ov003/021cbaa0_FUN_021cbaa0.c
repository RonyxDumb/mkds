/* Decompiled C draft; module arm9_ov003; ROM address 021cbaa0. No matching claim. */
#include "types.h"
#include "deps/021cbaa0_FUN_021cbaa0.h"

void FUN_021cbaa0(void)

{
  int iVar1;
  int iVar2;
  int local_18;
  undefined1 auStack_14 [10];
  char local_a;
  
  iVar1 = FUN_021cdb6c();
  func_0x0214d02c(DAT_021cbb0c,auStack_14,0xc);
  FUN_021c20dc(0,&local_18);
  if (local_18 == 2) {
    local_a = '\x04';
  }
  else {
    local_a = *(char *)(iVar1 + 0xf4) + '\x01';
  }
  iVar2 = func_0x02188868(auStack_14);
  if (iVar2 == 0) {
    func_0x0200fd1c();
  }
  if (local_18 == 0) {
    func_0x021886fc(*(undefined1 *)(iVar1 + 0xf4),iVar1);
  }
  FUN_021d3544(0,DAT_021cbb10,0,0x78);
  return;
}

