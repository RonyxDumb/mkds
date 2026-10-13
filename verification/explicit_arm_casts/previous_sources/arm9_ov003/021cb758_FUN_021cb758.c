/* Decompiled C draft; module arm9_ov003; ROM address 021cb758. No matching claim. */
#include "types.h"
#include "deps/021cb758_FUN_021cb758.h"

void FUN_021cb758(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_20 [32];
  
  puVar4 = local_20;
  iVar3 = 0x16;
  puVar5 = DAT_021cb7cc;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_021bf620(DAT_021cb7d0,DAT_021cb7d4);
  FUN_021bf620(DAT_021cb7d8,DAT_021cb7dc);
  FUN_021bf620(DAT_021cb7e0,DAT_021cb7e4);
  uVar2 = FUN_021bf650(local_20);
  uVar2 = FUN_021d14b8(uVar2,0,4);
  *DAT_021cb7e8 = uVar2;
  *DAT_021cb7ec = *DAT_021cb7ec & 0xfffc | 3;
  *DAT_021cb7f0 = *DAT_021cb7f0 & 0xfffc | 3;
  *DAT_021cb7f4 = *DAT_021cb7f4 & 0xfffc | 3;
  *DAT_021cb7f8 = *DAT_021cb7f8 & 0xfffc | 3;
  return;
}

