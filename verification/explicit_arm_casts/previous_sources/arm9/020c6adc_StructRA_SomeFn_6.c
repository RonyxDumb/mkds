/* Decompiled C draft; module arm9; ROM address 020c6adc. No matching claim. */
#include "types.h"
#include "deps/020c6adc_StructRA_SomeFn_6.h"

void StructRA_SomeFn_6(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  uint uVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  local_54 = *piRam020c6f10;
  local_50 = piRam020c6f10[1];
  local_4c = piRam020c6f10[2];
  local_48 = piRam020c6f10[3];
  local_44 = piRam020c6f10[4];
  local_40 = piRam020c6f10[5];
  local_3c = piRam020c6f10[6];
  local_38 = piRam020c6f10[7];
  uVar1 = (uint)(piRam020c6f10 + 8) & 3;
  uVar4 = *(uint *)((uint)(piRam020c6f10 + 8) & 0xfffffffc);
  local_34 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  func_020ae7c4(*(undefined1 *)(param_4 + 1),*(undefined1 *)((int)param_4 + 3),*param_4,&local_30);
  if (*(char *)(param_4 + 0xc) == '\0') {
    local_18 = 0xb;
    local_1c = 0xb;
    local_20 = 0xb;
    local_24 = 0xb;
    local_28 = 0xb;
    local_2c = 0xb;
    local_30 = 0xb;
  }
  if (local_30 != 0) {
    uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_30 + 0xe);
    local_98 = param_3 << 0xc;
    local_9c = (param_2 + local_54) * 0x1000;
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_9c,0,1);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  }
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_2c + 0xe);
  param_3 = param_3 << 0xc;
  local_94 = (param_2 + local_50) * 0x1000;
  local_90 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_94,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(0x18);
  local_8c = (param_2 + local_4c) * 0x1000;
  local_88 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_8c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_28 + 0xe);
  local_84 = (param_2 + local_48) * 0x1000;
  local_80 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_84,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_24 + 0xe);
  local_7c = (param_2 + local_44) * 0x1000;
  local_78 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_7c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(0x18);
  local_74 = (param_2 + local_40) * 0x1000;
  local_70 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_74,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_20 + 0xe);
  local_6c = (param_2 + local_3c) * 0x1000;
  local_68 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_6c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_1c + 0xe);
  local_64 = (param_2 + local_38) * 0x1000;
  local_60 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_64,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  uVar3 = GetB3C4_Cell_RaceNewRecordTaS(local_18 + 0xe);
  local_5c = (param_2 + local_34) * 0x1000;
  local_58 = param_3;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar3,0,&local_5c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

