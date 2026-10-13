/* Decompiled C draft; module arm9_ov003; ROM address 021c5c68. No matching claim. */
#include "types.h"
#include "deps/021c5c68_FUN_021c5c68.h"

void FUN_021c5c68(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = func_0x02147d30(*DAT_021c5cd4,0x1c);
  uVar4 = (uint)*(byte *)(*DAT_021c5cd8 + 0x51);
  FUN_021d2060(*(undefined4 *)(*DAT_021c5cd8 + 0xc),0);
  if (5 < uVar4) {
    uVar4 = 5;
  }
  iVar2 = 0;
  iVar3 = iVar1;
  if (uVar4 != 0) {
    do {
      FUN_021c5b90(iVar3,iVar2);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar2 < (int)uVar4);
  }
  iVar3 = 0;
  if (uVar4 != 0) {
    do {
      FUN_021c5b34(iVar1,iVar3);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 1;
    } while (iVar3 < (int)uVar4);
  }
  FUN_021d1fd0(*(undefined4 *)(*DAT_021c5cd8 + 0xc));
  FUN_021c5aa4();
  return;
}

