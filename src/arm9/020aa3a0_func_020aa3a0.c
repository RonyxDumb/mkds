/* Decompiled C draft; module arm9; ROM address 020aa3a0. No matching claim. */
#include "types.h"
#include "deps/020aa3a0_func_020aa3a0.h"

void func_020aa3a0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                  int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_34;
  int local_24;
  int local_20;
  
  if ((param_4 < param_6) && (param_5 < param_7)) {
    iVar1 = param_4 >> 3;
    iVar2 = (param_6 + -1 >> 3) + 1;
    iVar3 = (param_7 + -1 >> 3) + 1;
    local_34 = param_5 >> 3;
    if (local_34 < iVar3) {
      local_24 = local_34 << 3;
      local_20 = (param_2 >> 3) * local_34;
      do {
        if (iVar1 < iVar2) {
          iVar8 = iVar1 << 3;
          iVar9 = iVar1;
          do {
            iVar6 = param_4 - iVar8;
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            iVar7 = param_5 - local_24;
            if (param_5 - local_24 < 0) {
              iVar7 = 0;
            }
            iVar4 = param_6 - iVar8;
            if (8 < iVar4) {
              iVar4 = 8;
            }
            iVar5 = param_7 - local_24;
            if (8 < param_7 - local_24) {
              iVar5 = 8;
            }
            func_020aa4e8(param_1 + (iVar9 + local_20) * 0x20,param_3,iVar6,iVar7,iVar4,iVar5);
            iVar8 = iVar8 + 8;
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar2);
        }
        local_24 = local_24 + 8;
        local_20 = local_20 + (param_2 >> 3);
        local_34 = local_34 + 1;
      } while (local_34 < iVar3);
    }
  }
  return;
}

