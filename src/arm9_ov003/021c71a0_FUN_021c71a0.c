/* Decompiled C draft; module arm9_ov003; ROM address 021c71a0. No matching claim. */
#include "types.h"
#include "deps/021c71a0_FUN_021c71a0.h"

void FUN_021c71a0(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  int iVar5;
  ushort local_18 [2];
  
  uVar1 = *(undefined2 *)(DAT_021c7218 + 2);
  uVar2 = *DAT_021c721c;
  uVar3 = DAT_021c721c[1];
  FUN_021d2060(*(undefined4 *)*DAT_021c7220,0);
  iVar5 = 0;
  local_18[1] = 0;
  puVar4 = DAT_021c7224;
  do {
    local_18[0] = (ushort)*(byte *)(*DAT_021c7220 + iVar5 + 8);
    FUN_021d2070(*(undefined4 *)*DAT_021c7220,*puVar4,uVar1,uVar2,uVar3,2,DAT_021c7228,local_18,
                 *puVar4);
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xc);
  FUN_021d1fd0(*(undefined4 *)*DAT_021c7220);
  return;
}

