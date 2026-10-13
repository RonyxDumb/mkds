/* Decompiled C draft; module arm9_ov003; ROM address 021cb11c. No matching claim. */
#include "types.h"
#include "deps/021cb11c_FUN_021cb11c.h"

void FUN_021cb11c(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int local_28;
  
  puVar1 = DAT_021cb1cc;
  iVar4 = 0;
  iVar3 = 0;
  puVar5 = DAT_021cb1cc;
  do {
    local_28 = FUN_021cd844(iVar4);
    if (local_28 == 0xff) {
      local_28 = 3;
    }
    else {
      uVar2 = FUN_021d1be4(0,0x11,1);
      *(undefined4 *)(*DAT_021cb1d0 + iVar3 + 0x10) = uVar2;
      FUN_021d17d4(*(undefined4 *)(*DAT_021cb1d0 + iVar3 + 0x10),0xffffffff,puVar1[(iVar4 + 3) * 2],
                   puVar1[(iVar4 + 3) * 2 + 1]);
      FUN_021d1790(*(undefined4 *)(*DAT_021cb1d0 + iVar3 + 0x10),0xffffffff,3);
    }
    uVar2 = FUN_021d1be4(0,*(undefined1 *)(DAT_021cb1d4 + local_28),1);
    *(undefined4 *)(*DAT_021cb1d0 + iVar3 + 4) = uVar2;
    FUN_021d17d4(*(undefined4 *)(*DAT_021cb1d0 + iVar3 + 4),0xffffffff,*puVar5,puVar5[1]);
    FUN_021d1790(*(undefined4 *)(*DAT_021cb1d0 + iVar3 + 4),0xffffffff,3);
    iVar3 = iVar3 + 4;
    puVar5 = puVar5 + 2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return;
}

