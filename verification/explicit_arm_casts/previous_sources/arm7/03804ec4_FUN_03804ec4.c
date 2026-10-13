/* Decompiled C draft; module arm7; ROM address 03804ec4. No matching claim. */
#include "types.h"
#include "deps/03804ec4_FUN_03804ec4.h"

void FUN_03804ec4(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  ushort local_10;
  ushort local_e;
  
  FUN_03805b8c(&local_10);
  FUN_03805b34(&local_e);
  if ((((int)((uint)local_10 << 0x18) < 0) || ((int)((uint)local_10 << 0x19) < 0)) ||
     ((int)((uint)local_e << 0x18) < 0)) {
    local_10 = local_10 & 0xfffe | 1;
    FUN_03805b60(&local_10);
  }
  if (((int)((uint)local_10 << 0x1b) < 0) || ((int)((uint)local_10 << 0x1a) < 0)) {
    local_e = local_e & 0xffb0;
    FUN_03805b08(&local_e);
  }
  FUN_03805e48(DAT_03804ff4);
  iVar2 = FUN_03804dd0((char)*DAT_03804ff4);
  uVar3 = FUN_03804dd0(((*(uint *)((uint)DAT_03804ff4 & 0xfffffffc) >> ((uint)DAT_03804ff4 & 3) * 8
                        | *(uint *)((uint)DAT_03804ff4 & 0xfffffffc) <<
                          ((uint)DAT_03804ff4 & 3) * -8 + 0x20) << 0x13) >> 0x1b);
  uVar4 = FUN_03804dd0(((*(uint *)((uint)DAT_03804ff4 & 0xfffffffc) >> ((uint)DAT_03804ff4 & 3) * 8
                        | *(uint *)((uint)DAT_03804ff4 & 0xfffffffc) <<
                          ((uint)DAT_03804ff4 & 3) * -8 + 0x20) << 10) >> 0x1a);
  uVar5 = FUN_03804e48(iVar2 + 2000,uVar3,uVar4);
  puVar1 = DAT_03804ff4;
  uVar6 = *(uint *)((uint)DAT_03804ff4 & 0xfffffffc) >> ((uint)DAT_03804ff4 & 3) * 8 |
          *(uint *)((uint)DAT_03804ff4 & 0xfffffffc) << ((uint)DAT_03804ff4 & 3) * -8 + 0x20;
  if ((uVar6 << 5) >> 0x1d != uVar5) {
    *DAT_03804ff4 = uVar6 & 0xf8ffffff | (uVar5 & 7) << 0x18;
    FUN_03805e1c(puVar1);
  }
  FUN_03805e74(1);
  return;
}

