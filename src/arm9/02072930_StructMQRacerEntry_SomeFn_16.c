/* Decompiled C draft; module arm9; ROM address 02072930. No matching claim. */
#include "types.h"
#include "deps/02072930_StructMQRacerEntry_SomeFn_16.h"

void StructMQRacerEntry_SomeFn_16(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_28 [4];
  
  func_020f0044((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                (*(uint *)(uRam02072b88 & 0xfffffffc) >> (uRam02072b88 & 3) * 8 |
                *(uint *)(uRam02072b88 & 0xfffffffc) << (uRam02072b88 & 3) * -8 + 0x20));
  StructMQRacerEntry_SomeFn_17(param_1);
  func_02081768(*(undefined2 *)(param_1 + 0x74));
  func_020815a0(*(undefined2 *)(param_1 + 0x74));
  func_02081338(*(undefined2 *)(param_1 + 0x74));
  func_020810e4(*(undefined2 *)(param_1 + 0x74));
  StructMQRacerEntry_SomeFn_22(param_1);
  StructMQRacerEntry_SomeFn_23(param_1);
  func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
  func_0208c5d0();
  DriverContext_CreateSub450_2(param_1);
  if ((uint)*(ushort *)(param_1 + 0x74) ==
      (int)*(char *)((*(uint *)(uRam02072b8c & 0xfffffffc) >> (uRam02072b8c & 3) * 8 |
                     *(uint *)(uRam02072b8c & 0xfffffffc) << (uRam02072b8c & 3) * -8 + 0x20) + 0x62)
     ) {
    func_0210fa74(0);
  }
  func_0210a664(param_1);
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x2000) != 0) {
    StructMQRacerEntry_SomeFn_2(param_1);
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x40) != 0) {
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffffbf;
    func_0207b1a8(param_1);
    *(undefined4 *)(param_1 + 0x29c) = 0;
    func_020817b8(*(undefined2 *)(param_1 + 0x74));
    DriverContext_UpdateCharacterAnimation(param_1,0,1);
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) &&
       (uVar2 = (*(uint *)(uRam02072b8c & 0xfffffffc) >> (uRam02072b8c & 3) * 8 |
                *(uint *)(uRam02072b8c & 0xfffffffc) << (uRam02072b8c & 3) * -8 + 0x20) + 0xc,
       uVar1 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
       uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0)) {
      func_02106dc8();
    }
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x2000) != 0) {
      StructMQRacerEntry_SomeFn_36(param_1);
    }
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x10000000) != 0) {
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xefffffff;
    func_0210515c(*(undefined2 *)(param_1 + 0x74));
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
      func_02074854();
    }
    *(undefined4 *)(param_1 + 0x4c8) = 0x1000;
    *(undefined4 *)(param_1 + 0x3dc) = 0xffffffff;
    iVar4 = 0;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    uVar2 = param_1 + 0x590U & 3;
    uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
    uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x58;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
      local_28[0] = *puRam02072b90;
      local_28[1] = puRam02072b90[1];
      local_28[2] = puRam02072b90[2];
      do {
        uVar3 = func_0208b7bc(local_28[iVar4],param_1 + 0x80);
        func_02081f10(uVar3,*(undefined2 *)(param_1 + 0x74),0x14);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 3);
    }
    func_020815dc(*(undefined2 *)(param_1 + 0x74));
    DriverContext_MaybeQueuePlaySfx(param_1,0xfd,0x7f,0);
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x2000) != 0) {
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffdfff;
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff3fff;
    *(undefined4 *)(param_1 + 0x29c) = 0;
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
      func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
      func_0208c4e8();
    }
    else {
      DriverContext_MaybeQueuePlaySfx(param_1,0xf9,0x7f);
    }
    uVar2 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    func_0210fa40(0,((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0);
    return;
  }
  return;
}

