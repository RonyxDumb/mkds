/* Decompiled C draft; module arm9; ROM address 02114504. No matching claim. */
#include "types.h"
#include "deps/02114504_func_02114504.h"

void func_02114504(uint param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_28;
  undefined4 local_20;
  
  local_28 = 0;
  param_2 = param_1 + param_2;
  iVar2 = param_2 + -1;
  if ((int)param_1 < iVar2) {
    local_20 = 0;
    uVar5 = local_20;
    uVar7 = param_1;
    do {
      for (; (int)param_1 < param_2; param_1 = param_1 + 1) {
        uVar3 = func_02114584(param_1 & 0xffff);
        if (uVar5 < uVar3) {
          local_28 = param_1 & 0xffff;
          uVar5 = uVar3;
        }
      }
      if ((int)uVar7 < (int)local_28) {
        iVar6 = local_28 << 1;
        uVar5 = local_28;
        do {
          puVar4 = (undefined2 *)(*(int *)(*piRam02114580 + 4) + iVar6 + -2);
          uVar1 = *puVar4;
          *puVar4 = *(undefined2 *)(*(int *)(*piRam02114580 + 4) + iVar6);
          *(undefined2 *)(*(int *)(*piRam02114580 + 4) + iVar6) = uVar1;
          iVar6 = iVar6 + -2;
          uVar5 = uVar5 - 1;
        } while ((int)uVar7 < (int)uVar5);
      }
      param_1 = uVar7 + 1;
      uVar5 = local_20;
      uVar7 = param_1;
    } while ((int)param_1 < iVar2);
  }
  return;
}

