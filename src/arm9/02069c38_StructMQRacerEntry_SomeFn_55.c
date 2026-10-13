/* Decompiled C draft; module arm9; ROM address 02069c38. No matching claim. */
#include "types.h"
#include "deps/02069c38_StructMQRacerEntry_SomeFn_55.h"

void StructMQRacerEntry_SomeFn_55(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  iVar4 = param_1 + iRam02069dac;
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000000) == 0) {
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x2000) != 0) {
      uVar1 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffdfff;
      uVar1 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffff3fff;
      *(undefined4 *)(param_1 + 0x29c) = 0;
      uVar1 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) == 0) {
        func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
        func_0208c4e8();
      }
      else {
        DriverContext_MaybeQueuePlaySfx(param_1,0xf9,0x7f);
      }
      uVar1 = param_1 + 0x7cU & 3;
      uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      func_0210fa40(0,((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0);
    }
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x8000000) != 0) {
      uVar1 = param_1 + 0x4cU & 3;
      uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      *(uint *)(param_1 + 0x4c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam02069db0;
      uVar1 = param_1 + 0x4cU & 3;
      uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
      if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x2000) != 0) {
        StructMQRacerEntry_SomeFn_36(param_1);
      }
      uVar1 = param_1 + 0x590U & 3;
      uVar3 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      CharacterKartContext_SomeFn_1_1(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    }
    func_02103840(*(undefined2 *)(param_1 + 0x74));
    *(undefined2 *)(iVar4 + 6) = 0;
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x40;
    *(undefined4 *)(param_1 + 0x29c) = 1;
    StructMQRacerEntry_SomeFn_67(param_1);
    func_02081a40(*(undefined2 *)(param_1 + 0x74));
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) &&
       (uVar1 = (*(uint *)(uRam02069db4 & 0xfffffffc) >> (uRam02069db4 & 3) * 8 |
                *(uint *)(uRam02069db4 & 0xfffffffc) << (uRam02069db4 & 3) * -8 + 0x20) + 0xc,
       uVar3 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
       uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0)) {
      func_02106e78();
    }
    uVar1 = (*(uint *)(uRam02069db4 & 0xfffffffc) >> (uRam02069db4 & 3) * 8 |
            *(uint *)(uRam02069db4 & 0xfffffffc) << (uRam02069db4 & 3) * -8 + 0x20) + 8;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) == 2) {
      func_020a1e3c(*(undefined2 *)(param_1 + 0x74));
    }
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x200) != 0) {
      uVar1 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = uVar2 + 0x2c;
      uVar3 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *(uint *)(uVar2 + 0x2c) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) ^ 0x2000;
    }
    DriverContext_UpdateCharacterAnimation(param_1,2,1);
    return;
  }
  return;
}

