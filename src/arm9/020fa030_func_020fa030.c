/* Decompiled C draft; module arm9; ROM address 020fa030. No matching claim. */
#include "types.h"
#include "deps/020fa030_func_020fa030.h"

void func_020fa030(int param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar5 = param_1 + 0x44U & 3;
  uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x40;
  uVar3 = uRam020fa0b4;
  uVar1 = param_1 + 0x70U & 3;
  uVar4 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  *(uint *)(param_1 + 0x6c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x6cU & 3;
  uVar4 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(uint *)(param_1 + 0x68) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar4 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = param_1 + 0x6cU & 3;
  uVar6 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  iVar7 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) * 0xa8 +
          (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar1 = iVar7 + 100;
  uVar5 = uVar1 & 3;
  uVar8 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = iVar7 + 0x6c;
  uVar4 = uVar1 & 3;
  uVar9 = *(uint *)(uVar1 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0xdc) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x6cU & 3;
  uVar5 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
  *(uint *)(param_1 + 0xe0) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0xe0U & 3;
  uVar5 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  func_020d5148((int)*(short *)(param_1 + 0xda),
                (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0xa000);
  return;
}

