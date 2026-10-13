/* Decompiled C draft; module arm9; ROM address 0206938c. No matching claim. */
#include "types.h"
#include "deps/0206938c_StructMQRacerEntry_SomeFn_79.h"

void StructMQRacerEntry_SomeFn_79(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  undefined4 auStack_28 [4];
  
  iVar7 = param_1 + iRam020695b8;
  *(short *)(iVar7 + 0x1e) = *(short *)(iVar7 + 0x1e) + 1;
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if ((((((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x400) == 0) &&
       (iVar3 = StructMQSub2_SomeFn(iVar7 + 0x2c), iVar3 != 0)) &&
      (uVar4 = param_1 + 0x4cU & 3, uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
      ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x10000000) != 0)) &&
     ((uVar4 = param_1 + iRam020695b8 + 0x24, uVar2 = uVar4 & 3,
      uVar4 = *(uint *)(uVar4 & 0xfffffffc),
      uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0 &&
      (*(undefined4 *)(param_1 + iRam020695b8 + 0x24) = 1, uVar4 = param_1 + 0x7cU & 3,
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
      ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) != 0)))) {
    uVar4 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar6 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    uVar4 = uVar6 + 0x2c;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) ^ 0x200000;
  }
  uVar4 = param_1 + 0x590U & 3;
  uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  Animation_UpdateImpl((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x98);
  iVar3 = iRam020695c0;
  uVar4 = iVar7 + 0x24U & 3;
  uVar2 = *(uint *)(iVar7 + 0x24U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = param_1 + 0x4c8U & 3;
    uVar2 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
    *(uint *)(param_1 + 0x4c8) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 0x52;
    uVar4 = param_1 + 0x4c8U & 3;
    uVar2 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
    if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < 0x1001) {
      uVar4 = param_1 + 0x4cU & 3;
      uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xefffffff;
      func_0210515c(*(undefined2 *)(param_1 + 0x74));
      uVar4 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 1) != 0) {
        func_02074854();
      }
      *(undefined4 *)(param_1 + 0x4c8) = 0x1000;
      *(undefined4 *)(param_1 + 0x3dc) = 0xffffffff;
      iVar7 = 0;
      *(undefined4 *)(param_1 + 0x29c) = 0;
      uVar4 = param_1 + 0x590U & 3;
      uVar2 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x58;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) {
        auStack_28[0] = *puRam020695bc;
        auStack_28[1] = puRam020695bc[1];
        auStack_28[2] = puRam020695bc[2];
        do {
          uVar5 = func_0208b7bc(auStack_28[iVar7],param_1 + 0x80);
          func_02081f10(uVar5,*(undefined2 *)(param_1 + 0x74),0x14);
          iVar7 = iVar7 + 1;
        } while (iVar7 < 3);
      }
      func_020815dc(*(undefined2 *)(param_1 + 0x74));
      DriverContext_MaybeQueuePlaySfx(param_1,0xfd,0x7f,0);
      return;
    }
    return;
  }
  uVar4 = param_1 + 0x4c8U & 3;
  uVar2 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
  *(uint *)(param_1 + 0x4c8) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x52;
  uVar4 = param_1 + 0x4c8U & 3;
  uVar2 = *(uint *)(param_1 + 0x4c8U & 0xfffffffc);
  if (iVar3 < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    *(int *)(param_1 + 0x4c8) = iVar3;
  }
  uVar4 = iVar7 + 0x24U & 3;
  uVar2 = *(uint *)(iVar7 + 0x24U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    return;
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  bVar1 = false;
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x400) == 0) {
    iVar3 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74));
    bVar8 = iVar3 == 1;
    if ((!bVar8) &&
       (iVar3 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74)), iVar3 <= *(short *)(iVar7 + 0x28)))
    {
      bVar8 = true;
    }
    if ((0xb4 < *(short *)(iVar7 + 0x1e)) && (bVar8)) {
      bVar1 = true;
    }
  }
  if ((*(short *)(iVar7 + 0x1e) < 0x1e1) && (!bVar1)) {
    return;
  }
  *(undefined4 *)(iVar7 + 0x24) = 1;
  uVar4 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) != 0) {
    uVar4 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar6 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    uVar4 = uVar6 + 0x2c;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) ^ 0x200000;
  }
  return;
}

