/* Decompiled C draft; module arm9; ROM address 020924d8. No matching claim. */
#include "types.h"
#include "deps/020924d8_func_020924d8.h"

void func_020924d8(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  
  uVar6 = param_2 + 0xc4U & 3;
  uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  uVar3 = param_2 + 200U & 3;
  uVar2 = *(uint *)(param_2 + 200U & 0xfffffffc);
  piVar8 = (int *)(param_2 + 0xc4);
  *(uint *)(param_2 + 0xc4) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
       (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar6 = param_2 + 200U & 3;
  uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
  piVar7 = (int *)(param_2 + 200);
  *(uint *)(param_2 + 200) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x3c;
  uVar6 = param_2 + 0xc4U & 3;
  uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if (uVar6 == 0) {
    uVar6 = param_2 + 200U & 3;
    uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
    *piVar8 = (*(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
              *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20) +
              (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    *piVar7 = (*(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
              *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20) + 0x3c;
  }
  else if (DAT_020927f8 <= (int)uVar6) {
    uVar6 = param_2 + 200U & 3;
    uVar3 = *(uint *)(param_2 + 200U & 0xfffffffc);
    *(uint *)(param_2 + 200) = 0x3c - (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    uVar6 = param_2 + 0xccU & 3;
    uVar3 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
    *(uint *)(param_2 + 0xcc) = (uint)(uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0);
  }
  uVar3 = DAT_020927fc;
  uVar6 = param_2 + 0xd4U & 3;
  uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  switch(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) {
  case 0:
    uVar6 = param_2 + 0xb0U & 3;
    uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0xb0) = uVar3 - 1;
    uVar6 = DAT_020927fc;
    if ((int)uVar3 < 1) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
      iVar4 = DAT_02092800;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffd;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfff7;
      *(undefined2 *)(param_2 + 0x66) = 0x1f;
      uVar3 = param_2 + 0x40U & 3;
      uVar2 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = param_2 + 0xa0U & 3;
      uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      lVar1 = (ulonglong)uVar6 * (ulonglong)uVar2;
      *(uint *)(param_2 + 0xa0) =
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
           ((uint)lVar1 >> 0xc |
           (((int)uVar2 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
      uVar3 = param_2 + 0xa4U & 3;
      uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar4;
      uVar3 = param_2 + 0x48U & 3;
      uVar2 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = param_2 + 0xa8U & 3;
      uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      lVar1 = (ulonglong)uVar6 * (ulonglong)uVar2;
      *(uint *)(param_2 + 0xa8) =
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
           ((uint)lVar1 >> 0xc |
           (((int)uVar2 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
      VecFx32_Add(param_2 + 4,param_2 + 0xa0,(int *)(uintptr_t)(param_2 + 4));
      uVar6 = param_2 + 0xb4U & 3;
      uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
      *(uint *)(param_2 + 0xb4) = uVar6 - 1;
      if ((int)uVar6 < 1) {
        *(undefined4 *)(param_2 + 0xd4) = 1;
      }
    }
    break;
  case 1:
    uVar6 = param_2 + 0x40U & 3;
    uVar2 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    lVar1 = (ulonglong)DAT_020927fc * (ulonglong)uVar2;
    uVar6 = param_2 + 0xa0U & 3;
    uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) =
         (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar2 >> 0x1f) * DAT_020927fc + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar6 = param_2 + 0xa4U & 3;
    uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + uVar3;
    uVar6 = param_2 + 0x48U & 3;
    uVar2 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
    uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    lVar1 = (ulonglong)uVar3 * (ulonglong)uVar2;
    *(uint *)(param_2 + 0xa8) =
         (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar2 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    VecFx32_Add(param_2 + 4,param_2 + 0xa0,(int *)(uintptr_t)(param_2 + 4));
    uVar6 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    if (0 < (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa4) = 0;
      *(undefined4 *)(param_2 + 0xd4) = 2;
    }
    break;
  case 2:
    VecFx32_Add(param_2 + 4,param_2 + 0xa0,(int *)(uintptr_t)(param_2 + 4));
    uVar6 = param_2 + 0xb8U & 3;
    uVar3 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0xb8) = uVar6 - 1;
    if ((int)uVar6 < 1) {
      *(undefined4 *)(param_2 + 0xd4) = 3;
    }
    break;
  case 3:
    uVar6 = param_2 + 0x40U & 3;
    uVar3 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    lVar1 = (ulonglong)uVar3 * 0xcd;
    uVar6 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) =
         (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) -
         ((uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * 0xcd + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar6 = param_2 + 0xa4U & 3;
    uVar3 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x1000;
    uVar6 = param_2 + 0x48U & 3;
    uVar3 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    lVar1 = (ulonglong)uVar3 * 0xcd;
    *(uint *)(param_2 + 0xa8) =
         (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) -
         ((uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * 0xcd + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    VecFx32_Add(param_2 + 4,param_2 + 0xa0,(int *)(uintptr_t)(param_2 + 4));
    uVar6 = param_2 + 8U & 3;
    uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
    if (0x1b7fff < (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20)) {
      func_020d2398(param_2);
    }
  }
  uVar6 = param_2 + 0xb0U & 3;
  uVar3 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20)) {
    return;
  }
  iVar9 = *(ushort *)(param_2 + 0xac) + 1;
  iVar4 = StructMapObject_SomeFn_1
                    (*(uint *)(DAT_02092804 & 0xfffffffc) >> (DAT_02092804 & 3) * 8 |
                     *(uint *)(DAT_02092804 & 0xfffffffc) << (DAT_02092804 & 3) * -8 + 0x20);
  if (iVar4 <= iVar9) {
    iVar9 = 0;
  }
  *(short *)(param_2 + 0xac) = (short)iVar9;
  uVar6 = param_2 + 0xbcU & 3;
  uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0) {
    return;
  }
  func_020d275c(param_2,DAT_02092808);
  return;
}

