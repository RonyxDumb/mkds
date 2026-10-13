/* Decompiled C draft; module arm9; ROM address 020b45b0. No matching claim. */
#include "types.h"
#include "deps/020b45b0_func_020b45b0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020b45b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_40;
  int iStack_3c;
  int iStack_38;
  
  local_40 = 0;
  if (param_4 < 1) {
    return;
  }
  do {
    iStack_3c = 0;
    if (0 < param_5) {
      do {
        iStack_38 = 0;
        iVar1 = 0;
        do {
          iVar2 = 0;
          iVar3 = (7 - iStack_38) * 2;
          do {
            *(undefined2 *)
             (iVar3 * 2 +
             param_6 + (param_7 + local_40) * 0x20 + (param_8 + (param_5 - iStack_3c) + -1) * 0x400)
                 = *(undefined2 *)
                    ((iVar2 + iVar1) * 2 +
                    param_1 + (param_2 + local_40) * 0x20 + (param_3 + iStack_3c) * 0x400);
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 2);
          iVar1 = iVar1 + 2;
          iStack_38 = iStack_38 + 1;
        } while (iStack_38 < 8);
        iStack_3c = iStack_3c + 1;
      } while (iStack_3c < param_5);
    }
    local_40 = local_40 + 1;
  } while (local_40 < param_4);
  return;
}

