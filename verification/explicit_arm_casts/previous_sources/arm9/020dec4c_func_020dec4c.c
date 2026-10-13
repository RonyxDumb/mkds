/* Decompiled C draft; module arm9; ROM address 020dec4c. No matching claim. */
#include "types.h"
#include "deps/020dec4c_func_020dec4c.h"

void func_020dec4c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  
  iVar7 = *(ushort *)(param_2 + 0xa4) - 0x40;
  if (iVar7 < 0x40) {
    iVar1 = iVar7 * 0x1a >> 6;
    iVar4 = iVar7 * 0x14 >> 6;
    uVar8 = iVar7 * 0xd >> 6;
    if (0 < iVar1) {
      if (iVar4 < 1) {
        iVar4 = 1;
      }
      if ((int)uVar8 < 1) {
        uVar8 = 1;
      }
    }
    *(int *)(param_2 + 0xe8) = iVar1;
    *(int *)(param_2 + 0xec) = iVar4;
  }
  else {
    *(undefined4 *)(param_2 + 0xe8) = 0x1a;
    *(undefined4 *)(param_2 + 0xec) = 0x14;
    uVar8 = 0xd;
  }
  uVar3 = param_2 + 0x78U & 3;
  uVar5 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if ((iRam020dee78 < (int)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x3fffffe0)) &&
     (iVar7 = func_0203c5e4(), iVar7 == 0)) {
    return;
  }
  iVar7 = iRam020dee80;
  if ((int)uVar8 < 1) {
    return;
  }
  if (*(short *)(param_2 + 0xb0) == 0) {
    *(short *)(param_2 + 0xe4) = (short)uVar8;
    uVar8 = param_2 + 0xa8U & 3;
    uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar6 = uRam020dee7c;
    if (uVar3 >> uVar8 * 8 == 0 && uVar3 << uVar8 * -8 + 0x20 == 0) {
      uVar6 = 0;
    }
    func_020e54e4(param_2 + 0xb4,uVar6,param_3,param_4);
    return;
  }
  if (*(short *)(param_2 + 0xb0) != 1) {
    return;
  }
  uVar3 = param_2 + 0xa8U & 3;
  uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_2 + 0xfcU & 3;
    uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar9 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    *(int *)(iRam020dee80 + 0x24) =
         (int)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) >> 4;
    uVar6 = uRam020dee84;
    uVar3 = uVar9 + 4 & 3;
    uVar5 = *(uint *)(uVar9 + 4 & 0xfffffffc);
    *(int *)(iVar7 + 0x28) = (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) >> 4;
    uVar3 = uVar9 + 8 & 3;
    uVar5 = *(uint *)(uVar9 + 8 & 0xfffffffc);
    *(int *)(iVar7 + 0x2c) = (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) >> 4;
    func_020e5370(uVar6,iVar7,uVar8 & 0xffff,param_4);
    return;
  }
  uVar3 = param_2 + 0x1cU & 3;
  uVar5 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar2 = (ulonglong)uRam020dee88 * (ulonglong)uVar3;
  uStack_20 = (uint)lVar2 >> 0xc |
              (((int)uVar3 >> 0x1f) * uRam020dee88 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
  uVar3 = param_2 + 0x20U & 3;
  uVar5 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar2 = (ulonglong)uRam020dee88 * (ulonglong)uVar3;
  uStack_1c = (uint)lVar2 >> 0xc |
              (((int)uVar3 >> 0x1f) * uRam020dee88 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
  uVar3 = param_2 + 0x24U & 3;
  uVar5 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar2 = (ulonglong)uRam020dee88 * (ulonglong)uVar3;
  uStack_18 = (uint)lVar2 >> 0xc |
              (((int)uVar3 >> 0x1f) * uRam020dee88 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000;
  uVar3 = param_2 + 0x100U & 3;
  uVar5 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) {
    uVar3 = param_2 + 0xfcU & 3;
    uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar9 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    *(int *)(iRam020dee80 + 0x24) =
         (int)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) >> 4;
    uVar3 = uVar9 + 4 & 3;
    uVar5 = *(uint *)(uVar9 + 4 & 0xfffffffc);
    *(int *)(iVar7 + 0x28) = (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) >> 4;
    uVar3 = uVar9 + 8 & 3;
    uVar5 = *(uint *)(uVar9 + 8 & 0xfffffffc);
    *(int *)(iVar7 + 0x2c) = (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) >> 4;
  }
  else {
    uVar3 = param_2 + 0xfcU & 3;
    uVar5 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    iVar7 = func_020e6b58(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  }
  func_020e5370(&uStack_20,iVar7,uVar8 & 0xffff,param_4);
  return;
}

