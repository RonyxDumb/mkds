/* Decompiled C draft; module arm9; ROM address 020aa0ec. No matching claim. */
#include "types.h"
#include "deps/020aa0ec_func_020aa0ec.h"

byte * func_020aa0ec(ushort param_1,byte *param_2)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  if (*(int *)(iRam020aa2ec + 0x4c) != 0) {
    uVar1 = func_020ab2a4(param_2);
    iVar2 = (**(code **)(iRam020aa2ec + 0x4c))(uVar1,param_1);
    if ((iVar2 != 0) && (pbVar3 = (byte *)func_020ab338(), pbVar3 != (byte *)0x0)) {
      return pbVar3;
    }
  }
  if (*(ushort *)(param_2 + 6) < 0x100) {
    local_2c = *piRam020aa2f0;
    local_28 = *piRam020aa2f4;
  }
  else {
    local_2c = 0;
    local_28 = 0;
  }
  if ((param_1 & 0x40) == 0) {
    if ((param_1 & 0x80) == 0) {
      if ((param_1 & 0x20) == 0) {
        if ((param_1 & 0x10) != 0) {
          local_34 = 8;
          local_30 = 8;
          local_44 = local_2c + (uint)*param_2 + (uint)param_2[2];
          local_40 = local_44 + iRam020aa2f8;
          iVar2 = _s32_div_f((uint)param_2[1] * 2 + (uint)param_2[3],2);
          local_3c = local_28 + iVar2;
          local_38 = local_3c + 0x10;
        }
      }
      else {
        local_34 = -8;
        local_30 = 8;
        local_44 = local_2c + (uint)*param_2;
        local_40 = local_44 - iRam020aa2f8;
        iVar2 = _s32_div_f((uint)param_2[1] * 2 + (uint)param_2[3],2);
        local_3c = local_28 + iVar2;
        local_38 = local_3c + 0x10;
      }
    }
    else {
      local_34 = 8;
      local_30 = 8;
      iVar2 = _s32_div_f((uint)*param_2 * 2 + (uint)param_2[2],2);
      local_44 = local_2c + iVar2;
      local_40 = local_44 + 0x10;
      local_3c = local_28 + (uint)param_2[1] + (uint)param_2[3];
      local_38 = local_3c + iRam020aa2f8;
    }
  }
  else {
    local_34 = -8;
    local_30 = -8;
    iVar2 = _s32_div_f((uint)*param_2 * 2 + (uint)param_2[2],2);
    local_44 = local_2c + iVar2;
    local_40 = local_44 + -0x10;
    local_3c = local_28 + (uint)param_2[1];
    local_38 = local_3c - iRam020aa2f8;
  }
  do {
    if (local_3c == local_38) {
      return param_2;
    }
    if (local_44 != local_40) {
      iVar2 = local_44;
      do {
        puVar5 = *(ushort **)(*(int *)(iRam020aa2ec + 0x2c) + 4);
        iVar4 = (uint)puVar5[1] * 8;
        iVar8 = (uint)*puVar5 * 8;
        iVar6 = iVar2 - local_2c;
        iVar7 = *piRam020aa2fc;
        if (iVar6 + iVar7 < 0 == SBORROW4(iVar6,-iVar7)) {
          iVar9 = iVar2;
          if (iVar4 + iVar7 < iVar6) {
            iVar9 = iVar2 - (iVar4 + iVar7 * 2);
          }
        }
        else {
          iVar9 = iVar2 + iVar4 + iVar7 * 2;
        }
        if (local_3c - local_28 < -iVar7) {
          iVar4 = local_3c + iVar8 + iVar7 * 2;
        }
        else {
          iVar4 = local_3c;
          if (iVar8 + iVar7 < local_3c - local_28) {
            iVar4 = local_3c - (iVar8 + iVar7 * 2);
          }
        }
        pbVar3 = (byte *)func_020aaea0(iRam020aa2ec,iVar9,iVar4);
        if ((pbVar3 != (byte *)0x0) && (pbVar3 != param_2)) {
          return pbVar3;
        }
        iVar2 = iVar2 + local_34;
      } while (iVar2 != local_40);
    }
    local_3c = local_3c + local_30;
  } while( true );
}

