/* Decompiled C draft; module arm9; ROM address 020fa4c8. No matching claim. */
#include "types.h"
#include "deps/020fa4c8_func_020fa4c8.h"

int func_020fa4c8(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int unaff_r8;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  int local_44;
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined1 auStack_34 [4];
  undefined4 local_30;
  
  uVar10 = param_1 + 0x48U & 3;
  uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  iVar11 = 0;
  bVar17 = ((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) & 0x8000000) != 0;
  if (bVar17) {
    unaff_r8 = 1;
  }
  if (!bVar17) {
    unaff_r8 = 0;
  }
  iVar12 = 0;
  if (0 < *psRam020fa774) {
    local_44 = 0xf;
    do {
      if (((*(ushort *)
             ((*(uint *)(uRam020fa778 & 0xfffffffc) >> (uRam020fa778 & 3) * 8 |
              *(uint *)(uRam020fa778 & 0xfffffffc) << (uRam020fa778 & 3) * -8 + 0x20) + iVar12 * 2)
           & 0x4000) != 0) &&
         (((uVar10 = (*(uint *)(uRam020fa77c & 0xfffffffc) >> (uRam020fa77c & 3) * 8 |
                     *(uint *)(uRam020fa77c & 0xfffffffc) << (uRam020fa77c & 3) * -8 + 0x20) +
                     iVar12 * 4, uVar4 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
           uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20, unaff_r8 == 0 ||
           (uVar4 = uVar10 + 0x74 & 3, uVar5 = *(uint *)(uVar10 + 0x74 & 0xfffffffc),
           ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x200000) != 0)) &&
          (iVar6 = func_020f97e0(uVar10,param_1), iVar6 != 0)))) {
        uVar4 = uVar10 + 0x74 & 3;
        uVar5 = *(uint *)(uVar10 + 0x74 & 0xfffffffc);
        if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x8000) == 0) {
          bVar17 = true;
        }
        else {
          if ((*(ushort *)(uVar10 + 0x78) & 0x8000) == 0) {
            uVar3 = *(ushort *)(uVar10 + 0x78) & 0xff;
          }
          else {
            uVar3 = 8;
          }
          if (*(ushort *)(param_1 + 0x74) == uVar3) {
            uVar4 = uVar10 + 0x5c & 3;
            uVar5 = *(uint *)(uVar10 + 0x5c & 0xfffffffc);
            if (((uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) ||
                (uVar4 = uVar10 + 0x60 & 3, uVar5 = *(uint *)(uVar10 + 0x60 & 0xfffffffc),
                uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0)) ||
               ((uVar4 = uVar10 + 100 & 3, uVar5 = *(uint *)(uVar10 + 100 & 0xfffffffc),
                uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0 ||
                (uVar4 = param_1 + 0x2a8U & 3, uVar5 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc),
                uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0)))) {
              VecFx32_Subtract(uVar10 + 0xe4,param_1 + 0x1e4,(int *)(void *)(auStack_40));
              local_3c = 0;
              VecFx32_Subtract(uVar10 + 0x50,param_1 + 0x1d8,(int *)(void *)(auStack_34));
              local_30 = 0;
              iVar6 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_40),(uint)(uintptr_t)(auStack_40));
              iVar7 = VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_34),(uint)(uintptr_t)(auStack_34));
              if (iVar7 < iVar6 + -0x1000) {
                bVar17 = true;
                goto LAB_020fa674;
              }
            }
            uVar4 = uVar10 + 0xe0 & 3;
            uVar5 = *(uint *)(uVar10 + 0xe0 & 0xfffffffc);
            uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
            uVar4 = uVar10 + 0x50 & 3;
            uVar13 = *(uint *)(uVar10 + 0x50 & 0xfffffffc);
            lVar2 = (longlong)(int)uVar5 * (longlong)(int)uVar5;
            iVar6 = (int)((ulonglong)lVar2 >> 0x20);
            uVar5 = param_1 + 0x1d8U & 3;
            uVar8 = *(uint *)(param_1 + 0x1d8U & 0xfffffffc);
            uVar14 = uVar10 + 0x54 & 3;
            uVar9 = *(uint *)(uVar10 + 0x54 & 0xfffffffc);
            iVar7 = (uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20) -
                    (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
            uVar4 = param_1 + 0x1dcU & 3;
            uVar8 = *(uint *)(param_1 + 0x1dcU & 0xfffffffc);
            uVar5 = uVar10 + 0x58 & 3;
            uVar13 = *(uint *)(uVar10 + 0x58 & 0xfffffffc);
            iVar16 = (uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) -
                     (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
            uVar4 = param_1 + 0x1e0U & 3;
            uVar14 = *(uint *)(param_1 + 0x1e0U & 0xfffffffc);
            iVar15 = (uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20) -
                     (uVar14 >> uVar4 * 8 | uVar14 << uVar4 * -8 + 0x20);
            lVar1 = (longlong)iVar15 * (longlong)iVar15 +
                    (longlong)iVar7 * (longlong)iVar7 + (longlong)iVar16 * (longlong)iVar16;
            iVar7 = (int)((ulonglong)lVar1 >> 0x20);
            bVar18 = (uint)lVar1 < (uint)lVar2;
            bVar17 = false;
            if ((int)(iVar7 - (iVar6 + (uint)bVar18)) < 0 !=
                (SBORROW4(iVar7,iVar6) != SBORROW4(iVar7 - iVar6,(uint)bVar18))) {
              bVar17 = true;
            }
          }
          else {
            bVar17 = true;
          }
        }
LAB_020fa674:
        if ((bVar17) &&
           ((uVar4 = param_1 + 0x7cU & 3, uVar5 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
            ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x2000) == 0 ||
            (iVar6 = func_020f9880(uVar10), iVar6 == 0)))) {
          iVar6 = iVar11 + 1;
          *(uint *)((*(uint *)(uRam020fa780 & 0xfffffffc) >> (uRam020fa780 & 3) * 8 |
                    *(uint *)(uRam020fa780 & 0xfffffffc) << (uRam020fa780 & 3) * -8 + 0x20) +
                   iVar11 * 4) = uVar10;
          uVar4 = uVar10 + 0x74 & 3;
          uVar5 = *(uint *)(uVar10 + 0x74 & 0xfffffffc);
          if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0x1000) != 0) {
            func_020eda5c((*(ushort *)(uVar10 + 0x78) & 0xffff00ff) * 0x210 +
                          (*(uint *)(uRam020fa784 & 0xfffffffc) >> (uRam020fa784 & 3) * 8 |
                          *(uint *)(uRam020fa784 & 0xfffffffc) << (uRam020fa784 & 3) * -8 + 0x20) +
                          0x58,uVar10);
          }
          uVar4 = uVar10 + 0x44 & 3;
          uVar5 = *(uint *)(uVar10 + 0x44 & 0xfffffffc);
          uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) * 0xa8 +
                  (*(uint *)(uRam020fa788 & 0xfffffffc) >> (uRam020fa788 & 3) * 8 |
                  *(uint *)(uRam020fa788 & 0xfffffffc) << (uRam020fa788 & 3) * -8 + 0x20) + 0x88;
          uVar5 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
            iVar11 = func_020f9880(uVar10);
            if (iVar11 == 0) {
              func_020f7430(uVar10,1);
            }
            else {
              func_020f6be8(uVar10,param_1 + 0x1b8,param_1 + 0xa4,param_1 + 0x5c);
              func_020f6f10(uVar10,1,*(undefined2 *)(param_1 + 0x74));
            }
          }
          iVar11 = iVar6;
          if (0xf < iVar6) {
            iVar11 = local_44;
          }
        }
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < *psRam020fa774);
  }
  return iVar11;
}

