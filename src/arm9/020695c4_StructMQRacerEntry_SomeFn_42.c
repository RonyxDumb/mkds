/* Decompiled C draft; module arm9; ROM address 020695c4. No matching claim. */
#include "types.h"
#include "deps/020695c4_StructMQRacerEntry_SomeFn_42.h"

void StructMQRacerEntry_SomeFn_42(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  short *psVar10;
  undefined2 *puVar11;
  short asStack_38 [8];
  undefined4 local_28 [4];
  undefined2 *puVar12;
  
  psVar10 = asStack_38;
  iVar9 = 4;
  puVar11 = puRam02069874;
  do {
    puVar12 = puVar11 + 1;
    uVar2 = *puVar11;
    puVar11 = puVar11 + 2;
    uVar3 = *puVar12;
    iVar9 = iVar9 + -1;
    puVar12 = psVar10 + 1;
    *psVar10 = uVar2;
    psVar10 = psVar10 + 2;
    *puVar12 = uVar3;
  } while (iVar9 != 0);
  iVar9 = param_1 + iRam02069878;
  *(undefined2 *)(iVar9 + 0x1e) = 0;
  *(undefined2 *)(iVar9 + 0x20) = 0;
  *(undefined4 *)(iVar9 + 0x24) = 0;
  func_0209086c(iVar9 + 0x2c,*(undefined2 *)(param_1 + 0x74));
  uVar8 = uRam0206987c;
  uVar5 = param_1 + 0x4cU & 3;
  uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20 | 0x10000000;
  uVar5 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  bVar1 = *(byte *)((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0x3d0);
  sVar4 = GetDriverPlace(*(undefined2 *)(param_1 + 0x74));
  *(short *)(iVar9 + 0x28) = sVar4 - asStack_38[bVar1 - 1];
  if (*(short *)(iVar9 + 0x28) < 1) {
    *(undefined2 *)(iVar9 + 0x28) = 1;
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  *(undefined4 *)((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0xa4) = 0;
  uVar5 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x2000) != 0) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffffdfff;
    uVar5 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffff3fff;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    uVar5 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 1) == 0) {
      func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      func_0208c4e8();
    }
    else {
      DriverContext_MaybeQueuePlaySfx(param_1,0xf9,0x7f);
    }
    uVar5 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    func_0210fa40(0,((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 1) != 0);
  }
  uVar5 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x8000000) != 0) {
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & uRam02069880;
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_36(param_1);
    }
    uVar5 = param_1 + 0x590U & 3;
    uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    CharacterKartContext_SomeFn_1_1(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
  }
  func_021035ac(*(undefined2 *)(param_1 + 0x74));
  uVar5 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x40) != 0) {
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffffffbf;
    func_0207b1a8(param_1);
    *(undefined4 *)(param_1 + 0x29c) = 0;
    func_020817b8(*(undefined2 *)(param_1 + 0x74));
    DriverContext_UpdateCharacterAnimation(param_1,0,1);
    uVar5 = param_1 + 0x7cU & 3;
    uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 1) != 0) &&
       (uVar5 = (*(uint *)(uRam0206987c & 0xfffffffc) >> (uRam0206987c & 3) * 8 |
                *(uint *)(uRam0206987c & 0xfffffffc) << (uRam0206987c & 3) * -8 + 0x20) + 0xc,
       uVar8 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
       uVar5 >> uVar8 * 8 == 0 && uVar5 << uVar8 * -8 + 0x20 == 0)) {
      func_02106dc8();
    }
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_36(param_1);
    }
  }
  *(undefined4 *)(param_1 + 0x29c) = 3;
  uVar5 = param_1 + 0x4cU & 3;
  uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x2000) != 0) {
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0xffffdfff;
    *(undefined4 *)(param_1 + 0xd8) = 0x1000;
    uVar5 = param_1 + 0x4cU & 3;
    uVar8 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x8000000) == 0) {
      StructMQRacerEntry_SomeFn_2(param_1);
    }
    StructMQRacerEntry_SomeFn_3(param_1);
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar8 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0x58;
  uVar8 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar8 * 8 == 0 && uVar5 << uVar8 * -8 + 0x20 == 0) {
    local_28[0] = *puRam02069884;
    local_28[1] = puRam02069884[1];
    local_28[2] = puRam02069884[2];
    iVar9 = 0;
    do {
      uVar6 = func_0208b7bc(local_28[iVar9],param_1 + 0x80);
      func_02081f10(uVar6,*(undefined2 *)(param_1 + 0x74),0x14);
      iVar9 = iVar9 + 1;
    } while (iVar9 < 3);
  }
  func_02081724(*(undefined2 *)(param_1 + 0x74));
  StructMQRacerEntry_SomeFn_60(param_1);
  uVar5 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 0x200) != 0) {
    uVar5 = param_1 + 0x514U & 3;
    uVar8 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar7 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
    uVar5 = uVar7 + 0x2c;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar7 + 0x2c) = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) ^ 0x100000;
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar8 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) & 1) != 0) {
    func_02074874(uRam02069888);
    return;
  }
  return;
}

