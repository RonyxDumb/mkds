/* Decompiled C draft; module arm9; ROM address 020f6630. No matching claim. */
#include "types.h"
#include "deps/020f6630_func_020f6630.h"

void func_020f6630(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  longlong lVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int local_30;
  int local_2c;
  int local_28;
  
  puVar2 = puRam020f681c;
  uVar6 = param_1 + 0x44U & 3;
  uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = (*(uint *)(uRam020f6818 & 0xfffffffc) >> (uRam020f6818 & 3) * 8 |
          *(uint *)(uRam020f6818 & 0xfffffffc) << (uRam020f6818 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar7 & 3;
  uVar3 = *(uint *)(uVar7 & 0xfffffffc);
  piVar9 = (int *)(param_1 + 0x5c);
  uVar7 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f6814 & 0xfffffffc) >> (uRam020f6814 & 3) * 8 |
          *(uint *)(uRam020f6814 & 0xfffffffc) << (uRam020f6814 & 3) * -8 + 0x20) + 0x80;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 1) ||
     (uVar6 = param_1 + 0x74U & 3, uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x8000000) != 0)) {
    uVar7 = 0;
  }
  uVar6 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20 | 0x4000;
  *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) | *puVar2;
  iVar5 = Vector3_DotProduct(param_5,piVar9);
  lVar1 = (longlong)
          (int)(*(uint *)(param_5 & 0xfffffffc) >> (param_5 & 3) * 8 |
               *(uint *)(param_5 & 0xfffffffc) << (param_5 & 3) * -8 + 0x20) * (longlong)iVar5;
  *piVar9 = (*(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
            *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20) -
            ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar6 = param_5 + 4 & 3;
  uVar3 = *(uint *)(param_5 + 4 & 0xfffffffc);
  uVar4 = param_1 + 0x60U & 3;
  uVar8 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * (longlong)iVar5;
  *(uint *)(param_1 + 0x60) =
       (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  uVar6 = param_5 + 8 & 3;
  uVar3 = *(uint *)(param_5 + 8 & 0xfffffffc);
  uVar4 = param_1 + 100U & 3;
  uVar8 = *(uint *)(param_1 + 100U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) * (longlong)iVar5;
  *(uint *)(param_1 + 100) =
       (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  iVar5 = VecFx32_CrossProduct_0(param_4,param_5);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (iRam020f6820 < iVar5) {
    iVar5 = iRam020f6820;
  }
  if (uVar7 == 0) {
    iVar10 = 0x3800;
  }
  else {
    iVar10 = 0x2800;
  }
  VecFx32_AddScale1(iVar5 + iVar10,param_5,piVar9,piVar9);
  if (param_2 != 0) {
    VecFx32_Subtract(param_1 + 0x50,param_3,&local_30);
    lVar1 = (longlong)local_28 * (longlong)local_28 +
            (longlong)local_30 * (longlong)local_30 + (longlong)local_2c * (longlong)local_2c;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(&local_30,&local_30);
    }
    VecFx32_AddScale1(param_2 * iRam020f6824,&local_30,piVar9,piVar9);
  }
  if (uVar7 == 0) {
    uVar7 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xffffbfff;
    func_020f7070(param_1,1);
    return;
  }
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020f6828;
  }
  *(undefined4 *)(param_1 + 0x124) = uRam020f682c;
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xf8ffffff;
  return;
}

