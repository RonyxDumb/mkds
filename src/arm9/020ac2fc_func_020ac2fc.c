/* Decompiled C draft; module arm9; ROM address 020ac2fc. No matching claim. */
#include "types.h"
#include "deps/020ac2fc_func_020ac2fc.h"

void func_020ac2fc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_24;
  
  iVar1 = _s32_div_f(param_3,2);
  local_24 = 0;
  if (0 < param_3) {
    iVar7 = 0;
    iVar2 = _s32_div_f(param_3,8);
    do {
      iVar6 = 0;
      if (0 < iVar1) {
        uVar5 = 0;
        iVar3 = _s32_div_f(local_24,8);
        do {
          iVar4 = _s32_div_f(uVar5,8);
          iVar4 = _s32_div_f((local_24 & 7) * 8 + (uVar5 & 7) + iVar4 * 0x40 + iVar3 * 0x40 * iVar2,
                             2);
          *(undefined1 *)(param_2 + iVar4) = *(undefined1 *)(param_1 + iVar6 + iVar7);
          uVar5 = uVar5 + 2;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1);
      }
      iVar7 = iVar7 + iVar1;
      local_24 = local_24 + 1;
    } while ((int)local_24 < param_3);
  }
  return;
}

