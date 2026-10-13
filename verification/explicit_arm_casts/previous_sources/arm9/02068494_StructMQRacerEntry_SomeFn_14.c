/* Decompiled C draft; module arm9; ROM address 02068494. No matching claim. */
#include "types.h"
#include "deps/02068494_StructMQRacerEntry_SomeFn_14.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void StructMQRacerEntry_SomeFn_14(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [12];
  undefined4 *puVar2;
  
  uVar4 = param_1 + 0x2a8U & 3;
  uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  local_44 = *(undefined4 *)(param_1 + 0x80);
  uStack_40 = *(undefined4 *)(param_1 + 0x84);
  uStack_3c = *(undefined4 *)(param_1 + 0x88);
  if (param_2 != 0) {
    uVar6 = *(uint *)(uRam02068638 & 0xfffffffc) >> (uRam02068638 & 3) * 8 |
            *(uint *)(uRam02068638 & 0xfffffffc) << (uRam02068638 & 3) * -8 + 0x20;
    uVar3 = uVar6 + 0x3c & 3;
    uVar1 = *(uint *)(uVar6 + 0x3c & 0xfffffffc);
    puVar2 = (undefined4 *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    local_38 = *puVar2;
    uStack_34 = puVar2[1];
    uStack_30 = puVar2[2];
    uVar3 = uVar6 + 0x3c & 3;
    uVar1 = *(uint *)(uVar6 + 0x3c & 0xfffffffc);
    uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
    local_2c = *(undefined4 *)(uVar3 + 0xc);
    uStack_28 = *(undefined4 *)(uVar3 + 0x10);
    uStack_24 = *(undefined4 *)(uVar3 + 0x14);
    uVar3 = uVar6 + 0x3c & 3;
    uVar1 = *(uint *)(uVar6 + 0x3c & 0xfffffffc);
    local_48 = *(short *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0x1a);
  }
  StructMQRacerEntry_SomeFn_16(param_1);
  uVar3 = param_1 + 0x590U & 3;
  uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  CharacterKartContext_SomeFn_1_1(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0x210U & 3;
  uVar1 = *(uint *)(param_1 + 0x210U & 0xfffffffc);
  (*(code *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20))(param_1);
  uVar3 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xffff1fff;
  func_02103890(*(undefined2 *)(param_1 + 0x74));
  StructMQRacerEntry_MaybeInitializePosition(param_1,param_2);
  uVar3 = param_1 + 0x84U & 3;
  uVar1 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x84) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) - 0x1000;
  if ((param_2 != 0) && (local_48 != 0)) {
    *(uint *)(param_1 + 0x2a8) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar4 = param_1 + 0x48U & 3;
    uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x2000;
  }
  uVar4 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x44) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x10;
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x10) != 0) {
    if (param_3 == 0) {
      uVar4 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x20000;
      DriverContext_UpdateCharacterAnimation(param_1,3,1);
    }
    else {
      uVar4 = param_1 + 0x7cU & 3;
      uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x10000;
      DriverContext_UpdateCharacterAnimation(param_1,2,1);
    }
  }
  uVar4 = (*(uint *)(uRam0206863c & 0xfffffffc) >> (uRam0206863c & 3) * 8 |
          *(uint *)(uRam0206863c & 0xfffffffc) << (uRam0206863c & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
    VecFx32_Subtract(param_1 + 0x80,&local_44,auStack_20);
    func_020a21bc(*(undefined2 *)(param_1 + 0x74),auStack_20);
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 1) == 0) {
    return;
  }
  func_02055bd4(0);
  func_020e79c4();
  return;
}

