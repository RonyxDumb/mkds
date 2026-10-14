/* Decompiled C draft; module arm9; ROM address 0214755c. No matching claim. */
#include "types.h"
#include "deps/0214755c_func_0214755c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_0214755c(uint *param_1,uint *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  uint uVar9;
  uint uVar11;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *unaff_r9;
  uint uVar17;
  uint uVar19;
  uint uVar20;
  uint uStack_6c;
  int iStack_68;
  uint auStack_54 [12];
  uint uVar10;
  uint uVar12;
  uint uVar18;
  
  uVar18 = (uint)(param_1 + 5) & 3;
  uVar17 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  uVar18 = uVar17 >> uVar18 * 8 | uVar17 << uVar18 * -8 + 0x20;
  if (param_1 == param_2) {
    unaff_r9 = auStack_54;
  }
  uVar17 = (uint)(param_1 + 6) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  uVar10 = uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20;
  uVar17 = (uint)(param_1 + 3) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar9 = uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20;
  uVar17 = (uint)(param_1 + 8) & 3;
  uVar16 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar17 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
  if (param_1 != param_2) {
    unaff_r9 = param_2;
  }
  lVar2 = (longlong)(int)uVar9 * (longlong)(int)uVar17;
  uVar14 = (uint)lVar2;
  lVar3 = (longlong)(int)uVar18 * (longlong)(int)uVar10;
  uVar13 = (uint)lVar3;
  uVar16 = (uint)(param_1 + 7) & 3;
  uVar11 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
  uVar12 = uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20;
  uVar19 = uVar14 - uVar13;
  uVar16 = (uint)(param_1 + 4) & 3;
  uVar11 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar16 = uVar11 >> uVar16 * 8 | uVar11 << uVar16 * -8 + 0x20;
  lVar4 = (longlong)(int)uVar18 * (longlong)(int)uVar12;
  uVar18 = (uint)lVar4;
  lVar5 = (longlong)(int)uVar9 * (longlong)(int)uVar12;
  uVar11 = (uint)lVar5;
  lVar6 = (longlong)(int)uVar16 * (longlong)(int)uVar17;
  uVar17 = (uint)lVar6;
  lVar7 = (longlong)(int)uVar16 * (longlong)(int)uVar10;
  uVar10 = (uint)lVar7;
  uVar9 = uVar17 - uVar18;
  uVar15 = uVar9 + 0x800 >> 0xc |
           (((int)((ulonglong)lVar6 >> 0x20) -
            ((int)((ulonglong)lVar4 >> 0x20) + (uint)(uVar17 < uVar18))) +
           (uint)(0xfffff7ff < uVar9)) * 0x100000;
  uVar13 = uVar19 + 0x800 >> 0xc |
           (((int)((ulonglong)lVar2 >> 0x20) -
            ((int)((ulonglong)lVar3 >> 0x20) + (uint)(uVar14 < uVar13))) +
           (uint)(0xfffff7ff < uVar19)) * 0x100000;
  uVar17 = uVar11 - uVar10;
  uVar18 = (uint)(param_1 + 1) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20) * (longlong)(int)uVar13
  ;
  uVar16 = (uint)lVar2;
  lVar3 = (longlong)
          (int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) *
          (longlong)(int)uVar15;
  uVar12 = (uint)lVar3;
  uVar18 = (uint)(param_1 + 2) & 3;
  uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar17 = uVar17 + 0x800 >> 0xc |
           (((int)((ulonglong)lVar5 >> 0x20) -
            ((int)((ulonglong)lVar7 >> 0x20) + (uint)(uVar11 < uVar10))) +
           (uint)(0xfffff7ff < uVar17)) * 0x100000;
  lVar2 = (longlong)(int)uVar17 * (longlong)(int)(uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20)
          + CONCAT44((int)((ulonglong)lVar3 >> 0x20) -
                     ((int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar12 < uVar16)),uVar12 - uVar16) +
          0x800;
  uVar18 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  if (uVar18 != 0) {
    FX_InvAsync(uVar18);
    uVar18 = (uint)(param_1 + 2) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    uVar16 = uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20;
    uVar18 = (uint)(param_1 + 7) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    uVar9 = (uint)(param_1 + 4) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20) *
            (longlong)(int)uVar16;
    uVar10 = (uint)lVar2;
    lVar3 = (longlong)(int)(uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) *
            (longlong)(int)uVar16;
    uVar18 = (uint)(param_1 + 6) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20) *
            (longlong)(int)uVar16;
    uVar12 = (uint)lVar4;
    uVar18 = (uint)(param_1 + 8) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    uVar9 = uVar9 >> uVar18 * 8 | uVar9 << uVar18 * -8 + 0x20;
    uVar18 = (uint)(param_1 + 1) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    uVar20 = uVar11 >> uVar18 * 8 | uVar11 << uVar18 * -8 + 0x20;
    lVar5 = (longlong)(int)uVar20 * (longlong)(int)uVar9;
    uVar19 = (uint)lVar5;
    uVar18 = (uint)(param_1 + 3) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    lVar6 = (longlong)(int)(uVar11 >> uVar18 * 8 | uVar11 << uVar18 * -8 + 0x20) *
            (longlong)(int)uVar16;
    uVar16 = (uint)lVar6;
    uVar18 = (uint)(param_1 + 5) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
    uVar14 = uVar11 >> uVar18 * 8 | uVar11 << uVar18 * -8 + 0x20;
    lVar7 = (longlong)(int)uVar20 * (longlong)(int)uVar14;
    uVar11 = (uint)lVar7;
    uStack_6c = (uint)lVar3;
    uVar18 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    iStack_68 = (int)((ulonglong)lVar3 >> 0x20);
    lVar3 = (longlong)(int)uVar18 * (longlong)(int)uVar9;
    uVar20 = (uint)lVar3;
    lVar8 = (longlong)(int)uVar18 * (longlong)(int)uVar14;
    uVar18 = (uint)lVar8;
    uVar9 = FX_GetDivResult();
    lVar2 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar19 - uVar10 >> 0xc |
                 ((int)((ulonglong)lVar5 >> 0x20) -
                 ((int)((ulonglong)lVar2 >> 0x20) + (uint)(uVar19 < uVar10))) * 0x100000);
    lVar5 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar11 - uStack_6c >> 0xc |
                 ((int)((ulonglong)lVar7 >> 0x20) - (iStack_68 + (uint)(uVar11 < uStack_6c))) *
                 0x100000);
    lVar3 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar20 - uVar12 >> 0xc |
                 ((int)((ulonglong)lVar3 >> 0x20) -
                 ((int)((ulonglong)lVar4 >> 0x20) + (uint)(uVar20 < uVar12))) * 0x100000);
    lVar4 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar18 - uVar16 >> 0xc |
                 ((int)((ulonglong)lVar8 >> 0x20) -
                 ((int)((ulonglong)lVar6 >> 0x20) + (uint)(uVar18 < uVar16))) * 0x100000);
    iVar1 = (int)uVar9 >> 0x1f;
    *unaff_r9 = (uint)((ulonglong)uVar15 * (ulonglong)uVar9) >> 0xc |
                (iVar1 * uVar15 +
                uVar9 * ((int)uVar15 >> 0x1f) + (int)((ulonglong)uVar15 * (ulonglong)uVar9 >> 0x20))
                * 0x100000;
    unaff_r9[1] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    unaff_r9[2] = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14;
    unaff_r9[3] = -((uint)((ulonglong)uVar13 * (ulonglong)uVar9) >> 0xc |
                   (iVar1 * uVar13 +
                   uVar9 * ((int)uVar13 >> 0x1f) +
                   (int)((ulonglong)uVar13 * (ulonglong)uVar9 >> 0x20)) * 0x100000);
    unaff_r9[4] = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    unaff_r9[5] = -((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
    unaff_r9[6] = (uint)((ulonglong)uVar17 * (ulonglong)uVar9) >> 0xc |
                  (iVar1 * uVar17 +
                  uVar9 * ((int)uVar17 >> 0x1f) +
                  (int)((ulonglong)uVar17 * (ulonglong)uVar9 >> 0x20)) * 0x100000;
    uVar18 = (uint)(param_1 + 7) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    uVar17 = (uint)(param_1 + 6) & 3;
    uVar16 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    lVar2 = (longlong)
            (int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20);
    uVar11 = (uint)lVar2;
    uVar18 = (uint)(param_1 + 1) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20);
    uVar18 = (uint)lVar3;
    lVar2 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar11 - uVar18 >> 0xc |
                 ((int)((ulonglong)lVar2 >> 0x20) -
                 ((int)((ulonglong)lVar3 >> 0x20) + (uint)(uVar11 < uVar18))) * 0x100000);
    unaff_r9[7] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar18 = (uint)(param_1 + 4) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    uVar17 = (uint)(param_1 + 3) & 3;
    uVar16 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
    lVar2 = (longlong)
            (int)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                 *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20);
    uVar11 = (uint)lVar2;
    uVar18 = (uint)(param_1 + 1) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    lVar3 = (longlong)(int)(uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20) *
            (longlong)(int)(uVar10 >> uVar18 * 8 | uVar10 << uVar18 * -8 + 0x20);
    uVar18 = (uint)lVar3;
    lVar2 = (longlong)(int)uVar9 *
            (longlong)
            (int)(uVar11 - uVar18 >> 0xc |
                 ((int)((ulonglong)lVar2 >> 0x20) -
                 ((int)((ulonglong)lVar3 >> 0x20) + (uint)(uVar11 < uVar18))) * 0x100000);
    unaff_r9[8] = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar18 = (uint)(unaff_r9 + 3) & 3;
    uVar12 = *(uint *)((uint)(unaff_r9 + 3) & 0xfffffffc);
    uVar17 = (uint)(param_1 + 10) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    uVar9 = (uint)(param_1 + 9) & 3;
    uVar13 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
    uVar10 = (uint)(unaff_r9 + 6) & 3;
    uVar15 = *(uint *)((uint)(unaff_r9 + 6) & 0xfffffffc);
    uVar16 = (uint)(param_1 + 0xb) & 3;
    uVar14 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar14 >> uVar16 * 8 | uVar14 << uVar16 * -8 + 0x20) *
            (longlong)(int)(uVar15 >> uVar10 * 8 | uVar15 << uVar10 * -8 + 0x20) +
            (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)
            (int)(*(uint *)((uint)unaff_r9 & 0xfffffffc) >> ((uint)unaff_r9 & 3) * 8 |
                 *(uint *)((uint)unaff_r9 & 0xfffffffc) << ((uint)unaff_r9 & 3) * -8 + 0x20) +
            (longlong)(int)(uVar12 >> uVar18 * 8 | uVar12 << uVar18 * -8 + 0x20) *
            (longlong)(int)(uVar11 >> uVar17 * 8 | uVar11 << uVar17 * -8 + 0x20);
    unaff_r9[9] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar18 = (uint)(unaff_r9 + 4) & 3;
    uVar13 = *(uint *)((uint)(unaff_r9 + 4) & 0xfffffffc);
    uVar17 = (uint)(param_1 + 10) & 3;
    uVar12 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    uVar9 = (uint)(unaff_r9 + 1) & 3;
    uVar15 = *(uint *)((uint)(unaff_r9 + 1) & 0xfffffffc);
    uVar10 = (uint)(param_1 + 9) & 3;
    uVar14 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
    uVar16 = (uint)(unaff_r9 + 7) & 3;
    uVar20 = *(uint *)((uint)(unaff_r9 + 7) & 0xfffffffc);
    uVar11 = (uint)(param_1 + 0xb) & 3;
    uVar19 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar19 >> uVar11 * 8 | uVar19 << uVar11 * -8 + 0x20) *
            (longlong)(int)(uVar20 >> uVar16 * 8 | uVar20 << uVar16 * -8 + 0x20) +
            (longlong)(int)(uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) *
            (longlong)(int)(uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) +
            (longlong)(int)(uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) *
            (longlong)(int)(uVar12 >> uVar17 * 8 | uVar12 << uVar17 * -8 + 0x20);
    unaff_r9[10] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar18 = (uint)(param_1 + 10) & 3;
    uVar12 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    uVar17 = (uint)(unaff_r9 + 5) & 3;
    uVar13 = *(uint *)((uint)(unaff_r9 + 5) & 0xfffffffc);
    uVar9 = (uint)(unaff_r9 + 2) & 3;
    uVar15 = *(uint *)((uint)(unaff_r9 + 2) & 0xfffffffc);
    uVar10 = (uint)(param_1 + 9) & 3;
    uVar14 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
    uVar16 = (uint)(unaff_r9 + 8) & 3;
    uVar20 = *(uint *)((uint)(unaff_r9 + 8) & 0xfffffffc);
    uVar11 = (uint)(param_1 + 0xb) & 3;
    uVar19 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar19 >> uVar11 * 8 | uVar19 << uVar11 * -8 + 0x20) *
            (longlong)(int)(uVar20 >> uVar16 * 8 | uVar20 << uVar16 * -8 + 0x20) +
            (longlong)(int)(uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) *
            (longlong)(int)(uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) +
            (longlong)(int)(uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20) *
            (longlong)(int)(uVar12 >> uVar18 * 8 | uVar12 << uVar18 * -8 + 0x20);
    unaff_r9[0xb] = -((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    if (unaff_r9 == auStack_54) {
      asm_MI_Copy48B(auStack_54,param_2);
    }
    return 0;
  }
  return 0xffffffff;
}

