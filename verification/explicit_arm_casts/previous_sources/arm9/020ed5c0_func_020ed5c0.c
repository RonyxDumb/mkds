/* Decompiled C draft; module arm9; ROM address 020ed5c0. No matching claim. */
#include "types.h"
#include "deps/020ed5c0_func_020ed5c0.h"

void func_020ed5c0(int param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = *(ushort *)(param_1 + 0xd8);
  if (uVar1 != 0x1f) {
    uVar9 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0xffe0ffff;
    uVar9 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) =
         uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20 | (uint)uVar1 << 0x10;
  }
  func_020e6a18(param_2);
  uVar9 = param_1 + 0xf4U & 3;
  uVar3 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
  if (((int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) < iRam020ed714) ||
     (uVar9 = param_1 + 0x74U & 3, uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0x80) != 0)) {
    uVar4 = param_3[1];
    uVar6 = param_3[2];
    *(undefined4 *)(param_1 + 0xac) = *param_3;
    *(undefined4 *)(param_1 + 0xb0) = uVar4;
    *(undefined4 *)(param_1 + 0xb4) = uVar6;
    Vector3_Cross(param_1 + 0xf0,(undefined4 *)(param_1 + 0xac),param_1 + 0x94);
    uVar9 = param_1 + 0x98U & 3;
    uVar3 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
    uVar7 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    uVar9 = param_1 + 0x94U & 3;
    uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar3 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    uVar9 = param_1 + 0x9cU & 3;
    uVar8 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
    uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    lVar2 = (longlong)(int)uVar9 * (longlong)(int)uVar9 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar7 * (longlong)(int)uVar7;
    if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
      Vector3_MaybeNormalize(param_1 + 0x94,param_1 + 0x94);
    }
    Vector3_Cross(param_1 + 0xac,param_1 + 0x94,param_1 + 0xa0);
    uVar9 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    uVar7 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    iVar5 = param_1 + 0x94;
    *(int *)(param_1 + 0xb8) =
         (int)(*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) >> 4;
    uVar9 = uVar7 + 4 & 3;
    uVar3 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    *(int *)(param_1 + 0xbc) = (int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) >> 4;
    uVar9 = uVar7 + 8 & 3;
    uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    *(int *)(param_1 + 0xc0) = (int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) >> 4;
  }
  else {
    uVar9 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    iVar5 = func_020e6b94(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20);
  }
  func_020e67c4(param_2,iVar5,param_1 + 0x68,0,0x1f);
  if (*(short *)(param_1 + 0xd8) != 0x1f) {
    uVar9 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) & 0xffe0ffff;
    uVar9 = param_2 + 0x14U & 3;
    uVar3 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20 | 0x1f0000;
    return;
  }
  return;
}

