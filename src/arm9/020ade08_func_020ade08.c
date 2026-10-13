/* Decompiled C draft; module arm9; ROM address 020ade08. No matching claim. */
#include "types.h"
#include "deps/020ade08_func_020ade08.h"

void func_020ade08(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  code *param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int extraout_r1;
  int extraout_r1_00;
  uint extraout_r1_01;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar7 = 0;
  local_1c = 0;
  local_20 = 0;
  do {
    iVar2 = _s32_div_f(iVar7,8);
    _s32_div_f(iVar7,8);
    iVar8 = local_20;
    do {
      iVar3 = _s32_div_f(iVar8,2);
      _s32_div_f(iVar8,2);
      uVar1 = *(ushort *)(param_1 + (iVar8 + iVar7 * 0x10) * 2);
      iVar3 = iVar3 + iVar2 * 8;
      iVar4 = extraout_r1 * 8 + extraout_r1_00 * 4;
      uVar6 = local_1c;
      do {
        _s32_div_f((int)(uint)uVar1 >> ((uVar6 & 0x3f) << 2),0x10);
        uVar5 = extraout_r1_01 & 0xff;
        if (uVar5 != 0) {
          if (uVar5 == 1) {
            (*param_5)(param_2,uVar6 + iVar4,iVar3,param_3);
          }
          else if (uVar5 == 2) {
            (*param_5)(param_2,uVar6 + iVar4,iVar3,param_4);
          }
        }
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 4);
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x10);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  return;
}

