/* Decompiled C draft; module arm9_ov003; ROM address 021c2b28. No matching claim. */
#include "types.h"
#include "deps/021c2b28_FUN_021c2b28.h"

void FUN_021c2b28(void)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_021cdb90();
  FUN_021c25b4();
  FUN_021bf7f4();
  FUN_021bf8c0();
  FUN_021bf4d0();
  iVar2 = FUN_021c20d0();
  if ((iVar2 == 1) && (iVar2 = FUN_021c20a8(2), iVar2 != 0)) {
    uVar3 = FUN_021c2564(DAT_021c2c28);
    *DAT_021c2c2c = uVar3;
  }
  else {
    iVar2 = FUN_021c20d0();
    uVar3 = FUN_021c2564(*(undefined4 *)(DAT_021c2c30 + iVar2 * 4));
    *DAT_021c2c2c = uVar3;
  }
  uVar3 = FUN_021bf650(DAT_021c2c34);
  FUN_021d1cb0(1,uVar3);
  uVar3 = FUN_021bf650(DAT_021c2c38);
  FUN_021d1cb0(0,uVar3);
  FUN_021bf620(DAT_021c2c3c,DAT_021c2c40);
  FUN_021bf620(DAT_021c2c44,DAT_021c2c48);
  FUN_021bf620(DAT_021c2c4c,DAT_021c2c50);
  FUN_021bf620(DAT_021c2c54,DAT_021c2c58);
  FUN_021bf620(DAT_021c2c5c,DAT_021c2c60);
  FUN_021bf620(DAT_021c2c64,DAT_021c2c68);
  FUN_021bf620(DAT_021c2c6c,DAT_021c2c70);
  FUN_021bf620(DAT_021c2c74,DAT_021c2c78);
  iVar2 = FUN_021c20c0();
  if (iVar2 == 0) {
    FUN_021bf620(DAT_021c2c7c,DAT_021c2c80);
  }
  else if (iVar2 == 1) {
    FUN_021bf620(DAT_021c2c84,DAT_021c2c80);
  }
  *DAT_021c2c88 = *DAT_021c2c88 & 0xfffc | 3;
  puVar1 = DAT_021c2c8c;
  *DAT_021c2c8c = *DAT_021c2c8c & 0xfffc | 3;
  *puVar1 = *puVar1 & 0xfffc | 3;
  FUN_021d2784(1,2);
  FUN_021d2784(0,2);
  FUN_021c212c(DAT_021c2c90);
  return;
}

