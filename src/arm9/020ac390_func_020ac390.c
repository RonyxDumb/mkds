/* Decompiled C draft; module arm9; ROM address 020ac390. No matching claim. */
#include "types.h"
#include "deps/020ac390_func_020ac390.h"

void func_020ac390(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_2c;
  undefined4 local_24;
  
  iVar1 = _s32_div_f(param_3,2);
  local_2c = 0;
  if (0 < param_3) {
    local_24 = 0;
    iVar2 = _s32_div_f(param_3,8);
    do {
      iVar8 = 0;
      if (0 < iVar1) {
        uVar7 = 1;
        uVar6 = 0;
        iVar3 = _s32_div_f(local_2c,8);
        iVar9 = iVar3 * 0x40 * iVar2;
        iVar3 = (local_2c & 7) * 8;
        do {
          iVar4 = _s32_div_f(uVar6,8);
          iVar5 = _s32_div_f(uVar7,8);
          *(byte *)(param_2 + iVar8 + local_24) =
               *(byte *)(param_1 + iVar3 + (uVar6 & 7) + iVar4 * 0x40 + iVar9) |
               *(char *)(param_1 + iVar3 + (uVar7 & 7) + iVar5 * 0x40 + iVar9) << 4;
          uVar7 = uVar7 + 2;
          uVar6 = uVar6 + 2;
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar1);
      }
      local_24 = local_24 + iVar1;
      local_2c = local_2c + 1;
    } while ((int)local_2c < param_3);
  }
  return;
}

