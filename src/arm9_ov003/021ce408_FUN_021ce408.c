/* Decompiled C draft; module arm9_ov003; ROM address 021ce408. No matching claim. */
#include "types.h"
#include "deps/021ce408_FUN_021ce408.h"

void FUN_021ce408(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int local_2c;
  undefined1 *local_28;
  
  iVar1 = FUN_021d283c(0x1c,4);
  *DAT_021ce4c0 = iVar1;
  local_2c = 0;
  puVar4 = (undefined1 *)(DAT_021ce4c4 + param_1 * 5);
  iVar3 = 0;
  local_28 = (undefined1 *)(DAT_021ce4cc + param_1 * 5);
  iVar1 = DAT_021ce4c8;
  do {
    uVar2 = FUN_021d1be4(1,*puVar4,1);
    *(undefined4 *)(*DAT_021ce4c0 + iVar3) = uVar2;
    FUN_021d1790(*(undefined4 *)(*DAT_021ce4c0 + iVar3),0xffffffff,0);
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce4c0 + iVar3),0xffffffff,0xffffffd6,
                 *(undefined2 *)(iVar1 + 2));
    FUN_021d1890(*(undefined4 *)(*DAT_021ce4c0 + iVar3),0xffffffff,0,*local_28);
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 4;
    iVar1 = iVar1 + 4;
    local_28 = local_28 + 1;
    local_2c = local_2c + 1;
  } while (local_2c < 5);
  uVar2 = FUN_021d3544(0,DAT_021ce4d0,0,0x78);
  *(undefined4 *)(*DAT_021ce4c0 + 0x14) = uVar2;
  FUN_021cdcf0(param_1);
  FUN_021cdc10(0xd);
  return;
}

