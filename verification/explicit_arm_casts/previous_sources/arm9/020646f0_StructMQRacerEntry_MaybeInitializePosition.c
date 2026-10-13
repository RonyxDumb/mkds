/* Decompiled C draft; module arm9; ROM address 020646f0. No matching claim. */
#include "types.h"
#include "deps/020646f0_StructMQRacerEntry_MaybeInitializePosition.h"

void StructMQRacerEntry_MaybeInitializePosition(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 local_60;
  int local_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [12];
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 uStack_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  if (param_2 == 0) {
    func_02041bb0(param_1 + 0x80,&local_60,*(undefined2 *)(param_1 + 0x74));
    uVar2 = (*(uint *)(uRam020649d8 & 0xfffffffc) >> (uRam020649d8 & 3) * 8 |
            *(uint *)(uRam020649d8 & 0xfffffffc) << (uRam020649d8 & 3) * -8 + 0x20) + 0xc;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 5) {
      puVar3 = (undefined4 *)((uint)*(ushort *)(param_1 + 0x74) * 0xc + iRam020649dc);
      uVar7 = puVar3[1];
      uVar9 = puVar3[2];
      *(undefined4 *)(param_1 + 0x80) = *puVar3;
      *(undefined4 *)(param_1 + 0x84) = uVar7;
      *(undefined4 *)(param_1 + 0x88) = uVar9;
    }
  }
  else {
    uVar4 = *(uint *)(uRam020649e0 & 0xfffffffc) >> (uRam020649e0 & 3) * 8 |
            *(uint *)(uRam020649e0 & 0xfffffffc) << (uRam020649e0 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0x3c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    if (puVar3 != (undefined4 *)0x0) {
      if ((undefined4 *)(param_1 + 0x80) != (undefined4 *)0x0) {
        uVar7 = puVar3[1];
        uVar9 = puVar3[2];
        *(undefined4 *)(param_1 + 0x80) = *puVar3;
        *(undefined4 *)(param_1 + 0x84) = uVar7;
        *(undefined4 *)(param_1 + 0x88) = uVar9;
      }
      uVar4 = uVar4 + 0x3c;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      local_60 = *(undefined4 *)(uVar2 + 0xc);
      local_5c = *(int *)(uVar2 + 0x10);
      uStack_58 = *(undefined4 *)(uVar2 + 0x14);
    }
  }
  uVar2 = param_1 + 0x7cU & 3;
  uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 0x600) != 0) {
    uVar2 = param_1 + 0x80U & 3;
    uVar5 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
    uVar4 = param_1 + 0x84U & 3;
    uVar8 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    uVar1 = param_1 + 0x88U & 3;
    uVar10 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
    *(int *)(param_1 + 0x80) =
         (((int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) >> 10) << 0x10) >> 6;
    *(int *)(param_1 + 0x84) =
         (((int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) >> 10) << 0x10) >> 6;
    *(int *)(param_1 + 0x88) =
         (((int)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) >> 10) << 0x10) >> 6;
  }
  local_3c = *(undefined4 *)(param_1 + 0x80);
  uStack_34 = *(undefined4 *)(param_1 + 0x88);
  local_38 = *(int *)(param_1 + 0x84) + 0x1000;
  uVar2 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x84) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - 0x1400;
  iVar6 = func_01ffdee4((undefined4 *)(param_1 + 0x80),&local_3c,param_1 + 0x50,0x5000,1,0xfffffffe,
                        auStack_54,&local_48,0,0,0,0,0,0);
  if (iVar6 != 0) {
    local_30 = (uint)((ulonglong)local_48 * 0x5000) >> 0xc |
               (int)((ulonglong)local_48 * 0x5000 >> 0x20) * 0x100000;
    local_2c = (uint)((ulonglong)local_44 * 0x5000) >> 0xc |
               (int)((ulonglong)local_44 * 0x5000 >> 0x20) * 0x100000;
    local_28 = (uint)((ulonglong)local_40 * 0x5000) >> 0xc |
               (int)((ulonglong)local_40 * 0x5000 >> 0x20) * 0x100000;
    VecFx32_Subtract(auStack_54,&local_30,auStack_54);
    VecFx32_Add(param_1 + 0x80,auStack_54,param_1 + 0x80);
  }
  uVar2 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x84) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - 0x1000;
  *(short *)(param_1 + 0x236) = (short)((uint)(local_5c * 0xb6) >> 0xc);
  func_01ffd190(uRam020649e4,*(undefined2 *)(param_1 + 0x236),param_1 + 0xe0);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0xe4);
  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0xec);
  func_01ffcd84(param_1 + 0x120,(undefined4 *)(param_1 + 0x110));
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x120);
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x124);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0x128);
  *(undefined4 *)(param_1 + 0x15c) = *(undefined4 *)(param_1 + 300);
  *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(param_1 + 0x130);
  *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(param_1 + 0x134);
  *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(param_1 + 0x138);
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x140);
  *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x94);
  uVar2 = param_1 + 0x98U & 3;
  uVar4 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  *(uint *)(param_1 + 0x174) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x9cU & 3;
  uVar4 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  *(uint *)(param_1 + 0x178) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0xa0U & 3;
  uVar4 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  *(uint *)(param_1 + 0x17c) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x138U & 3;
  uVar4 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  *(uint *)(param_1 + 0x278) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x13cU & 3;
  uVar4 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
  *(uint *)(param_1 + 0x27c) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x140U & 3;
  uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  *(uint *)(param_1 + 0x280) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x278);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x27c);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x280);
  *(undefined4 **)(param_1 + 0x1b4) = (undefined4 *)(param_1 + 0x150);
  uVar2 = param_1 + 0x590U & 3;
  uVar4 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 != 0) {
    if (*(short *)(uVar2 + 0x18) != 0) {
      uVar4 = uVar4 + 0x2c;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar2 + 0xc) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    }
    return;
  }
  return;
}

