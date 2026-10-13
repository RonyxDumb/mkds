/* Decompiled C draft; module arm9; ROM address 020f9f08. No matching claim. */
#include "types.h"
#include "deps/020f9f08_func_020f9f08.h"

void func_020f9f08(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = uRam020f9fa4;
  uVar3 = param_1 + 0x70U & 3;
  uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar2 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)param_2;
  iVar5 = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) * 0xa8;
  uVar3 = (*(uint *)(uRam020f9fa4 & 0xfffffffc) >> (uRam020f9fa4 & 3) * 8 |
          *(uint *)(uRam020f9fa4 & 0xfffffffc) << (uRam020f9fa4 & 3) * -8 + 0x20) + iVar5 + 0x68;
  uVar2 = uVar3 & 3;
  uVar7 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(param_1 + 0x68) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x70U & 3;
  uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)param_3;
  *(uint *)(param_1 + 0x6c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = param_1 + 0x6cU & 3;
  uVar8 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + iVar5 + 100;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  *(uint *)(param_1 + 0xdc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x6cU & 3;
  uVar4 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0xe0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0xe0U & 3;
  uVar2 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  func_020d5148((int)*(short *)(param_1 + 0xda),
                (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0xa000);
  return;
}

