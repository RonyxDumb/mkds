/* Decompiled C draft; module arm9; ROM address 02098d4c. No matching claim. */
#include "types.h"
#include "deps/02098d4c_func_02098d4c.h"

void func_02098d4c(int param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  short *psVar7;
  undefined1 auStack_40 [4];
  int local_3c;
  undefined4 local_34 [2];
  undefined4 local_2c;
  
  uVar5 = param_1 + 0x9cU & 3;
  uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x10;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  iVar4 = 0;
  *(uint *)(param_1 + 0x1d8) =
       (((int)uVar5 >> 0x1f) * uRam02098f08 +
        uVar5 * 0xb6 + (int)((ulonglong)uRam02098f08 * (ulonglong)uVar5 >> 0x20) + 0x800) * 0x10 >>
       0x10;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(undefined4 *)(param_1 + 0x1e8) = 0x1000;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0x1000;
  *(undefined4 *)(param_1 + 500) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0x46000;
  uVar1 = uRam02098f0c;
  iVar6 = param_1;
  do {
    iVar4 = iVar4 + 1;
    *(short *)(iVar6 + 0xc0) = (short)uVar1;
    iVar6 = iVar6 + 0x24;
  } while (iVar4 < 7);
  iVar6 = 0;
  psVar7 = (short *)(param_1 + iRam02098f10);
  do {
    if (iVar6 == 0) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x28);
    }
    else if (iVar6 == 1) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x2a);
    }
    else if (iVar6 == 2) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x2c);
    }
    else if (iVar6 == 3) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x2e);
    }
    else if (iVar6 == 4) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x30);
    }
    else if (iVar6 == 5) {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x32);
    }
    else {
      uVar5 = param_1 + 0x9cU & 3;
      uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
      uVar5 = (uint)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x34);
    }
    if (-1 < (int)uVar5) {
      func_020d7db4((uint)*(ushort *)(param_1 + 0x1ba) * 0x24 + param_1 + 0xb8,uVar5 & 0xffff,100);
      func_020d8918((uint)*(ushort *)(param_1 + 0x1ba) * 0x24 + param_1 + 0xb8,auStack_40,local_34);
      iVar4 = FX_Atan2(local_34[0],local_2c);
      uVar5 = param_1 + 0x1d8U & 3;
      uVar3 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
      iVar4 = iVar4 - (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
      if (0x8000 < iVar4) {
        iVar4 = iVar4 + -0x10000;
      }
      *(int *)(param_1 + (uint)*(ushort *)(param_1 + 0x1ba) * 4 + 0x1bc) = iVar4;
      uVar5 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(uint *)(param_1 + 0x1fc) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) - local_3c;
      *psVar7 = *psVar7 + 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 7);
  uVar2 = GetIncrementSomeItemCounter();
  *(undefined2 *)(param_1 + 0xa0) = uVar2;
  func_020ac588(uRam02098f14,0x14,param_1);
  return;
}

