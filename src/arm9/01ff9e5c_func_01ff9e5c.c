/* Decompiled C draft; module arm9; ROM address 01ff9e5c. No matching claim. */
#include "types.h"
#include "deps/01ff9e5c_func_01ff9e5c.h"

void func_01ff9e5c(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined8 uVar8;
  
  uVar2 = func_020d59f8(uRam01ff9f50);
  *(int *)(param_1 + 0x3e0) = (int)(uVar2 & 0x1f00) >> 8;
  *(uint *)(param_1 + 0x3e4) = ((uVar2 & 0xe0) << 0xb) >> 0x10;
  uVar2 = param_1 + 0x3e0U & 3;
  uVar4 = *(uint *)(param_1 + 0x3e0U & 0xfffffffc);
  uVar2 = iRam01ff9f54 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 4;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar6 = 0x1000;
  uVar8 = (*(code *)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20))(param_1);
  uVar4 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar2 = (uint)uVar8;
  if (uVar2 != 0) {
    uVar4 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  uVar3 = param_1 + 0xdcU & 3;
  uVar5 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (uVar2 != 0) {
    uVar4 = uVar4 + uVar2 * 4 + 0x68;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  }
  if ((int)uVar6 < (int)uVar3) {
    lVar1 = (ulonglong)uRam01ff9f58 * (ulonglong)(uVar6 - uVar3);
    uVar4 = (uint)lVar1;
    *(uint *)(param_1 + 0xdc) =
         uVar3 + (uVar4 + 0x800 >> 0xc |
                 (((int)(uVar6 - uVar3) >> 0x1f) * uRam01ff9f58 + (int)((ulonglong)lVar1 >> 0x20) +
                 (uint)(0xfffff7ff < uVar4)) * 0x100000);
  }
  else {
    *(uint *)(param_1 + 0xdc) = uVar6;
  }
  uVar4 = param_1 + 0x4cU & 3;
  uVar6 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  bVar7 = (uVar4 & uRam01ff9f5c) != 0;
  if (bVar7) {
    uVar4 = 0;
  }
  uVar6 = param_1 + 0x2ccU & 3;
  uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  if (!bVar7) {
    uVar4 = uVar2;
  }
  uVar4 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + uVar4 * 4 + 0x38;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x240) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar4 = param_1 + 0x48U & 3;
  uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x40000000) != 0) &&
      (uVar4 = param_1 + 0x44U & 3, uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
      ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x10) != 0)) && (uVar2 != 0xb)) {
    uVar4 = param_1 + 0x48U & 3;
    uVar6 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xbfffffff;
  }
  *(uint *)(param_1 + 0x3dc) = uVar2;
  return;
}

