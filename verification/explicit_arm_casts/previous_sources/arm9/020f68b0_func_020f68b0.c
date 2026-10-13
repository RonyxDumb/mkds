/* Decompiled C draft; module arm9; ROM address 020f68b0. No matching claim. */
#include "types.h"
#include "deps/020f68b0_func_020f68b0.h"

void func_020f68b0(int param_1)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_10 [8];
  uint uVar2;
  
  uVar2 = param_1 + 0x104U & 3;
  uVar1 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 == 0 &&
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 == 0) {
    uVar2 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x40) != 0) {
      uVar2 = param_1 + 0xdcU & 3;
      uVar1 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
      VecFx32_AddScale1(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_1 + 0xf0,
                        param_1 + 0x108,param_1 + 0x50);
      return;
    }
    return;
  }
  iVar3 = func_020e04b0(uVar2,param_1 + 0x108,param_1 + 0xf0);
  if (iVar3 != 0) {
    func_020f65c4(param_1);
  }
  uVar2 = param_1 + 0x104U & 3;
  uVar1 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x130;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
     (uVar2 = param_1 + 0xf4U & 3, uVar1 = *(uint *)(param_1 + 0xf4U & 0xfffffffc),
     (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < iRam020f6a68)) {
    uVar2 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x80;
  }
  uVar2 = param_1 + 0xdcU & 3;
  uVar1 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  VecFx32_AddScale1(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,param_1 + 0xf0,param_1 + 0x108,
                    param_1 + 0x50);
  if (*(short *)(param_1 + 0x11a) < 1) {
    VecFx32_Subtract(param_1 + 0x50,param_1 + 0xe4,param_1 + 0x5c);
    return;
  }
  *(short *)(param_1 + 0x11a) = *(short *)(param_1 + 0x11a) + -1;
  uVar1 = func_02061f90();
  uVar2 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 7) != uVar1) {
    return;
  }
  uVar2 = param_1 + 0xdcU & 3;
  uVar1 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar3 = func_01ffdee4(param_1 + 0x50,0,0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  if (iVar3 != 0) {
    uVar2 = param_1 + 0xfcU & 3;
    uVar4 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    uVar1 = param_1 + 0x104U & 3;
    uVar5 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    iVar3 = func_020d5a68(auStack_10,uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,
                          uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
      *(undefined4 *)(param_1 + 100) = 0;
      func_020f6fc4(param_1,1);
    }
    uVar2 = param_1 + 0xfcU & 3;
    uVar1 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000) != 0) {
      func_020f7070(param_1,1);
      return;
    }
    return;
  }
  return;
}

