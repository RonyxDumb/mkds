/* Decompiled C draft; module arm9; ROM address 020f6a6c. No matching claim. */
#include "types.h"
#include "deps/020f6a6c_func_020f6a6c.h"

void func_020f6a6c(int param_1,undefined4 param_2)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = param_1 + 0xdcU & 3;
  uVar2 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  VecFx32_AddScale1(-(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20),param_1 + 0xf0,param_1 + 0x50
                    ,(int *)(uintptr_t)(param_1 + 0x108));
  uVar4 = param_1 + 0xfcU & 3;
  uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  uVar2 = param_1 + 0x104U & 3;
  uVar7 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  func_020d5aa0(param_2,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,
                (undefined4 *)(uintptr_t)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20),param_1 + 0x108,param_1 + 0xf0);
  uVar4 = param_1 + 0x104U & 3;
  uVar2 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) ||
     (iVar3 = func_020e0448(), iVar3 == 0)) {
    *(undefined2 *)(param_1 + 0x11a) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x11a) = 0xe10;
  }
  uVar5 = uRam020f6bd0;
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x8000;
  uVar4 = param_1 + 0x44U & 3;
  uVar7 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) * 0xa8 +
          (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x44;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) &&
     (uVar4 = param_1 + 0x74U & 3, uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x180000) == 0)) {
    *(undefined4 *)(param_1 + 0x120) = uRam020f6bd4;
  }
  uVar4 = uRam020f6bd0;
  *(undefined4 *)(param_1 + 0x124) = uRam020f6bd8;
  uVar7 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = param_1 + 0x44U & 3;
  uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar2 = param_1 + 0x60U & 3;
  uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  uVar4 = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) * 0xa8 +
          (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x7c;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((int)uVar5 < 1) {
    uVar5 = -uVar5;
  }
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x100) = -((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar4 = param_1 + 0x100U & 3;
  uVar2 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < iRam020f6bdc) {
    *(int *)(param_1 + 0x100) = iRam020f6bdc;
  }
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  func_020f90dc(param_1);
  uVar4 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  func_020f0e2c((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020f6be0 & 0xfffffffc) >> (uRam020f6be0 & 3) * 8 |
                *(uint *)(uRam020f6be0 & 0xfffffffc) << (uRam020f6be0 & 3) * -8 + 0x20),param_1);
  uVar4 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f6bd0 & 0xfffffffc) >> (uRam020f6bd0 & 3) * 8 |
          *(uint *)(uRam020f6bd0 & 0xfffffffc) << (uRam020f6bd0 & 3) * -8 + 0x20) + 0x9c;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  func_020f91fc(param_1,uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  return;
}

