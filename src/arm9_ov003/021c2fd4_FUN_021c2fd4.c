/* Decompiled C draft; module arm9_ov003; ROM address 021c2fd4. No matching claim. */
#include "types.h"
#include "deps/021c2fd4_FUN_021c2fd4.h"

void FUN_021c2fd4(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 local_20 [32];
  
  puVar4 = local_20;
  iVar3 = 0x16;
  puVar5 = DAT_021c3048;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_021bf620(DAT_021c304c,DAT_021c3050);
  FUN_021bf620(DAT_021c3054,DAT_021c3058);
  FUN_021bf620(DAT_021c305c,DAT_021c3060);
  uVar2 = FUN_021bf650((int)(uintptr_t)(local_20));
  uVar2 = FUN_021d14b8(uVar2,0,4);
  *DAT_021c3064 = uVar2;
  *DAT_021c3068 = *DAT_021c3068 & 0xfffc | 3;
  *DAT_021c306c = *DAT_021c306c & 0xfffc | 3;
  *DAT_021c3070 = *DAT_021c3070 & 0xfffc | 3;
  *DAT_021c3074 = *DAT_021c3074 & 0xfffc | 3;
  return;
}

