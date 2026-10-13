/* Decompiled C draft; module arm9_ov000; ROM address 0219d14c. No matching claim. */
#include "types.h"
#include "deps/0219d14c_FUN_0219d14c.h"

int FUN_0219d14c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  local_24 = -1;
  iVar5 = param_1;
  local_1c = param_1;
  if (0 < param_2 + -1) {
    do {
      iVar1 = FUN_0219d630(local_20);
      if (iVar1 != 0) {
        if (iVar1 == param_3) {
          local_24 = local_20;
        }
        iVar4 = local_20 + 1;
        if (iVar4 < param_2) {
          iVar3 = param_1 + iVar4 * 0xc;
          do {
            iVar2 = FUN_0219d630(iVar4);
            if (iVar1 == iVar2) {
              iVar2 = func_0x02152a1c(local_1c);
              if ((iVar2 == 2) && (iVar2 = func_0x02152a1c(iVar3), iVar2 == 3)) {
                func_0x02152468(iVar5,iVar1);
              }
              iVar2 = func_0x02152a24(iVar3);
              if (iVar2 != 0) {
                func_0x021529bc(iVar5);
              }
              FUN_0219d288(param_1,iVar4,local_20);
              *(undefined1 *)(*DAT_0219d20c + 0x1d) = 1;
            }
            iVar3 = iVar3 + 0xc;
            iVar4 = iVar4 + 1;
          } while (iVar4 < param_2);
        }
      }
      local_1c = local_1c + 0xc;
      local_20 = local_20 + 1;
      iVar5 = iVar5 + 0xc;
    } while (local_20 < param_2 + -1);
  }
  return local_24;
}

