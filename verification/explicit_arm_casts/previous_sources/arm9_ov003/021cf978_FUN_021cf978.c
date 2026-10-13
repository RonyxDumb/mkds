/* Decompiled C draft; module arm9_ov003; ROM address 021cf978. No matching claim. */
#include "types.h"
#include "deps/021cf978_FUN_021cf978.h"

void FUN_021cf978(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  byte local_84;
  undefined1 local_83;
  undefined1 auStack_82 [20];
  undefined2 local_6e [7];
  undefined1 uStack_60;
  byte local_5f;
  undefined1 auStack_5c [20];
  ushort local_48;
  
  func_0x0200fddc(&uStack_60);
  local_84 = local_84 & 0xf0 | local_5f & 0xf;
  local_83 = (undefined1)local_48;
  func_0x0214d1fc(auStack_5c,auStack_82,(uint)local_48 << 1);
  local_84 = local_84 & 0xf;
  puVar3 = local_6e;
  local_6e[0] = 0;
  local_6e[1] = 0;
  local_6e[2] = 0;
  local_6e[3] = 0;
  local_6e[4] = 0;
  local_6e[5] = 0;
  local_6e[6] = 0;
  puVar4 = (undefined2 *)*DAT_021cfa1c;
  iVar5 = 7;
  puVar6 = puVar4;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *puVar6 = uVar1;
    iVar2 = DAT_021cfa24;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(int *)((int)puVar4 + DAT_021cfa24) = (int)puVar4 + DAT_021cfa20;
  iVar5 = func_0x02009ff4(*(undefined4 *)(*DAT_021cfa1c + iVar2),&local_84,param_1,param_2,2);
  if (iVar5 != 0) {
    func_0x0200fd1c();
  }
  func_0x02009f38(DAT_021cfa28,1);
  func_0x02007ea0(DAT_021cfa2c);
  FUN_021cf36c(1);
  return;
}

