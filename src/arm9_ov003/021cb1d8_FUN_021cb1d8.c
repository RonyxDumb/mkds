/* Decompiled C draft; module arm9_ov003; ROM address 021cb1d8. No matching claim. */
#include "types.h"
#include "deps/021cb1d8_FUN_021cb1d8.h"

void FUN_021cb1d8(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_20 [32];
  
  puVar4 = local_20;
  iVar3 = 0x16;
  puVar5 = DAT_021cb25c;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_021bf620(DAT_021cb260,DAT_021cb264);
  FUN_021bf620(DAT_021cb268,DAT_021cb26c);
  FUN_021bf620(DAT_021cb270,DAT_021cb274);
  FUN_021bf620(DAT_021cb278,DAT_021cb27c);
  uVar2 = FUN_021bf650((int)(uintptr_t)(local_20));
  uVar2 = FUN_021d14b8(uVar2,0,4);
  *(undefined4 *)*DAT_021cb280 = uVar2;
  FUN_021d2784(1,0x10);
  *DAT_021cb284 = *DAT_021cb284 & 0xfffc | 3;
  *DAT_021cb288 = *DAT_021cb288 & 0xfffc | 3;
  *DAT_021cb28c = *DAT_021cb28c & 0xfffc | 3;
  *DAT_021cb290 = *DAT_021cb290 & 0xfffc | 3;
  return;
}

