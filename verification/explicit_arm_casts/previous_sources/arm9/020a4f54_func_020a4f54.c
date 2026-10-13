/* Decompiled C draft; module arm9; ROM address 020a4f54. No matching claim. */
#include "types.h"
#include "deps/020a4f54_func_020a4f54.h"

undefined4 func_020a4f54(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar2 = func_020a2378();
  iVar2 = iVar2 + param_1 * 0x38;
  iVar3 = func_020a2204(param_1);
  if (iVar3 == 0) {
    uVar5 = 0;
  }
  else {
    iVar3 = func_020a1154(param_1);
    uVar5 = iVar2 + iVar3 * 4 + 0x10;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  iVar3 = func_020a1154(param_1);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    iVar3 = func_020a1154(param_1);
    uVar6 = iVar2 + (iVar3 + -1) * 4 + 0x10;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  }
  iVar3 = func_020a1154(param_1);
  if ((iVar3 != 0) && (uVar6 != 0)) {
    iVar3 = func_020a2204(param_1);
    if ((iVar3 == 0) || (uVar5 == 0)) {
      MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
    }
    else {
      iVar3 = func_020a1154(param_1);
      *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar6;
      MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
      iVar3 = func_020a1154(param_1);
      *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar5;
    }
  }
  iVar2 = func_020a2378();
  iVar2 = iVar2 + param_2 * 0x38;
  iVar3 = func_020a2204(param_2);
  if (iVar3 == 0) {
    uVar5 = 0;
  }
  else {
    iVar3 = func_020a1154(param_2);
    uVar5 = iVar2 + iVar3 * 4 + 0x10;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  }
  iVar3 = func_020a1154(param_2);
  if (iVar3 == 0) {
    uVar7 = 0;
  }
  else {
    iVar3 = func_020a1154(param_2);
    uVar7 = iVar2 + (iVar3 + -1) * 4 + 0x10;
    uVar1 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  }
  iVar3 = func_020a1154(param_2);
  if ((iVar3 != 0) && (uVar7 != 0)) {
    iVar3 = func_020a2204(param_2);
    if ((iVar3 == 0) || (uVar5 == 0)) {
      MaybeUpdateDriverBalloonShineCount(param_2,0xffffffff);
    }
    else {
      iVar3 = func_020a1154(param_2);
      *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar7;
      MaybeUpdateDriverBalloonShineCount(param_2,0xffffffff);
      iVar3 = func_020a1154(param_2);
      *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar5;
    }
  }
  if (uVar6 != 0) {
    iVar2 = func_020a2378();
    iVar2 = iVar2 + param_2 * 0x38;
    iVar3 = func_020a1154(param_2);
    iVar4 = func_020a1154(param_2);
    uVar5 = iVar2 + iVar4 * 4 + 0x10;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(iVar2 + (iVar3 + 1) * 4 + 0x10) = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    iVar3 = func_020a1154(param_2);
    *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar6;
    MaybeUpdateDriverBalloonShineCount(param_2,1);
    func_020a2e68(uVar6);
    func_020a2e58(uVar6,param_2);
    uVar5 = func_020a1154(param_2);
    if ((1 < uVar5) && (iVar3 = func_020a2204(param_2), iVar3 != 0)) {
      *(undefined4 *)(iVar2 + 0x34) = 4;
    }
  }
  if (uVar7 != 0) {
    iVar2 = func_020a2378();
    iVar2 = iVar2 + param_1 * 0x38;
    iVar3 = func_020a1154(param_1);
    iVar4 = func_020a1154(param_1);
    uVar5 = iVar2 + iVar4 * 4 + 0x10;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(iVar2 + (iVar3 + 1) * 4 + 0x10) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    iVar3 = func_020a1154(param_1);
    *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar7;
    MaybeUpdateDriverBalloonShineCount(param_1,1);
    func_020a2e68(uVar7);
    func_020a2e58(uVar7,param_1);
    uVar5 = func_020a1154(param_1);
    if ((1 < uVar5) && (iVar3 = func_020a2204(param_1), iVar3 != 0)) {
      *(undefined4 *)(iVar2 + 0x34) = 4;
    }
  }
  iVar2 = (int)*(char *)((*(uint *)(uRam020a5260 & 0xfffffffc) >> (uRam020a5260 & 3) * 8 |
                         *(uint *)(uRam020a5260 & 0xfffffffc) << (uRam020a5260 & 3) * -8 + 0x20) +
                        0x62);
  if ((param_1 == iVar2) || (param_2 == iVar2)) {
    local_38 = uRam020a5264;
    local_34 = 0;
    local_30 = 2;
    local_2c = func_020d4ef4();
    func_0210b7a8(&local_38);
  }
  return 1;
}

