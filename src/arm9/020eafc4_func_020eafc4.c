/* Decompiled C draft; module arm9; ROM address 020eafc4. No matching claim. */
#include "types.h"
#include "deps/020eafc4_func_020eafc4.h"

undefined4
func_020eafc4(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
             int param_6,uint *param_7)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined1 auStack_30 [12];
  
  uVar10 = param_3 + 0x18;
  uVar11 = param_3 + 0xc;
  VecFx32_Subtract(param_1,param_2,(int *)(void *)(auStack_30));
  iVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_30),param_3);
  iVar8 = (*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
          *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) + param_6;
  if ((iVar8 <= iVar3) ||
     (iVar5 = (*(uint *)(param_5 & 0xfffffffc) >> (param_5 & 3) * 8 |
              *(uint *)(param_5 & 0xfffffffc) << (param_5 & 3) * -8 + 0x20) + param_6,
     iVar3 == -iVar5 || iVar3 + iVar5 < 0 != SBORROW4(iVar3,-iVar5))) {
    return 0;
  }
  if (iVar3 < 1) {
    iVar8 = iVar3 + iVar5;
  }
  else {
    iVar8 = iVar8 - iVar3;
  }
  iVar5 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_30),uVar11);
  uVar1 = param_4 + 4 & 3;
  uVar6 = *(uint *)(param_4 + 4 & 0xfffffffc);
  iVar9 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_6;
  if ((iVar9 <= iVar5) ||
     (uVar1 = param_5 + 4 & 3, uVar6 = *(uint *)(param_5 + 4 & 0xfffffffc),
     iVar7 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_6,
     iVar5 == -iVar7 || iVar5 + iVar7 < 0 != SBORROW4(iVar5,-iVar7))) {
    return 0;
  }
  if (iVar5 < 1) {
    iVar9 = iVar5 + iVar7;
  }
  else {
    iVar9 = iVar9 - iVar5;
  }
  iVar4 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_30),uVar10);
  uVar1 = param_4 + 8 & 3;
  uVar6 = *(uint *)(param_4 + 8 & 0xfffffffc);
  iVar7 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_6;
  if ((iVar7 <= iVar4) ||
     (uVar1 = param_5 + 8 & 3, uVar6 = *(uint *)(param_5 + 8 & 0xfffffffc),
     param_6 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + param_6,
     iVar4 == -param_6 || iVar4 + param_6 < 0 != SBORROW4(iVar4,-param_6))) {
    return 0;
  }
  if (iVar4 < 1) {
    iVar7 = iVar4 + param_6;
  }
  else {
    iVar7 = iVar7 - iVar4;
  }
  if (iVar8 <= iVar7) {
    if ((iVar9 < iVar8) && (0 < iVar5)) {
      if (param_7 != (uint *)0x0) {
        lVar2 = (longlong)
                (int)(*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                     *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) * (longlong)iVar9;
        *param_7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        uVar10 = param_3 + 0x10 & 3;
        uVar11 = *(uint *)(param_3 + 0x10 & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) *
                (longlong)iVar9;
        param_7[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        uVar10 = param_3 + 0x14 & 3;
        uVar11 = *(uint *)(param_3 + 0x14 & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) *
                (longlong)iVar9;
        param_7[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      }
      return 1;
    }
    if (param_7 != (uint *)0x0) {
      if (iVar3 < 1) {
        iVar8 = -iVar8;
      }
      lVar2 = (longlong)
              (int)(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                   *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) * (longlong)iVar8;
      *param_7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar10 = param_3 + 4 & 3;
      uVar11 = *(uint *)(param_3 + 4 & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar8
      ;
      param_7[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar10 = param_3 + 8 & 3;
      uVar11 = *(uint *)(param_3 + 8 & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar8
      ;
      param_7[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      param_7[1] = 0;
    }
    return 3;
  }
  if ((iVar9 < iVar7) && (0 < iVar5)) {
    if (param_7 != (uint *)0x0) {
      lVar2 = (longlong)
              (int)(*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                   *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) * (longlong)iVar9;
      *param_7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar10 = param_3 + 0x10 & 3;
      uVar11 = *(uint *)(param_3 + 0x10 & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar9
      ;
      param_7[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
      uVar10 = param_3 + 0x14 & 3;
      uVar11 = *(uint *)(param_3 + 0x14 & 0xfffffffc);
      lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar9
      ;
      param_7[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    }
    return 1;
  }
  if (param_7 != (uint *)0x0) {
    if (iVar4 < 1) {
      iVar7 = -iVar7;
    }
    lVar2 = (longlong)
            (int)(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                 *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) * (longlong)iVar7;
    *param_7 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar10 = param_3 + 0x1c & 3;
    uVar11 = *(uint *)(param_3 + 0x1c & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar7;
    param_7[1] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar10 = param_3 + 0x20 & 3;
    uVar11 = *(uint *)(param_3 + 0x20 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) * (longlong)iVar7;
    param_7[2] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    param_7[1] = 0;
  }
  return 4;
}

