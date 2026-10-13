/* Decompiled C draft; module arm9; ROM address 020427d4. No matching claim. */
#include "types.h"
#include "deps/020427d4_func_020427d4.h"

void func_020427d4(longlong *param_1)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  uint extraout_r1;
  uint uVar4;
  int extraout_r1_00;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  int local_30;
  uint local_28;
  int local_20;
  
  sVar1 = *(short *)(*piRam02042890 + 0x28);
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  do {
    uVar4 = local_28;
    if (sVar1 != 0) {
      lVar7 = Multiply64((int)param_1[1],*(undefined4 *)((int)param_1 + 0xc),(int)*param_1,
                         *(undefined4 *)((int)param_1 + 4));
      *param_1 = lVar7 + param_1[2];
      if (sVar1 == 0) {
        uVar4 = *(uint *)((int)param_1 + 4);
      }
      else {
        Multiply64(*(undefined4 *)((int)param_1 + 4),0,sVar1,0);
        uVar4 = extraout_r1;
      }
    }
    iVar6 = local_20;
    if (sVar1 != 0) {
      lVar7 = Multiply64((int)param_1[1],*(undefined4 *)((int)param_1 + 0xc),(int)*param_1,
                         *(undefined4 *)((int)param_1 + 4));
      *param_1 = lVar7 + param_1[2];
      if (sVar1 == 0) {
        iVar6 = *(int *)((int)param_1 + 4);
      }
      else {
        Multiply64(*(undefined4 *)((int)param_1 + 4),0,sVar1,0);
        iVar6 = extraout_r1_00;
      }
    }
    iVar3 = *(int *)(*piRam02042890 + 0xf8);
    uVar5 = (uint)(iVar6 << 0x10) >> 0xf;
    uVar2 = *(undefined2 *)(iVar3 + uVar5);
    iVar6 = (uVar4 & 0xffff) * 2;
    *(undefined2 *)(iVar3 + uVar5) = *(undefined2 *)(iVar3 + iVar6);
    *(undefined2 *)(*(int *)(*piRam02042890 + 0xf8) + iVar6) = uVar2;
    local_30 = local_30 + 1;
  } while (local_30 < 100);
  return;
}

