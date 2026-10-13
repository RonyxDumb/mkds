/* Decompiled C draft; module arm9; ROM address 021009fc. No matching claim. */
#include "types.h"
#include "deps/021009fc_func_021009fc.h"

void func_021009fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar1 = 8;
  }
  iVar5 = uVar1 * 0x210 +
          (*(uint *)(uRam02100b44 & 0xfffffffc) >> (uRam02100b44 & 3) * 8 |
          *(uint *)(uRam02100b44 & 0xfffffffc) << (uRam02100b44 & 3) * -8 + 0x20);
  uVar1 = iVar5 + 0x1fc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(param_1 + 0x168) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x144) = 0;
  uVar1 = param_1 + 0x24cU & 3;
  uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = iVar5 + 0x14;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 0x10) {
      uVar1 = param_1 + 0x168U & 3;
      uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar3 = *(undefined4 *)(uVar1 + 0x9c);
      uVar6 = *(undefined4 *)(uVar1 + 0xa0);
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(uVar1 + 0x98);
      *(undefined4 *)(param_1 + 0x188) = uVar3;
      *(undefined4 *)(param_1 + 0x18c) = uVar6;
      uVar1 = param_1 + 0x168U & 3;
      uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar3 = *(undefined4 *)(uVar1 + 0xa8);
      uVar6 = *(undefined4 *)(uVar1 + 0xac);
      *(undefined4 *)(param_1 + 400) = *(undefined4 *)(uVar1 + 0xa4);
      *(undefined4 *)(param_1 + 0x194) = uVar3;
      *(undefined4 *)(param_1 + 0x198) = uVar6;
      *(undefined4 *)(param_1 + 0x16c) = 0;
      *(undefined4 *)(param_1 + 0x174) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x144) = 1;
      uVar1 = param_1 + 0x74U & 3;
      uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) != 0) {
        func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),1,5);
      }
      *(undefined4 *)(param_1 + 0x16c) = 0;
      *(undefined4 *)(param_1 + 0x174) = 0;
    }
  }
  uVar1 = param_1 + 0x160U & 3;
  uVar2 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0xf) {
    uVar1 = iRam02100b48 + 4U & 3;
    uVar2 = *(uint *)(iRam02100b48 + 4U & 0xfffffffc);
    func_020f4020(param_1 + 0x1a4,(undefined4 *)(uintptr_t)(iRam02100b48),uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0x248) = 3;
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  else {
    uVar1 = param_1 + 0x150U & 3;
    uVar2 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
    *(uint *)(param_1 + 0x17c) = -(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x14cU & 3;
    uVar2 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
    *(uint *)(param_1 + 0x170) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  uVar1 = param_1 + 0x144U & 3;
  uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x168U & 3;
    uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    func_020f8e3c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0xf7);
  }
  *(undefined4 *)(param_1 + 0x270) = 0;
  uVar1 = param_1 + 0x168U & 3;
  uVar2 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x48;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  pcVar4 = pcRam02100b4c;
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    pcVar4 = pcRam02100b50;
  }
  (*pcVar4)(param_1);
  return;
}

