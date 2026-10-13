/* Decompiled C draft; module arm9; ROM address 020f9334. No matching claim. */
#include "types.h"
#include "deps/020f9334_func_020f9334.h"

void func_020f9334(int param_1,uint param_2,uint *param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  
  local_20 = 0;
  uVar2 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar7 = param_1 + 0xdcU & 3;
  uVar5 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  uVar1 = param_2 + 8 & 3;
  uVar8 = *(uint *)(param_2 + 8 & 0xfffffffc);
  local_14 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  local_1c = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  local_18 = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) -
             (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  uVar2 = param_1 + 0xdcU & 3;
  uVar7 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  func_01ffdee4(&local_1c,param_2,0,(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) >> 1,0x24
                ,(int)*(short *)(param_1 + 0xda),0,0,0,&local_20,0,0,0,0);
  if (((local_20 & uRam020f9448) == 0) &&
     (uVar2 = param_1 + 0xfcU & 3, uVar7 = *(uint *)(param_1 + 0xfcU & 0xfffffffc),
     ((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) & 0x80000) == 0)) {
    param_3[2] = 0;
    uVar2 = (uint)(param_3 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
    *param_3 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
    uVar2 = (uint)(param_3 + 1) & 3;
    uVar7 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
    if ((int)uVar2 < 1) {
      uVar7 = -param_4;
      if (uVar2 != uVar7 && (int)(uVar2 + param_4) < 0 == SBORROW4(uVar2,uVar7)) {
        param_3[1] = uVar7;
      }
      return;
    }
    param_3[1] = 0;
    return;
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar7 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if ((uVar2 & 0x4000000) == 0) {
    *(uint *)(param_1 + 0x74) = uVar2 | 8;
    uVar3 = param_5[1];
    uVar4 = param_5[2];
    *(undefined4 *)(param_1 + 0xf0) = *param_5;
    *(undefined4 *)(param_1 + 0xf4) = uVar3;
    *(undefined4 *)(param_1 + 0xf8) = uVar4;
    return;
  }
  return;
}

