/* Decompiled C draft; module arm9; ROM address 020c2304. No matching claim. */
#include "types.h"
#include "deps/020c2304_func_020c2304.h"

void func_020c2304(int param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  iVar5 = -(param_2 >> 0x1f);
  iVar6 = iVar5 + (int)((longlong)iRam020c2564 * (longlong)param_2 >> 0x25);
  iVar7 = iVar5 + (int)((longlong)iRam020c2560 * (longlong)param_2 >> 0x22);
  iVar6 = iVar6 - iRam020c256c *
                  ((int)((longlong)iRam020c2560 * (longlong)iVar6 >> 0x22) - (iVar6 >> 0x1f));
  iVar7 = iVar7 - iRam020c256c *
                  ((int)((longlong)iRam020c2560 * (longlong)iVar7 >> 0x22) - (iVar7 >> 0x1f));
  lVar1 = (longlong)iRam020c256c *
          (longlong)(iVar5 + (int)((longlong)iRam020c2560 * (longlong)param_2 >> 0x22));
  iVar4 = (int)lVar1;
  iVar5 = iVar5 + (int)((longlong)iRam020c2568 * (longlong)param_2 >> 0x26);
  if (iVar5 == 0) {
    if (iVar6 == 0) goto LAB_020c2474;
  }
  else {
    uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar5 + 0x12,param_2,iVar4,(int)((ulonglong)lVar1 >> 0x20));
    local_44 = param_3 << 0xc;
    local_40 = param_4 << 0xc;
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(&local_44),0,1);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  }
  uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar6 + 0x12);
  local_3c = (param_3 + 0xf) * 0x1000;
  local_38 = param_4 << 0xc;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(&local_3c),0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
LAB_020c2474:
  if (((iVar5 != 0) || (iVar6 != 0)) || (iVar7 != 0)) {
    uVar3 = GetB3C4_Cell_RaceGoalTeamS(iVar7 + 0x12);
    local_34 = (param_3 + 0x1e) * 0x1000;
    local_30 = param_4 << 0xc;
    sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(&local_34),0,1);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  }
  uVar3 = GetB3C4_Cell_RaceGoalTeamS((param_2 - iVar4) + 0x12);
  local_2c = (param_3 + 0x2d) * 0x1000;
  local_28 = param_4 << 0xc;
  sVar2 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,(ushort *)(uintptr_t)(uVar3),0,(uint)(uintptr_t)(&local_2c),0,1);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar2;
  return;
}

