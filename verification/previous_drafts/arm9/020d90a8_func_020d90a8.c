/* Decompiled C draft; module arm9; ROM address 020d90a8. No matching claim. */
#include "types.h"
#include "deps/020d90a8_func_020d90a8.h"

void func_020d90a8(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar5 = uVar7 + 8 & 3;
  uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
    if ((param_2 == 0) && (param_3 == 0)) {
      param_3 = 1;
    }
    else {
      uVar5 = uVar7 + 4 & 3;
      uVar3 = *(uint *)(uVar7 + 4 & 0xfffffffc);
      if ((param_2 == (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) && (param_3 != 0)) {
        param_3 = 0;
      }
    }
  }
  else if ((param_2 == 0) && (param_3 == 0)) {
    uVar5 = uVar7 + 4 & 3;
    uVar3 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    param_2 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) & 0xffff;
  }
  uVar5 = param_2;
  if (param_3 == 0) {
    uVar5 = param_2 - 1;
  }
  *(uint *)(param_1 + 0xc) = uVar5;
  uVar6 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar5 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) * 0x54 + uVar6 + 0x34;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar2 = CONCAT44(uVar5,uVar6);
  if (uVar5 != 0) {
    uVar3 = param_1 + 4 & 3;
    uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * (longlong)(int)uVar5;
  }
  if (uVar5 != 0) {
    uVar5 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  }
  else {
    uVar5 = 0x1000000;
  }
  *(uint *)(param_1 + 0x10) = uVar5;
  if (param_3 == 0) {
    uVar4 = 0x1000000;
  }
  else {
    uVar4 = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = uVar4;
  *(int *)(param_1 + 0x18) = param_3;
  uVar5 = param_1 + 0x18 & 3;
  uVar6 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar3 = param_2;
  if (((uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0) &&
      (uVar5 = uVar7 + 8 & 3, uVar6 = *(uint *)(uVar7 + 8 & 0xfffffffc),
      uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0)) &&
     (uVar5 = uVar7 + 4 & 3, uVar6 = *(uint *)(uVar7 + 4 & 0xfffffffc),
     param_2 == (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20))) {
    uVar3 = 0;
  }
  uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8),uVar3);
  *(undefined4 *)(param_1 + 0x1c) = uVar4;
  uVar5 = param_1 + 0x18 & 3;
  uVar6 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar3 = uVar6 >> uVar5 * 8;
  iVar1 = uVar6 << uVar5 * -8 + 0x20;
  if (uVar3 == 0 && iVar1 == 0) {
    param_2 = param_2 - 1;
  }
  else {
    param_2 = param_2 + 1;
  }
  param_2 = param_2 & 0xffff;
  if (((uVar3 != 0 || iVar1 != 0) &&
      (uVar5 = uVar7 + 8 & 3, uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc),
      uVar3 >> uVar5 * 8 != 0 || uVar3 << uVar5 * -8 + 0x20 != 0)) &&
     (uVar5 = uVar7 + 4 & 3, uVar3 = *(uint *)(uVar7 + 4 & 0xfffffffc),
     param_2 == (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20))) {
    param_2 = 0;
  }
  uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8),param_2);
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  return;
}

