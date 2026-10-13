/* Decompiled C draft; module arm7; ROM address 0380405c. No matching claim. */
#include "types.h"
#include "deps/0380405c_FUN_0380405c.h"

void FUN_0380405c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = FUN_037faf70();
  iVar4 = FUN_03801450(1);
  if (iVar4 == 0) {
    FUN_037faf84(uVar3);
    uVar1 = param_1 + 4U & 3;
    uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
    FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,4);
  }
  else {
    FUN_03801438(1);
    FUN_037faf84(uVar3);
    uVar1 = param_1 + 4U & 3;
    uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
    switch(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) {
    case 0x20:
      FUN_03804d90();
      break;
    case 0x21:
      FUN_03804d50();
      break;
    case 0x22:
      uVar1 = param_1 + 0x10U & 3;
      uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804cdc(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      break;
    case 0x23:
      iVar4 = FUN_03804030();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar5 = param_1 + 0xcU & 3;
      uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar2 = param_1 + 0x10U & 3;
      uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804bbc(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
                   uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,
                   uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
      break;
    case 0x24:
      iVar4 = FUN_03804030();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar5 = param_1 + 0xcU & 3;
      uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar2 = param_1 + 0x10U & 3;
      uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804a80(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
                   uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,
                   uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
      break;
    case 0x25:
      iVar4 = FUN_03803ff8();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar5 = param_1 + 0xcU & 3;
      uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar2 = param_1 + 0x10U & 3;
      uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804954(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
                   (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 0xffff,
                   uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
      break;
    case 0x26:
      iVar4 = FUN_03803ff8();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar5 = param_1 + 0xcU & 3;
      uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar2 = param_1 + 0x10U & 3;
      uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804828(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
                   (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) & 0xffff,
                   uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
      break;
    case 0x27:
      iVar4 = FUN_03803ff8();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
      FUN_03804764(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      break;
    case 0x28:
      iVar4 = FUN_03803ff8();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      uVar1 = param_1 + 8U & 3;
      uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
      FUN_038046a0(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      break;
    case 0x29:
      FUN_03804660();
      break;
    case 0x2a:
      FUN_03804620();
      break;
    case 0x2b:
      iVar4 = FUN_03803ff8();
      if (iVar4 == 0) {
        uVar1 = param_1 + 4U & 3;
        uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
        FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,3);
        FUN_038013f4(1);
        return;
      }
      FUN_038045e0();
      break;
    case 0x2c:
      uVar1 = param_1 + 0x10U & 3;
      uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      FUN_03804544(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      break;
    case 0x2d:
      FUN_03804504();
      break;
    default:
      FUN_038013f4(1);
      uVar1 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,1);
      return;
    }
    uVar1 = param_1 + 4U & 3;
    uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
    FUN_0380146c((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xffff,0);
    FUN_038013f4(1);
  }
  return;
}

