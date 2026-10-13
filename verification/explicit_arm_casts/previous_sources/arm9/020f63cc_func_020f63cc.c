/* Decompiled C draft; module arm9; ROM address 020f63cc. No matching claim. */
#include "types.h"
#include "deps/020f63cc_func_020f63cc.h"

void func_020f63cc(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [24];
  undefined1 auStack_34 [16];
  uint uVar3;
  
  iVar7 = param_1 + 0x50;
  iVar6 = param_1 + 0x5c;
  VecFx32_Add(iVar6,iVar7,iVar7);
  uVar5 = uRam020f65b4;
  uVar3 = param_1 + 0x5cU & 3;
  uVar2 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020f65b4 * (ulonglong)uVar3;
  *(uint *)(param_1 + 0x5c) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uRam020f65b4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 100U & 3;
  uVar2 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  lVar1 = (ulonglong)uVar5 * (ulonglong)uVar3;
  *(uint *)(param_1 + 100) =
       (uint)lVar1 >> 0xc |
       (((int)uVar3 >> 0x1f) * uVar5 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar3 = param_1 + 0xdcU & 3;
  uVar5 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar4 = func_01ffdee4(iVar7,param_1 + 0xe4,0,uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  if (iVar4 != 0) {
    VecFx32_Add(auStack_4c,iVar7,iVar7);
    uVar3 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam020f65b8) != 0) {
      func_020f9334(param_1,iVar7,iVar6,iRam020f65bc);
    }
    uVar3 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam020f65c0) != 0) {
      uVar3 = param_1 + 0x74U & 3;
      uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      *(uint *)(param_1 + 0x74) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 0x20;
      func_020f92e8(iVar6,auStack_34);
      iVar4 = func_020f9290(param_1,auStack_34);
      if (iVar4 != 0) {
        return;
      }
    }
    uVar3 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x8000) != 0) {
      func_020f7070(param_1,1);
      return;
    }
  }
  uVar5 = uRam020f65b8;
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfbffffff;
  uVar3 = param_1 + 0xfcU & 3;
  uVar2 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if ((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & uVar5) == 0) &&
     (uVar3 = param_1 + 0x60U & 3, uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc),
     *(uint *)(param_1 + 0x60) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) - iRam020f65bc,
     uVar3 = param_1 + 0x60U & 3, uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc),
     (int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) < -0xa000)) {
    *(undefined4 *)(param_1 + 0x60) = 0xffff6000;
  }
  uVar3 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if ((uVar3 & 8) != 0) {
    if ((uVar3 & 3) == 0) {
      func_020f6a6c(param_1,auStack_50);
      return;
    }
    return;
  }
  return;
}

