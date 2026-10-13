/* Decompiled C draft; module arm9; ROM address 020732d8. No matching claim. */
#include "types.h"
#include "deps/020732d8_func_020732d8.h"

void func_020732d8(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar7 = param_1 + 0x78U & 3;
  uVar6 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  *(short *)(iRam020733d8 + (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 0x5c) =
       (short)uRam020733d4;
  uVar7 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x20) != 0) {
    StructMQRacerEntry_SomeFn_53();
    return;
  }
  *(short *)(param_1 + 0x3c8) = *(short *)(param_1 + 0x3c8) + 1;
  iVar3 = iRam020733e4;
  iVar2 = iRam020733e0;
  iVar8 = (int)*(short *)(param_1 + 0x3c8);
  if (iVar8 < 0x19) {
    uVar7 = iRam020733dc + iVar8 * 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x41c) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar7 = iVar2 + iVar8 * 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x420) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar7 = iVar3 + iVar8 * 4;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x424) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar7 = param_1 + 0x428U & 3;
    uVar5 = *(uint *)(param_1 + 0x428U & 0xfffffffc);
    uVar6 = param_1 + 0x41cU & 3;
    uVar4 = *(uint *)(param_1 + 0x41cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    *(uint *)(param_1 + 0xbc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar7 = param_1 + 0x42cU & 3;
    uVar5 = *(uint *)(param_1 + 0x42cU & 0xfffffffc);
    uVar6 = param_1 + 0x420U & 3;
    uVar4 = *(uint *)(param_1 + 0x420U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar7 = param_1 + 0x430U & 3;
    uVar5 = *(uint *)(param_1 + 0x430U & 0xfffffffc);
    uVar6 = param_1 + 0x424U & 3;
    uVar4 = *(uint *)(param_1 + 0x424U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    *(uint *)(param_1 + 0xc4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar7 = param_1 + 0x434U & 3;
    uVar5 = *(uint *)(param_1 + 0x434U & 0xfffffffc);
    uVar6 = param_1 + 0xc0U & 3;
    uVar4 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) *
            (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    *(uint *)(param_1 + 0xc0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    return;
  }
  uVar7 = param_1 + 0x7cU & 3;
  uVar6 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffffff7f;
  return;
}

