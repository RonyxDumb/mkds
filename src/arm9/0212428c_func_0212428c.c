/* Decompiled C draft; module arm9; ROM address 0212428c. No matching claim. */
#include "types.h"
#include "deps/0212428c_func_0212428c.h"

void func_0212428c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  int param_6,undefined4 param_7,char param_8)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int local_20;
  int local_1c;
  
  puVar1 = (ushort *)func_0201ea58(param_3);
  iVar8 = *(int *)(param_6 + (uint)*(ushort *)(param_5 + 6) * 0x40 + param_2 * 0x40 + 0x3c);
  iVar2 = *(int *)(iVar8 + 0x3c);
  iVar10 = *(int *)(iVar8 + 0x40);
  iVar3 = ((iVar2 + -1 >> 3) + 1) * 8;
  iVar4 = ((iVar10 + -1 >> 3) + 1) * 8;
  local_20 = 0;
  local_1c = 0;
  uVar5 = ((uint)*puVar1 << 0x12) >> 0x1e;
  uVar6 = uRam0212439c;
  if (uVar5 != 0) {
    if (uVar5 == 1) {
      local_20 = iVar3 - iVar2 >> 1;
      uVar6 = uRam021243a0;
    }
    else {
      uVar6 = 0;
      if (uVar5 == 2) {
        local_20 = iVar3 - iVar2;
        uVar6 = uRam021243a4;
      }
    }
  }
  uVar5 = ((uint)puVar1[1] << 0x12) >> 0x1e;
  if (uVar5 == 0) {
    uVar6 = uVar6 | 0x40;
  }
  else if (uVar5 == 1) {
    uVar6 = uVar6 | 0x80;
    local_1c = iVar4 - iVar10 >> 1;
  }
  else if (uVar5 == 2) {
    uVar6 = uVar6 | uRam021243a8;
    local_1c = iVar4 - iVar10;
  }
  (**(code **)(iVar8 + 0x18))(iVar8,0);
  G2d_Text_SomeFn_5_from_thumb
            (iVar8 + 0x20,local_20,local_1c,iVar2,iVar10,(char)puVar1[3],uVar6,
             ((uint)*puVar1 << 0x10) >> 0x1e,param_4,param_7,(int)param_8);
  uVar7 = *(undefined4 *)(iVar8 + 0x30);
  iVar2 = *(int *)(iVar8 + 0x38) * 0x20;
  uVar9 = *(undefined4 *)(iVar8 + 0x34);
  Arm_FlushRange(uVar7,uVar9);
  if (param_1 != 0) {
    AllocateReserveTEQSub(0x23,iVar2,uVar7,uVar9);
    return;
  }
  AllocateReserveTEQSub(0x13,iVar2,uVar7,uVar9);
  return;
}

