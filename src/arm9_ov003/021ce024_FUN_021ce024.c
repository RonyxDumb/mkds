/* Decompiled C draft; module arm9_ov003; ROM address 021ce024. No matching claim. */
#include "types.h"
#include "deps/021ce024_FUN_021ce024.h"

void FUN_021ce024(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  int local_2c;
  undefined1 *local_28;
  
  iVar2 = 0;
  local_2c = 0;
  puVar3 = (undefined1 *)(DAT_021ce0b4 + param_1 * 5);
  local_28 = (undefined1 *)(DAT_021ce0bc + param_1 * 5);
  puVar4 = DAT_021ce0b8;
  do {
    uVar1 = FUN_021d1974(*(undefined4 *)(*DAT_021ce0c0 + iVar2),0);
    FUN_021d1c3c(1,*puVar3,uVar1);
    FUN_021d1790(*(undefined4 *)(*DAT_021ce0c0 + iVar2),0xffffffff,0);
    FUN_021d17d4(*(undefined4 *)(*DAT_021ce0c0 + iVar2),0xffffffff,*puVar4,puVar4[1]);
    FUN_021d1890(*(undefined4 *)(*DAT_021ce0c0 + iVar2),0xffffffff,0,*local_28);
    iVar2 = iVar2 + 8;
    puVar3 = puVar3 + 2;
    puVar4 = puVar4 + 4;
    local_28 = local_28 + 2;
    local_2c = local_2c + 2;
  } while (local_2c < 5);
  FUN_021cdcf0(param_1);
  return;
}

