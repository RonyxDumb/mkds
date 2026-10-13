/* Decompiled C draft; module arm9; ROM address 020fc79c. No matching claim. */
#include "types.h"
#include "deps/020fc79c_func_020fc79c.h"

undefined4 func_020fc79c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  
  func_020f9114(param_2);
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_020fcb9c(param_2,(short)*(char *)((*(uint *)(uRam020fc8e8 & 0xfffffffc) >>
                                            (uRam020fc8e8 & 3) * 8 |
                                           *(uint *)(uRam020fc8e8 & 0xfffffffc) <<
                                           (uRam020fc8e8 & 3) * -8 + 0x20) + 0x474));
    uVar2 = param_2 + 0x228U & 3;
    uVar5 = *(uint *)(param_2 + 0x228U & 0xfffffffc);
    uVar1 = param_2 + 0x74U & 3;
    uVar3 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x1fc;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x40000000) == 0) &&
       (uVar2 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x48, uVar1 = uVar2 & 3,
       uVar2 = *(uint *)(uVar2 & 0xfffffffc),
       ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) == 0)) {
      uVar4 = 3;
    }
    else {
      uVar4 = 2;
    }
    *(undefined2 *)(param_2 + 0x2f8) = uVar4;
    *(undefined2 *)(param_2 + 0x2fa) = 1;
    uVar2 = param_2 + 0x74U & 3;
    uVar1 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) != 0) {
      uVar2 = param_2 + 0x228U & 3;
      uVar1 = *(uint *)(param_2 + 0x228U & 0xfffffffc);
      func_020fe71c(5,*(undefined2 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_2 + 0x4e));
    }
  }
  else {
    func_020ed268(param_2,param_1,0x14,0xcc,1,1,0,0x6000,*(undefined2 *)(param_2 + 0x276),1);
    StateDualHandler_SetState(param_2 + 0x2e8,1);
  }
  func_020fc94c(param_2);
  uVar6 = *(undefined4 *)(param_1 + 0x30);
  uVar7 = *(undefined4 *)(param_1 + 0x34);
  uVar8 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0x98) = uVar6;
  *(undefined4 *)(param_2 + 0x9c) = uVar7;
  *(undefined4 *)(param_2 + 0xa0) = uVar8;
  uVar6 = *(undefined4 *)(param_1 + 0x40);
  uVar7 = *(undefined4 *)(param_1 + 0x44);
  uVar8 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0xa8) = uVar6;
  *(undefined4 *)(param_2 + 0xac) = uVar7;
  *(undefined4 *)(param_2 + 0xb0) = uVar8;
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_2 + 0xb4) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = param_2 + 0x74U & 3;
  uVar1 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000;
  bVar9 = uVar2 != 0;
  if (bVar9) {
    uVar2 = param_2 + 0x200;
    uVar6 = 0;
  }
  if (bVar9) {
    *(short *)(uVar2 + 0xf8) = (short)uVar6;
    *(undefined2 *)(uVar2 + 0xfa) = 1;
  }
  return 1;
}

