/* Decompiled C draft; module arm9_ov003; ROM address 021cefc0. No matching claim. */
#include "types.h"
#include "deps/021cefc0_FUN_021cefc0.h"

void FUN_021cefc0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int local_34;
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1c [2];
  
  local_24[0] = *DAT_021cf1a8;
  local_24[1] = DAT_021cf1a8[1];
  local_24[2] = DAT_021cf1a8[2];
  local_24[3] = DAT_021cf1a8[3];
  local_20 = DAT_021cf1a8[4];
  local_1f = DAT_021cf1a8[5];
  uVar2 = FUN_021c250c(*DAT_021cf1ac,param_1,param_4,param_5);
  iVar3 = FUN_021d283c(0x20,4);
  piVar1 = DAT_021cf1b0;
  *DAT_021cf1b0 = iVar3;
  *(char *)(iVar3 + 0x1c) = (char)param_2;
  *(undefined1 *)(*piVar1 + 0x1b) = 0xfe;
  *(char *)(*piVar1 + 0x1e) = (char)param_3;
  func_0x0214a3e8(DAT_021cf1b4,0x1f,0);
  uVar4 = FUN_021d1be4(0,*(undefined1 *)(DAT_021cf1b8 + param_2),0);
  piVar1 = DAT_021cf1b0;
  *(undefined4 *)*DAT_021cf1b0 = uVar4;
  FUN_021d17d4(*(undefined4 *)*piVar1,0xffffffff,DAT_021cf1bc);
  FUN_021d1790(*(undefined4 *)*DAT_021cf1b0,0xffffffff);
  local_34 = 0;
  if (*(char *)(DAT_021cf1c0 + param_2) != '\0') {
    puVar6 = (undefined1 *)(DAT_021cf1c4 + param_2 * 2);
    iVar3 = 0;
    pbVar5 = (byte *)(DAT_021cf1c0 + param_2);
    do {
      uVar4 = FUN_021d1be4(0,*puVar6,0);
      *(undefined4 *)(*DAT_021cf1b0 + iVar3 + 8) = uVar4;
      FUN_021d17d4(*(undefined4 *)(*DAT_021cf1b0 + iVar3 + 8),0xffffffff,DAT_021cf1bc,0);
      FUN_021d1790(*(undefined4 *)(*DAT_021cf1b0 + iVar3 + 8),0xffffffff,0);
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + 4;
      local_34 = local_34 + 1;
    } while (local_34 < (int)(uint)*pbVar5);
  }
  uVar4 = FUN_021d23b0(0,0x20,0xc,1,local_1c,0);
  *(undefined4 *)(*DAT_021cf1b0 + 0x10) = uVar4;
  uVar4 = FUN_021d19e0(0,local_1c[0],0);
  *(undefined4 *)(*DAT_021cf1b0 + 4) = uVar4;
  uVar4 = FUN_021bf4dc();
  FUN_021d2070(*(undefined4 *)(*DAT_021cf1b0 + 0x10),0,0,*(undefined2 *)(DAT_021cf1cc + param_2 * 4)
               ,*(undefined2 *)(DAT_021cf1c8 + param_2 * 4),2,uVar4,uVar2);
  FUN_021d1ffc(*(undefined4 *)(*DAT_021cf1b0 + 0x10),DAT_021cf1bc,0,
               *(undefined4 *)(*DAT_021cf1b0 + 4),0);
  FUN_021d254c(0,0,0x1f,0);
  FUN_021d254c(0,1,0x1f,local_24[*(byte *)(*DAT_021cf1b0 + 0x1c)]);
  FUN_021d254c(0,3,0x1f,1);
  FUN_021d2658(0,1,DAT_021cf1d0);
  FUN_021cec50(0xc0);
  *DAT_021cf1d4 = *DAT_021cf1d4 & DAT_021cf1d8 | DAT_021cf1dc;
  if (param_3 != 0) {
    uVar2 = FUN_021d3544(1,DAT_021cf1e0,0,0x78);
    *(undefined4 *)(*DAT_021cf1b0 + 0x14) = uVar2;
    return;
  }
  uVar2 = FUN_021d3544(1,DAT_021cf1e4,0,0x78);
  *(undefined4 *)(*DAT_021cf1b0 + 0x14) = uVar2;
  return;
}

