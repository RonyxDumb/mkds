/* Decompiled C draft; module arm9; ROM address 020d029c. No matching claim. */
#include "types.h"
#include "deps/020d029c_func_020d029c.h"

void func_020d029c(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
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
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  
  local_44 = *piRam020d06b4;
  local_40 = piRam020d06b4[1];
  local_3c = piRam020d06b4[2];
  local_38 = piRam020d06b4[3];
  local_34 = piRam020d06b4[4];
  local_30 = piRam020d06b4[5];
  local_2c = piRam020d06b4[6];
  local_28 = piRam020d06b4[7];
  uVar3 = (uint)(piRam020d06b4 + 8) & 3;
  uVar2 = *(uint *)((uint)(piRam020d06b4 + 8) & 0xfffffffc);
  local_24 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
          *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
  if (uVar3 != 0) {
    uVar4 = GetB3C4_Cell_RaceGoalM(uVar3 + 0x17 + param_5);
    local_88 = param_3 << 0xc;
    local_8c = (param_2 + local_44) * 0x1000;
    sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_8c,0,1);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  }
  uVar3 = param_4 + 4 & 3;
  uVar2 = *(uint *)(param_4 + 4 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  param_3 = param_3 << 0xc;
  local_84 = (param_2 + local_40) * 0x1000;
  local_80 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_84,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar4 = GetB3C4_Cell_RaceGoalM(param_5 + 0x21);
  local_7c = (param_2 + local_3c) * 0x1000;
  local_78 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_7c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar3 = param_4 + 8 & 3;
  uVar2 = *(uint *)(param_4 + 8 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  local_74 = (param_2 + local_38) * 0x1000;
  local_70 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_74,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar3 = param_4 + 0xc & 3;
  uVar2 = *(uint *)(param_4 + 0xc & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  local_6c = (param_2 + local_34) * 0x1000;
  local_68 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_6c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar4 = GetB3C4_Cell_RaceGoalM(param_5 + 0x21);
  local_64 = (param_2 + local_30) * 0x1000;
  local_60 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_64,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar3 = param_4 + 0x10 & 3;
  uVar2 = *(uint *)(param_4 + 0x10 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  local_5c = (param_2 + local_2c) * 0x1000;
  local_58 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_5c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar3 = param_4 + 0x14 & 3;
  uVar2 = *(uint *)(param_4 + 0x14 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  local_54 = (param_2 + local_28) * 0x1000;
  local_50 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_54,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  uVar3 = param_4 + 0x18 & 3;
  uVar2 = *(uint *)(param_4 + 0x18 & 0xfffffffc);
  uVar4 = GetB3C4_Cell_RaceGoalM((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x17 + param_5)
  ;
  local_4c = (param_2 + local_24) * 0x1000;
  local_48 = param_3;
  sVar1 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar4,0,&local_4c,0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar1;
  return;
}

