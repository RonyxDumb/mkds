/* Decompiled C draft; module arm9; ROM address 02064d60. No matching claim. */
#include "types.h"
#include "deps/02064d60_StructMQRacerEntry_SomeFn_84.h"

void StructMQRacerEntry_SomeFn_84(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar6;
  undefined1 auStack_20 [20];
  uint uVar5;
  
  uVar2 = param_1 + 0x514U & 3;
  uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar5 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x3f8) = 0x1000;
  uVar2 = param_1 + 0x380U & 3;
  uVar4 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < 6) ||
     (uVar2 = param_1 + 0x514U & 3, uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc),
     uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x44, uVar4 = uVar2 & 3,
     uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 1) != 0)) {
    func_01ffad14(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x3a8) = 0xf6;
    StructMQRacerEntry_SomeFn_88(param_1,param_1 + 0x100);
  }
  uVar2 = param_1 + 0x3a8U & 3;
  uVar4 = *(uint *)(param_1 + 0x3a8U & 0xfffffffc);
  func_01ffce48(param_1 + 0xf0,param_1 + 0x100,param_1 + 0xf0,
                uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  uVar1 = *(ushort *)(uVar5 + 0xe);
  iVar6 = (uint)*(ushort *)(param_1 + 0x236) - (uint)uVar1;
  iVar3 = iVar6;
  if (iVar6 < 1) {
    iVar3 = -iVar6;
  }
  if (iRam02064f30 < iVar3) {
    if (iVar6 < 1) {
      iVar6 = iVar6 + iRam02064f34;
    }
    else {
      iVar6 = -(iRam02064f34 - iVar6);
    }
  }
  *(ushort *)(uVar5 + 0xe) = uVar1 + (short)((uint)(iRam02064f38 * iVar6) >> 0xc);
  func_01ffd190(uRam02064f3c,*(short *)(param_1 + 0x236) + *(short *)(param_1 + 0x4de),
                param_1 + 0xe0);
  func_01ffcebc(param_1 + 0xf0,param_1 + 0xe0,param_1 + 0x110);
  uVar2 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 2) == 0) {
    *(undefined2 *)(param_1 + 0x2c0) = 0;
  }
  else {
    uVar2 = param_1 + 0x2b8U & 3;
    uVar4 = *(uint *)(param_1 + 0x2b8U & 0xfffffffc);
    if ((int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) < 1) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
    }
    else {
      uVar2 = param_1 + 700U & 3;
      uVar4 = *(uint *)(param_1 + 700U & 0xfffffffc);
      *(short *)(param_1 + 0x2c0) =
           (short)uRam02064f40 -
           (short)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 500 >> 0xc);
      if (uRam02064f44 < *(ushort *)(param_1 + 0x2c0)) {
        *(short *)(param_1 + 0x2c0) = (short)uRam02064f48;
      }
    }
    func_01ffd190(uRam02064f4c,-*(short *)(param_1 + 0x2c0),auStack_20);
    func_01ffcebc(param_1 + 0x110,auStack_20,param_1 + 0x110);
  }
  func_01ffcf7c(param_1 + 0x110,param_1 + 0x110);
  return;
}

