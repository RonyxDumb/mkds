/* Decompiled C draft; module arm9; ROM address 02069aa0. No matching claim. */
#include "types.h"
#include "deps/02069aa0_StructMQRacerEntry_SomeFn_54.h"

void StructMQRacerEntry_SomeFn_54(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1 + iRam02069c2c;
  *(undefined2 *)(iVar7 + 0x10) = 0;
  uVar1 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & uRam02069c30) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0xffffffbf;
    func_0207b1a8();
    *(undefined4 *)(param_1 + 0x29c) = 0;
    func_020817b8(*(undefined2 *)(param_1 + 0x74));
    DriverContext_UpdateCharacterAnimation(param_1,0,1);
    uVar1 = param_1 + 0x7cU & 3;
    uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 1) != 0) &&
       (uVar1 = (*(uint *)(uRam02069c34 & 0xfffffffc) >> (uRam02069c34 & 3) * 8 |
                *(uint *)(uRam02069c34 & 0xfffffffc) << (uRam02069c34 & 3) * -8 + 0x20) + 0xc,
       uVar6 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
       uVar1 >> uVar6 * 8 == 0 && uVar1 << uVar6 * -8 + 0x20 == 0)) {
      func_02106dc8();
    }
    uVar1 = param_1 + 0x4cU & 3;
    uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_36(param_1);
    }
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 0x2000;
  *(undefined4 *)(param_1 + 0x29c) = 2;
  func_02103840(*(undefined2 *)(param_1 + 0x74));
  uVar1 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar1 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  if ((((uVar1 & 0x20000) == 0) && ((uVar1 & 0x8000000) != 0)) &&
     (*(short *)(param_1 + iRam02069c2c + 0x1c) < 0x191)) {
    *(undefined2 *)(param_1 + iRam02069c2c + 0x1c) = 400;
    uVar1 = param_1 + 0x4cU & 3;
    uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 0x20000;
    uVar2 = func_0207a134();
    uVar3 = func_0207a11c();
    uVar4 = func_0207a104();
    uVar1 = param_1 + 0x590U & 3;
    uVar6 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SomeFn_1_0
              (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,uVar2,uVar3,uVar4);
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  func_0210fa40(1,((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 1) != 0);
  uVar1 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 1) == 0) {
    *(undefined2 *)(iVar7 + 0x12) = 2;
    *(undefined2 *)(iVar7 + 0x14) = 0;
    *(undefined2 *)(iVar7 + 0x18) = 10;
    *(undefined2 *)(iVar7 + 0x16) = 0;
    *(undefined2 *)(iVar7 + 0x1a) = 1;
  }
  else {
    uVar1 = param_1 + 0x7cU & 3;
    uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20 | 0x4000;
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) & 0x200) != 0) {
    uVar1 = param_1 + 0x514U & 3;
    uVar6 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar5 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    uVar1 = uVar5 + 0x2c;
    uVar6 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar5 + 0x2c) = (uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) ^ 0x4000000;
  }
  return;
}

