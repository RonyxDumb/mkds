/* Decompiled C draft; module arm9_ov003; ROM address 021c5aa4. No matching claim. */
#include "types.h"
#include "deps/021c5aa4_FUN_021c5aa4.h"

void FUN_021c5aa4(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = func_0x02147cd8(*DAT_021c5b20,0x1c);
  iVar1 = 0x36 - iVar1;
  uVar5 = (uint)*(byte *)(*DAT_021c5b24 + 0x51);
  if (5 < uVar5) {
    uVar5 = 5;
  }
  iVar4 = 0;
  if (uVar5 != 0) {
    iVar3 = 0;
    do {
      puVar2 = *(uint **)(*DAT_021c5b24 + iVar3 + 0x10);
      *puVar2 = *puVar2 & DAT_021c5b28 | iVar1 - 2U & 0xff | DAT_021c5b2c;
      puVar2 = *(uint **)(*DAT_021c5b24 + iVar3 + 0x24);
      *puVar2 = *puVar2 & DAT_021c5b28 | iVar1 + 1U & 0xff | DAT_021c5b30;
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 0x1c;
    } while (iVar4 < (int)uVar5);
  }
  *(undefined1 *)(*DAT_021c5b24 + 0x56) = 1;
  return;
}

