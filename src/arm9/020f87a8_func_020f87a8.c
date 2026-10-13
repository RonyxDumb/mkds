/* Decompiled C draft; module arm9; ROM address 020f87a8. No matching claim. */
#include "types.h"
#include "deps/020f87a8_func_020f87a8.h"

void func_020f87a8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  int param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int unaff_r5;
  bool bVar8;
  
  uVar1 = (uint)(param_1 + 6) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = (*(uint *)(uRam020f89a4 & 0xfffffffc) >> (uRam020f89a4 & 3) * 8 |
          *(uint *)(uRam020f89a4 & 0xfffffffc) << (uRam020f89a4 & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  bVar8 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 5;
  if (bVar8) {
    unaff_r5 = 1;
  }
  if (!bVar8) {
    unaff_r5 = 0;
  }
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    return;
  }
  uVar1 = (uint)(param_1 + 5) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 0x13) {
    return;
  }
  *param_1 = 1;
  param_1[3] = 0x13;
  if (unaff_r5 == 0) {
    uVar1 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    func_020be930(*(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1f8));
    if (param_5 == 0) {
      param_1[7] = 0;
      param_1[1] = 0;
      param_1[2] = 0xd5;
      param_1[10] = 0x10;
      param_1[0xb] = 4;
    }
    else {
      param_1[7] = 1;
      param_1[1] = 0x4d;
      param_1[2] = 0x65;
      param_1[10] = 8;
      param_1[0xb] = 3;
    }
  }
  else {
    param_1[7] = 0;
    param_1[1] = 0;
    param_1[2] = 0x85;
    param_1[10] = 0x10;
    param_1[0xb] = 4;
  }
  uVar1 = uVar6 + 0x58;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 0xf) ||
     (uVar6 = uVar6 + 0x5c, uVar1 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     (int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < 9)) {
    uVar3 = GetDriverKartIndexMod3();
    uVar3 = func_020f8a04(uVar3,param_2,param_3,param_4);
    param_1[4] = uVar3;
  }
  else {
    uVar3 = func_020f8a04(0,param_2,param_3,param_4);
    param_1[4] = uVar3;
  }
  if (unaff_r5 == 0) {
    uVar1 = (uint)(param_1 + 4) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    iVar7 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * 0x1c +
            (*(uint *)(uRam020f89a8 & 0xfffffffc) >> (uRam020f89a8 & 3) * 8 |
            *(uint *)(uRam020f89a8 & 0xfffffffc) << (uRam020f89a8 & 3) * -8 + 0x20);
    uVar1 = iVar7 + 8;
    uVar6 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    iVar5 = (uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20) * 0x44 +
            (*(uint *)(uRam020f89ac & 0xfffffffc) >> (uRam020f89ac & 3) * 8 |
            *(uint *)(uRam020f89ac & 0xfffffffc) << (uRam020f89ac & 3) * -8 + 0x20);
    uVar1 = iVar5 + 0x1c;
    uVar6 = uVar1 & 3;
    uVar4 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = iVar7 + 0xc;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(iVar5 + 0x1c) =
         (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
         (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    return;
  }
  uVar1 = (uint)(param_1 + 4) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  func_0205a750(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  param_1[8] = 1;
  return;
}

