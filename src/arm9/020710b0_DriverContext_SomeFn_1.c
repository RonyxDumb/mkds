/* Decompiled C draft; module arm9; ROM address 020710b0. No matching claim. */
#include "types.h"
#include "deps/020710b0_DriverContext_SomeFn_1.h"

void DriverContext_SomeFn_1(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    uVar2 = param_1 + 0x48U & 3;
    uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x40000;
    uVar2 = param_1 + 0x44U & 3;
    uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffffef;
  }
  uVar2 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & uRam020712fc;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar2 = param_1 + 0x48U & 3, uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x2000) != 0) {
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffdfff;
    *(undefined4 *)(param_1 + 0xd8) = 0x1000;
    uVar2 = param_1 + 0x4cU & 3;
    uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) == 0) {
      StructMQRacerEntry_SomeFn_2(param_1);
    }
    StructMQRacerEntry_SomeFn_3(param_1);
  }
  StructMQRacerEntry_SomeFn_22(param_1);
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & uRam02071300;
  *(undefined4 *)(param_1 + 0x2c4) = 0;
  *(undefined4 *)(param_1 + 0x2fc) = 0;
  *(undefined2 *)(param_1 + 0x302) = 0;
  *(undefined2 *)(param_1 + 0x300) = *(undefined2 *)(param_1 + 0x302);
  *(undefined4 *)(param_1 + 0x30c) = 0;
  func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
  func_0208c534();
  *(undefined4 *)(param_1 + 0x180) = 0;
  uVar2 = param_1 + 0x4cU & 3;
  uVar1 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffffffcf;
  uVar2 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xfffdffff;
  DriverContext_UpdateCharacterAnimation(param_1,0,1);
  uVar2 = param_1 + 0x44U & 3;
  uVar1 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x80000000;
  StructMQRacerEntry_SomeFn_11(param_1);
  StructMQRacerEntry_SomeFn_12(param_1);
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    return;
  }
  func_02073f90();
  uVar1 = *(uint *)(uRam02071304 & 0xfffffffc) >> (uRam02071304 & 3) * 8 |
          *(uint *)(uRam02071304 & 0xfffffffc) << (uRam02071304 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0x13) {
    if (uVar2 == 0x21) {
      iVar3 = DriverContext_MaybeQueuePlaySfx(param_1,uRam02071314,0x7f,0);
      if (iVar3 != 0) {
        *(byte *)(iVar3 + 0x19) = *(byte *)(iVar3 + 0x19) | 0x10;
      }
      return;
    }
    return;
  }
  func_02089d14(0);
  iVar3 = DriverContext_MaybeQueuePlaySfx(param_1,0x15c,0x7f,0);
  if (iVar3 != 0) {
    *(byte *)(iVar3 + 0x19) = *(byte *)(iVar3 + 0x19) | 0x10;
  }
  uVar2 = func_02108e6c(7);
  if (((*(uint *)(uRam02071308 & 0xfffffffc) >> (uRam02071308 & 3) * 8 |
       *(uint *)(uRam02071308 & 0xfffffffc) << (uRam02071308 & 3) * -8 + 0x20) & 1) != 0) {
    uVar1 = iRam0207130c + 0xcU & 3;
    uVar4 = *(uint *)(iRam0207130c + 0xcU & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar2,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar2,0,uRam02071310);
      return;
    }
    return;
  }
  return;
}

