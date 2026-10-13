/* Decompiled C draft; module arm9; ROM address 02068640. No matching claim. */
#include "types.h"
#include "deps/02068640_StructMQRacerEntry_SomeFn_25.h"

void StructMQRacerEntry_SomeFn_25(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined1 auStack_30 [12];
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [4];
  int iStack_14;
  
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x100000) != 0) {
    return;
  }
  func_020fa9e4();
  uVar5 = uRam0206888c;
  if (param_2 != 0) {
    uVar3 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 0x2000000;
  }
  uVar3 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | uRam02068890;
  uVar3 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 8;
  uVar3 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20 | 0x2000;
  uVar3 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & uVar5;
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0x20) != 0) {
    func_02041bb0(auStack_30,auStack_18,*(undefined2 *)(param_1 + 0x74));
    *(short *)(param_1 + 0x236) = (short)((uint)(iStack_14 * 0xb6) >> 0xc);
    func_01ffd190(uRam02068894,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
    func_01ffcd84(param_1 + 0x120,param_1 + 0xe0);
    GetMQRacerVector333(param_1,auStack_24);
    StructMQRacerEntry_SomeFn_63(param_1,auStack_30,auStack_24,0);
    uVar5 = (*(uint *)(uRam02068898 & 0xfffffffc) >> (uRam02068898 & 3) * 8 |
            *(uint *)(uRam02068898 & 0xfffffffc) << (uRam02068898 & 3) * -8 + 0x20) + 8;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) == 5) {
      iVar6 = param_1 + 0x1d8;
    }
    else {
      iVar6 = param_1 + 0x1b8;
    }
    if (*(short *)(param_1 + 0x2c8) == -1) {
      uVar5 = param_1 + 0x2ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar2 = FindComputeSomeCollisionEntryId
                        (iVar6,(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0xd000,0x8000,
                         param_1);
      *(undefined2 *)(param_1 + 0x2c8) = uVar2;
    }
    if (*(short *)(param_1 + 0x2ca) == -1) {
      uVar5 = param_1 + 0x2ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar2 = FindComputeSomeCollisionEntryId
                        (param_1 + 0x1f0,(uVar5 << 0xf) >> 0xc | (uVar5 >> 0x11) << 0x14,0x800,
                         param_1);
      *(undefined2 *)(param_1 + 0x2ca) = uVar2;
    }
    puVar1 = puRam0206889c;
    uVar5 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20 | 0x80;
    uVar5 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xffffff9f;
    uVar7 = puVar1[1];
    uVar9 = puVar1[2];
    *(undefined4 *)(param_1 + 0xbc) = *puVar1;
    *(undefined4 *)(param_1 + 0xc0) = uVar7;
    *(undefined4 *)(param_1 + 0xc4) = uVar9;
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  puVar8 = (uint *)(param_1 + 0x7c);
  *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xffffff7f;
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 1) == 0) {
    *puVar8 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
              *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20 | 0x40;
  }
  else {
    func_02075eb8();
  }
  StructMQRacerEntry_SomeFn_14(param_1,0,param_2);
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if (((uVar5 & 1) != 0) &&
     ((uVar3 = (*(uint *)(uRam02068898 & 0xfffffffc) >> (uRam02068898 & 3) * 8 |
               *(uint *)(uRam02068898 & 0xfffffffc) << (uRam02068898 & 3) * -8 + 0x20) + 8,
      uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20, uVar3 == 2 || (uVar3 == 4)))) {
    uVar10 = (uVar5 & 0x10000) == 0;
    if (((bool)uVar10) && ((uVar5 & 0x20000) != 0)) {
      uVar10 = 2;
    }
    func_021112fc(uVar10);
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 1) != 0) {
    uVar5 = param_1 + 0x3ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
    func_0210ab48(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,param_2);
    return;
  }
  return;
}

