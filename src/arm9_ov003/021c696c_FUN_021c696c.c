/* Decompiled C draft; module arm9_ov003; ROM address 021c696c. No matching claim. */
#include "types.h"
#include "deps/021c696c_FUN_021c696c.h"

void FUN_021c696c(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int local_28;
  ushort local_1c [4];
  
  uVar1 = *DAT_021c6a00;
  uVar4 = *DAT_021c6a04;
  uVar5 = DAT_021c6a04[1];
  FUN_021d2060(*(undefined4 *)*DAT_021c6a08);
  iVar6 = 0;
  local_1c[1] = 0;
  iVar7 = 0;
  uVar2 = DAT_021c6a00[1];
  local_28 = 0;
  do {
    if (iVar6 == 0x10) {
      iVar7 = local_28;
      uVar1 = uVar2;
    }
    bVar3 = *(byte *)(*DAT_021c6a08 + iVar6 + 8);
    if (bVar3 == 0x20) {
      local_1c[0] = (ushort)DAT_021c6a0c;
    }
    else {
      local_1c[0] = (ushort)bVar3;
    }
    FUN_021d2070(*(undefined4 *)*DAT_021c6a08,*(undefined1 *)(DAT_021c6a10 + iVar7),uVar1,uVar4,
                 uVar5,2,DAT_021c6a14,local_1c);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar6 < 0x20);
  FUN_021d1fd0(*(undefined4 *)*DAT_021c6a08);
  return;
}

