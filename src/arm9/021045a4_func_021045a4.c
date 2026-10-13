/* Decompiled C draft; module arm9; ROM address 021045a4. No matching claim. */
#include "types.h"
#include "deps/021045a4_func_021045a4.h"

void func_021045a4(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = param_1 + 0x2cU & 3;
  uVar5 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar6 = iRam02104654 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * -4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  sVar3 = *(short *)(param_1 + 0x20);
  sVar4 = *(short *)(param_1 + 0x22);
  iVar7 = 0;
  do {
    iVar1 = iVar7 * 4;
    iVar2 = iVar7 * 4;
    *(short *)(param_1 + iVar7 * 4) =
         sVar3 + (short)(uVar6 * (int)*(short *)(param_1 + 0x10 + iVar7 * 4) >> 0xc);
    iVar7 = iVar7 + 1;
    *(short *)(param_1 + iVar2 + 2) =
         sVar4 + (short)(uVar6 * (int)*(short *)(param_1 + 0x10 + iVar1 + 2) >> 0xc);
  } while (iVar7 < 4);
  uVar6 = param_1 + 0x2cU & 3;
  uVar5 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1;
  uVar6 = param_1 + 0x2cU & 3;
  uVar5 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 0xfffffff3) {
    *(undefined4 *)(param_1 + 0x24) = uRam02104658;
  }
  return;
}

