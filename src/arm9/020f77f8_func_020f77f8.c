/* Decompiled C draft; module arm9; ROM address 020f77f8. No matching claim. */
#include "types.h"
#include "deps/020f77f8_func_020f77f8.h"

void func_020f77f8(int param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar13;
  bool bVar14;
  uint uStack_4c;
  int iStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uVar12;
  
  uVar12 = param_1 + 0x74U & 3;
  uVar11 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  if ((uVar12 & 0x80000) != 0) {
    return;
  }
  if (param_5 == 0) {
    uVar11 = 0xffffffff;
  }
  else {
    uVar11 = param_5 + 0x98U & 3;
    uVar3 = *(uint *)(param_5 + 0x98U & 0xfffffffc);
    uVar11 = (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) + 0x28;
    uVar3 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar11 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
  }
  if (param_2 == 1) {
    if ((uVar12 & 0x1000) == 0) {
      VecFx32_Subtract(param_1 + 0xe4,param_3,&uStack_4c);
      uVar12 = param_1 + 0x74U & 3;
      uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      uVar12 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
      if (((uVar12 & 0x8000) == 0) && ((uVar12 & 0x1000000) != 0)) {
        func_020f7c90(param_1,param_3);
      }
      else {
        uVar12 = param_1 + 0x74U & 3;
        uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20 | 0x4000000;
        iVar5 = VecFx32_CrossProduct_0(param_1 + 0x5c,(uint)(uintptr_t)(&uStack_4c));
        if (iVar5 < 1) {
          lVar1 = (longlong)(int)uStack_44 * (longlong)(int)uStack_44 +
                  (longlong)(int)uStack_4c * (longlong)(int)uStack_4c +
                  (longlong)iStack_48 * (longlong)iStack_48;
          if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
            Vector3_MaybeNormalize((uint)(uintptr_t)(&uStack_4c),&uStack_4c);
          }
          uVar12 = param_1 + 0x124U & 3;
          uVar3 = *(uint *)(param_1 + 0x124U & 0xfffffffc);
          (*(code *)(uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20))(param_1,param_4);
          uVar12 = param_1 + 0x74U & 3;
          uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
          if (((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) & 0x8000) == 0) {
            uVar12 = param_3 + 4 & 3;
            uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
            uVar3 = param_1 + 0x54U & 3;
            uVar10 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
            uVar9 = param_1 + 0xe0U & 3;
            uVar7 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
            uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
            iVar5 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) -
                    (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
            uVar10 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                     *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
            uVar12 = param_1 + 0x50U & 3;
            uVar9 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
            uVar3 = param_3 + 8 & 3;
            uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
            iVar13 = uVar10 - (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
            uVar12 = param_1 + 0x58U & 3;
            uVar9 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
            iVar4 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
                    (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
            lVar1 = (longlong)iVar4 * (longlong)iVar4 +
                    (longlong)iVar13 * (longlong)iVar13 + (longlong)iVar5 * (longlong)iVar5;
            iVar4 = (int)((ulonglong)lVar1 >> 0x20);
            iVar5 = (int)((ulonglong)((longlong)(int)uVar7 * (longlong)(int)uVar7) >> 0x20);
            bVar14 = (uint)lVar1 < (uint)((longlong)(int)uVar7 * (longlong)(int)uVar7);
            if ((int)(iVar4 - (iVar5 + (uint)bVar14)) < 0 !=
                (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)bVar14))) {
              *(uint *)(param_1 + 0x50) =
                   uVar10 + ((uint)((ulonglong)uStack_4c * (ulonglong)uVar7) >> 0xc |
                            (((int)uVar7 >> 0x1f) * uStack_4c +
                            uVar7 * ((int)uStack_4c >> 0x1f) +
                            (int)((ulonglong)uStack_4c * (ulonglong)uVar7 >> 0x20)) * 0x100000);
              uVar12 = param_3 + 8 & 3;
              uVar3 = *(uint *)(param_3 + 8 & 0xfffffffc);
              *(uint *)(param_1 + 0x58) =
                   (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) +
                   ((uint)((ulonglong)uStack_44 * (ulonglong)uVar7) >> 0xc |
                   (((int)uVar7 >> 0x1f) * uStack_44 +
                   uVar7 * ((int)uStack_44 >> 0x1f) +
                   (int)((ulonglong)uStack_44 * (ulonglong)uVar7 >> 0x20)) * 0x100000);
            }
          }
        }
        else {
          uVar12 = param_1 + 0x74U & 3;
          uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
          if (((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) & 0x8000) == 0) {
            uVar12 = param_3 + 4 & 3;
            uVar7 = *(uint *)(param_3 + 4 & 0xfffffffc);
            uVar3 = param_1 + 0x54U & 3;
            uVar6 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
            uVar9 = param_1 + 0xe0U & 3;
            uVar10 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
            uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
            iVar5 = (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) -
                    (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
            uVar12 = param_1 + 0x50U & 3;
            uVar10 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
            uVar3 = param_3 + 8 & 3;
            uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc);
            iVar13 = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                     *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) -
                     (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20);
            uVar12 = param_1 + 0x58U & 3;
            uVar10 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
            iVar4 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
                    (uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20);
            lVar1 = (longlong)iVar4 * (longlong)iVar4 +
                    (longlong)iVar13 * (longlong)iVar13 + (longlong)iVar5 * (longlong)iVar5;
            iVar4 = (int)((ulonglong)lVar1 >> 0x20);
            lVar2 = (longlong)(int)uVar9 * (longlong)(int)uVar9;
            iVar5 = (int)((ulonglong)lVar2 >> 0x20);
            bVar14 = (uint)lVar1 < (uint)lVar2;
            if ((int)(iVar4 - (iVar5 + (uint)bVar14)) < 0 !=
                (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)bVar14))) {
              lVar1 = (longlong)(int)uStack_44 * (longlong)(int)uStack_44 +
                      (longlong)(int)uStack_4c * (longlong)(int)uStack_4c +
                      (longlong)iStack_48 * (longlong)iStack_48;
              if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
                Vector3_MaybeNormalize((uint)(uintptr_t)(&uStack_4c),&uStack_4c);
              }
              uVar12 = param_1 + 0xe0U & 3;
              uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
              uVar3 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
              lVar1 = (longlong)(int)uVar3 * (longlong)(int)uStack_4c;
              *(uint *)(param_1 + 0x50) =
                   (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                   *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) +
                   ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
              uVar12 = param_3 + 8 & 3;
              uVar9 = *(uint *)(param_3 + 8 & 0xfffffffc);
              lVar1 = (longlong)(int)uVar3 * (longlong)(int)uStack_44;
              *(uint *)(param_1 + 0x58) =
                   (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) +
                   ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
            }
          }
        }
      }
    }
  }
  else if (param_2 == 2) {
    if ((uVar12 & 0x1000) != 0) {
      func_020eda5c((*(ushort *)(param_1 + 0x78) & 0xffff00ff) * 0x210 +
                    (*(uint *)(uRam020f7c54 & 0xfffffffc) >> (uRam020f7c54 & 3) * 8 |
                    *(uint *)(uRam020f7c54 & 0xfffffffc) << (uRam020f7c54 & 3) * -8 + 0x20) + 0x58,
                    param_1);
    }
    uVar12 = param_4 + 4 & 3;
    uVar3 = *(uint *)(param_4 + 4 & 0xfffffffc);
    uVar9 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
    uVar3 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
            *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
    uVar12 = param_4 + 8 & 3;
    uVar10 = *(uint *)(param_4 + 8 & 0xfffffffc);
    uVar12 = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar12 * (longlong)(int)uVar12 +
            (longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar9 * (longlong)(int)uVar9;
    iVar5 = 0;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      iVar5 = Vector3_MaybeNormalize(param_4,&uStack_40);
    }
    if (iVar5 == 0) {
      VecFx32_Subtract(param_1 + 0x50,param_3,&uStack_40);
      if ((int)uStack_3c < 0) {
        uStack_3c = 0;
      }
      lVar1 = (longlong)(int)uStack_38 * (longlong)(int)uStack_38 +
              (longlong)(int)uStack_40 * (longlong)(int)uStack_40 +
              (longlong)(int)uStack_3c * (longlong)(int)uStack_3c;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(&uStack_40),&uStack_40);
      }
      uStack_34 = (uint)((ulonglong)uStack_40 * 0x1800) >> 0xc |
                  (((int)uStack_40 >> 0x1f) * 0x1800 + (int)((ulonglong)uStack_40 * 0x1800 >> 0x20))
                  * 0x100000;
      uStack_30 = (uint)((ulonglong)uStack_3c * 0x1800) >> 0xc |
                  (((int)uStack_3c >> 0x1f) * 0x1800 + (int)((ulonglong)uStack_3c * 0x1800 >> 0x20))
                  * 0x100000;
      uStack_2c = (uint)((ulonglong)uStack_38 * 0x1800) >> 0xc |
                  (((int)uStack_38 >> 0x1f) * 0x1800 + (int)((ulonglong)uStack_38 * 0x1800 >> 0x20))
                  * 0x100000;
      func_020f6be8(param_1,param_3,(uint)(uintptr_t)(&uStack_34),(uint)(uintptr_t)(&uStack_40));
    }
    else {
      func_020f6be8(param_1,param_3,param_4,(uint)(uintptr_t)(&uStack_40));
    }
    if ((uVar11 == 0xffffffff) ||
       (uVar12 = param_1 + 0x74U & 3, uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
       ((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) & 0x8000000) != 0)) {
      func_020f6fc4(param_1,1);
    }
    else {
      uVar12 = param_1 + 0x44U & 3;
      uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar12 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
      func_020f7104(param_1,1);
      if ((uVar12 == 5) || (uVar12 == 9)) {
        uVar11 = 0xffffffff;
      }
    }
  }
  if (uVar11 == 0xffffffff) {
    return;
  }
  uVar12 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  pcVar8 = pcRam020f7c58;
  if (((uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20) & 0x400000) == 0) {
    pcVar8 = pcRam020f7c5c;
  }
  (*pcVar8)(param_1,uVar11);
  return;
}

