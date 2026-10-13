/* Decompiled C draft; module arm9; ROM address 01ffc6c0. No matching claim. */
#include "types.h"
#include "deps/01ffc6c0_func_01ffc6c0.h"

void func_01ffc6c0(int param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar1 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x4000) != 0) &&
     (*(short *)(param_1 + 0x23a) = *(short *)(param_1 + 0x23a) + -1,
     *(short *)(param_1 + 0x23a) < 1)) {
    *(undefined2 *)(param_1 + 0x23a) = 0;
    uVar1 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xfffbbfff;
  }
  iVar4 = IsAwardOrStaffRoll();
  if (iVar4 != 1) {
    func_01ffc92c(param_1);
    func_01ffc558(param_1);
    func_01ffc5a0(param_1);
    uVar1 = param_1 + 0x78U & 3;
    uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar2 = *(ushort *)(iRam01ffc8c8 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c);
    if ((uVar2 & 0x20) == 0) {
      if ((uVar2 & 0x10) != 0) {
        uVar1 = param_1 + 0x48U & 3;
        uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x10;
      }
    }
    else {
      uVar1 = param_1 + 0x48U & 3;
      uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 8;
    }
    uVar1 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x10;
    return;
  }
  uVar6 = 0;
  iVar5 = func_01ffc67c(param_1);
  iVar4 = iRam01ffc8b8;
  if (iVar5 == 0) {
    uVar1 = param_1 + 0x78U & 3;
    uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(short *)(iRam01ffc8b8 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c) =
         (short)uRam01ffc8c4;
    func_01ffc558(param_1);
  }
  else {
    uVar1 = param_1 + 0x78U & 3;
    uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(short *)(iRam01ffc8b8 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c) =
         (short)uRam01ffc8b4;
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000000) != 0) {
      uVar1 = param_1 + 0x78U & 3;
      uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(short *)(iVar4 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c) =
           (short)uRam01ffc8bc;
    }
    uVar1 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x2000000) != 0) {
      uVar1 = param_1 + 0x78U & 3;
      uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(short *)(iRam01ffc8b8 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x5c) =
           (short)uRam01ffc8c0;
    }
  }
  func_01ffc5a0(param_1);
  uVar1 = param_1 + 0x180U & 3;
  uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar6 = 0;
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 8) == 0) {
      uVar6 = func_0206c494(param_1,0);
    }
    uVar6 = func_01ffc27c(param_1,uVar6);
    func_0206c5e4(param_1);
    func_01ffba68(param_1);
  }
  func_01ffc090(param_1,uVar6);
  iVar4 = func_01ffc92c(param_1);
  if (iVar4 != 0) {
    uVar1 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x840) == 0) {
      uVar1 = param_1 + 0x3ccU & 3;
      uVar3 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
      StructMQRacerEntry_SomeFn_5(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,8);
      return;
    }
    return;
  }
  return;
}

