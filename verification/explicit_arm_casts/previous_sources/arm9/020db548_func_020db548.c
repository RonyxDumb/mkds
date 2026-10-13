/* Decompiled C draft; module arm9; ROM address 020db548. No matching claim. */
#include "types.h"
#include "deps/020db548_func_020db548.h"

uint func_020db548(int param_1,int param_2,char *param_3,byte *param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int unaff_r8;
  int iVar11;
  bool bVar12;
  int local_40 [2];
  int local_38;
  undefined1 auStack_34 [4];
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  
  uVar10 = param_1 + 200;
  if ((*param_3 == '\x01') &&
     ((((uint)*(ushort *)(param_1 + 0xc0) & 1 << (*(ushort *)(param_2 + 0x74) & 0xff)) == 0 ||
      (uVar5 = GetSomeTimeOrDuration(), uVar9 = param_1 + 0xbcU & 3,
      uVar8 = *(uint *)(param_1 + 0xbcU & 0xfffffffc),
      (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 0xf < uVar5)))) {
    VecFx32_Subtract(param_2 + 0x1b8,param_1 + 4,local_40);
    uVar9 = param_1 + 0xe8U & 3;
    uVar5 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    VecFx32_Subtract(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20,param_1 + 4,auStack_34);
    uVar9 = param_1 + 0xf8U & 3;
    uVar5 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
    local_30 = local_30 + (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
    iVar6 = VecFx32_CrossProduct_0(local_40,auStack_34);
    if (0 < iVar6) {
      func_020d8620(uVar10);
    }
    uVar9 = param_1 + 0xa0U & 3;
    uVar5 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
    uVar5 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
    uVar9 = param_1 + 0x20U & 3;
    uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    if ((int)uVar5 < 4) {
      unaff_r8 = 0xa800;
    }
    uVar9 = 0x1000 - (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
    if (3 < (int)uVar5) {
      unaff_r8 = 0x8000;
    }
    iVar6 = unaff_r8 - (uVar9 * 0x2000 >> 0xc | (uVar9 >> 0x13) << 0x14);
    *(int *)(param_1 + 0xcc) = iVar6;
    uVar5 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
    uVar10 = param_1 + 0xd4U & 3;
    uVar8 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    uVar9 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar10 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) * 0x54 +
             (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 0x34;
    uVar9 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar4 = (undefined2)uRam020db75c;
    lVar2 = (longlong)iVar6 * (longlong)(int)(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20);
    *(uint *)(param_1 + 0xd8) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    *(undefined4 *)(param_1 + 0xb4) = 1;
    *(undefined2 *)(param_1 + 0xb8) = uVar4;
    uVar10 = param_2 + 0xa4U & 3;
    uVar8 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar9 = param_2 + 0xacU & 3;
    uVar5 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    lVar2 = (longlong)local_38 * (longlong)(int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20);
    lVar3 = (longlong)local_40[0] * (longlong)(int)(uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20)
    ;
    if ((int)((int)((ulonglong)lVar2 >> 0x20) -
             ((int)((ulonglong)lVar3 >> 0x20) + (uint)((uint)lVar2 < (uint)lVar3))) < 0) {
      *(short *)(param_1 + 0xb8) = -*(short *)(param_1 + 0xb8);
    }
    func_020d26f8(param_1,param_2);
    *(ushort *)(param_1 + 0xc0) =
         *(ushort *)(param_1 + 0xc0) | (ushort)(1 << (*(ushort *)(param_2 + 0x74) & 0xff));
    uVar7 = GetSomeTimeOrDuration();
    *(undefined4 *)(param_1 + 0xbc) = uVar7;
  }
  uVar10 = param_1 + 0xa0U & 3;
  uVar9 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  if (((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) == 4) ||
     (uVar10 = param_1 + 0xb0U & 3, uVar9 = *(uint *)(param_1 + 0xb0U & 0xfffffffc),
     uVar9 >> uVar10 * 8 != 0 || uVar9 << uVar10 * -8 + 0x20 != 0)) {
    VecFx32_Subtract(param_2 + 0x1b8,param_1 + 4,&local_28);
    uVar1 = (longlong)local_28 * (longlong)local_28 + (longlong)local_20 * (longlong)local_20;
    lVar2 = (uVar1 & 0xffffffff) * 5;
    iVar11 = (int)(uVar1 >> 0x20) * 5 + (int)((ulonglong)lVar2 >> 0x20);
    lVar3 = (longlong)local_24 * (longlong)local_24 * 4;
    iVar6 = (int)((ulonglong)lVar3 >> 0x20);
    if ((local_24 < 0) &&
       (bVar12 = (uint)lVar2 < (uint)lVar3,
       (int)(iVar11 - (iVar6 + (uint)bVar12)) < 0 !=
       (SBORROW4(iVar11,iVar6) != SBORROW4(iVar11 - iVar6,(uint)bVar12)))) {
      uVar10 = param_2 + 0x29cU & 3;
      uVar9 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
      uVar10 = func_020d6dc0(*(ushort *)(param_1 + 2) & 0x800,
                             uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20,4,4);
      return uVar10;
    }
  }
  return (uint)*param_4;
}

