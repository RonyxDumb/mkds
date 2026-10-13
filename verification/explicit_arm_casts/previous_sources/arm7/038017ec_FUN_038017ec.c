/* Decompiled C draft; module arm7; ROM address 038017ec. No matching claim. */
#include "types.h"
#include "deps/038017ec_FUN_038017ec.h"

void FUN_038017ec(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 extraout_r1;
  uint uVar6;
  uint uVar8;
  undefined2 local_2c [2];
  undefined2 local_28;
  undefined2 local_26;
  uint uVar7;
  
  uVar3 = DAT_03801a18;
  iVar2 = DAT_03801a14;
  iVar1 = DAT_03801a10;
  iVar4 = DAT_03801a04;
  uVar7 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 < 3) {
    if (uVar7 != 0) {
      if (uVar7 == 1) {
        uVar7 = DAT_03801a04 + 0x20U & 3;
        uVar6 = *(uint *)(DAT_03801a04 + 0x20U & 0xfffffffc);
        if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 1) {
          for (uVar7 = 0; uVar6 = param_1 + 8U & 3, uVar8 = *(uint *)(param_1 + 8U & 0xfffffffc),
              uVar7 < (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20); uVar7 = uVar7 + 1) {
            iVar5 = FUN_03806d38(uVar7 * iVar1);
            uVar6 = param_1 + 0xcU & 3;
            uVar8 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
            FUN_03806d38((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + iVar5,iVar1);
            iVar5 = iVar4 + uVar7 * 2;
            *(undefined2 *)(iVar5 + 0xcc) = extraout_r1;
            FUN_037fac9c(uVar7 * 0x28 + iVar2,(int)*(short *)(iVar5 + 0xcc),10,uVar3,uVar7);
          }
          uVar7 = param_1 + 4U & 3;
          uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
          FUN_0380146c((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffff,0);
          *(undefined4 *)(DAT_03801a04 + 0x20) = 2;
          return;
        }
        FUN_0380146c(1,3);
        return;
      }
      if (uVar7 != 2) {
        return;
      }
      uVar7 = DAT_03801a04 + 0x20U & 3;
      uVar6 = *(uint *)(DAT_03801a04 + 0x20U & 0xfffffffc);
      if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 3) {
        FUN_037fab44(DAT_03801a1c);
        uVar7 = param_1 + 4U & 3;
        uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffff,0);
        *(undefined4 *)(DAT_03801a04 + 0x20) = 0;
        return;
      }
      FUN_0380146c(2,3);
      return;
    }
  }
  else {
    if (uVar7 != 0x10) {
      return;
    }
    uVar7 = DAT_03801a04 + 0x20U & 3;
    uVar6 = *(uint *)(DAT_03801a04 + 0x20U & 0xfffffffc);
    if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) != 2) {
      return;
    }
  }
  uVar3 = FUN_037faf70();
  iVar4 = FUN_03801450(0);
  if (iVar4 == 0) {
    FUN_037faf84(uVar3);
    uVar7 = param_1 + 4U & 3;
    uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
    FUN_0380146c((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffff,4);
  }
  else {
    FUN_03801438(0);
    FUN_037faf84(uVar3);
    uVar7 = DAT_03801a04 + 0x24U & 3;
    uVar6 = *(uint *)(DAT_03801a04 + 0x24U & 0xfffffffc);
    FUN_03801de4(&local_28,uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,local_2c);
    FUN_03801a20(&local_28,local_2c[0]);
    *DAT_03801a08 = local_28;
    *DAT_03801a0c = local_26;
    uVar7 = param_1 + 4U & 3;
    uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    if (uVar7 == 0) {
      FUN_0380146c(0,0);
    }
    else {
      uVar6 = param_1 + 8U & 3;
      uVar8 = *(uint *)(param_1 + 8U & 0xfffffffc);
      FUN_0380146c(uVar7 & 0xffff,(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) & 0xff);
    }
    FUN_038013f4(0);
  }
  return;
}

