/* Decompiled C draft; module arm9; ROM address 020d2c2c. No matching claim. */
#include "types.h"
#include "deps/020d2c2c_func_020d2c2c.h"

int func_020d2c2c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_5c;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_5c = 0;
  func_01ffd900(param_4,uRam020d2d80);
  iVar6 = 0;
  if (*psRam020d2d84 != 0) {
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    iVar5 = *piRam020d2d88 + iRam020d2d8c;
    if (0 < *psRam020d2d84) {
      iVar7 = 0;
      do {
        iVar4 = *(int *)(*piRam020d2d90 + iVar7);
        iVar1 = func_020d3e34(param_1,param_3,iVar4,&local_50);
        if (iVar1 != 0) {
          iVar1 = local_30;
          if (((*(ushort *)(iVar4 + 2) & 0x40) == 0) &&
             (iVar2 = func_020d6968(param_5,iVar4), iVar1 = local_30, iVar2 != 0)) {
            if (local_50 < local_44) {
              local_44 = local_50;
            }
            if (local_4c < local_40) {
              local_40 = local_4c;
            }
            if (local_48 < local_3c) {
              local_3c = local_48;
            }
            iVar1 = local_50;
            if (local_50 <= local_38) {
              iVar1 = local_38;
            }
            iVar2 = local_4c;
            if (local_4c <= local_34) {
              iVar2 = local_34;
            }
            local_38 = iVar1;
            local_34 = iVar2;
            iVar1 = local_48;
            if (local_48 <= local_30) {
              iVar1 = local_30;
            }
          }
          local_30 = iVar1;
          uVar3 = param_1[1];
          *(undefined4 *)(iVar5 + 0x50) = *param_1;
          *(undefined4 *)(iVar5 + 0x54) = uVar3;
          *(undefined4 *)(iVar5 + 0x58) = param_1[2];
          uVar3 = param_2[1];
          *(undefined4 *)(iVar5 + 0x5c) = *param_2;
          *(undefined4 *)(iVar5 + 0x60) = uVar3;
          *(undefined4 *)(iVar5 + 100) = param_2[2];
          *(undefined4 *)(iVar5 + 0x44) = param_5;
          iVar1 = func_020d6a54(iVar5,iVar4,0);
          if (local_5c < iVar1) {
            local_5c = iVar1;
          }
        }
        iVar7 = iVar7 + 4;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *psRam020d2d84);
    }
    if ((local_5c != 0) && (param_6 != (int *)0x0)) {
      *param_6 = local_38 + local_44;
      param_6[1] = local_34 + local_40;
      if (param_6[1] < 0) {
        param_6[1] = 0;
      }
      param_6[2] = local_30 + local_3c;
    }
  }
  return local_5c;
}

