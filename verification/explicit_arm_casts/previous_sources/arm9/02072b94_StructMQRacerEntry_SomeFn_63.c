/* Decompiled C draft; module arm9; ROM address 02072b94. No matching claim. */
#include "types.h"
#include "deps/02072b94_StructMQRacerEntry_SomeFn_63.h"

void StructMQRacerEntry_SomeFn_63(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  StructMQRacerEntry_SomeFn_16();
  uVar2 = param_1 + 0x590U & 3;
  uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  CharacterKartContext_SomeFn_1_1(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  uVar2 = param_1 + 0x210U & 3;
  uVar1 = *(uint *)(param_1 + 0x210U & 0xfffffffc);
  (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff1fff;
  func_02103890(*(undefined2 *)(param_1 + 0x74));
  uVar2 = param_1 + 0x48U & 3;
  uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x240;
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *(undefined4 *)(param_1 + 0x80) = *param_2;
  *(undefined4 *)(param_1 + 0x84) = uVar3;
  *(undefined4 *)(param_1 + 0x88) = uVar4;
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x400) != 0) {
    uVar2 = param_1 + 0x514U & 3;
    uVar1 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    puVar6 = (undefined4 *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    uVar3 = *(undefined4 *)(param_1 + 0x84);
    uVar4 = *(undefined4 *)(param_1 + 0x88);
    *puVar6 = *(undefined4 *)(param_1 + 0x80);
    puVar6[1] = uVar3;
    puVar6[2] = uVar4;
    puVar6[4] = *puVar6;
    puVar6[5] = puVar6[1];
    puVar6[6] = puVar6[2];
    uVar3 = *(undefined4 *)(param_1 + 0x114);
    uVar4 = *(undefined4 *)(param_1 + 0x118);
    uVar5 = *(undefined4 *)(param_1 + 0x11c);
    puVar6[0x13] = *(undefined4 *)(param_1 + 0x110);
    puVar6[0x14] = uVar3;
    puVar6[0x15] = uVar4;
    puVar6[0x16] = uVar5;
    uVar3 = puRam02072d78[1];
    uVar4 = puRam02072d78[2];
    puVar6[0x2a] = *puRam02072d78;
    puVar6[0x2b] = uVar3;
    puVar6[0x2c] = uVar4;
    *(undefined2 *)(puVar6 + 0x2d) = 0;
  }
  if (param_3 != 0) {
    uVar2 = param_3 + 8 & 3;
    uVar1 = *(uint *)(param_3 + 8 & 0xfffffffc);
    uVar2 = func_02148538(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20,
                          uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    puVar6 = puRam02072d80;
    *(short *)(param_1 + 0x236) =
         (short)((int)((uint)((ulonglong)uRam02072d7c * (ulonglong)uVar2) >> 0xc |
                      (((int)uVar2 >> 0x1f) * uRam02072d7c +
                      (int)((ulonglong)uRam02072d7c * (ulonglong)uVar2 >> 0x20)) * 0x100000) >> 0xc)
    ;
    local_28 = *puVar6;
    uStack_24 = puVar6[1];
    uStack_20 = puVar6[2];
    func_01ffd190(&local_28,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
  }
  func_01ffcd84(param_1 + 0x120,param_1 + 0xe0);
  GetMQRacerVector333(param_1,param_1 + 0x278);
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x278);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x27c);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x280);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x58);
  puVar6 = (undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x8c) = *puVar6;
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 0x1c4) = *puVar6;
  *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x1cc) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x1b8) = *puVar6;
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x88);
  uVar2 = param_1 + 0x84U & 3;
  uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x2ac) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 2) != 0) {
    if (param_4 == 0) {
      uVar2 = param_1 + 0x310U & 3;
      uVar1 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
      func_0208c260(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,*(undefined2 *)(param_1 + 0x74))
      ;
    }
    else {
      uVar2 = param_1 + 0x310U & 3;
      uVar1 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
      func_0208c23c(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_4);
    }
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    func_0207409c(param_2,param_1 + 0xe0);
    func_02074828();
    func_02089f9c();
    func_020747f4(0);
    return;
  }
  return;
}

