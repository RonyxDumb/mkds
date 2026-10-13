/* Decompiled C draft; module arm9; ROM address 0214049c. No matching claim. */
#include "types.h"
#include "deps/0214049c_func_0214049c.h"

double func_0214049c(undefined2 *param_1)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  bool bVar21;
  bool bVar22;
  double dVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined4 in_stack_fffffec0;
  undefined4 in_stack_fffffec4;
  int iVar27;
  undefined4 in_stack_fffffec8;
  undefined4 in_stack_fffffecc;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  uint local_120;
  undefined4 local_10c;
  undefined1 local_108 [2];
  uint auStack_106 [8];
  undefined1 auStack_e6 [38];
  undefined2 auStack_c0 [19];
  undefined2 auStack_9a [19];
  undefined2 auStack_74 [19];
  undefined1 auStack_4e [42];
  
  uVar6 = (uint)(param_1 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xff) == 0) {
    dVar23 = copysign((double)CONCAT44(in_stack_fffffec4,in_stack_fffffec0),
                      (double)CONCAT44(in_stack_fffffecc,in_stack_fffffec8));
    return dVar23;
  }
  uVar6 = (int)param_1 + 5U & 3;
  uVar5 = *(uint *)((int)param_1 + 5U & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xff;
  if (uVar6 == 0x30) {
    dVar23 = copysign((double)CONCAT44(in_stack_fffffec4,in_stack_fffffec0),
                      (double)CONCAT44(in_stack_fffffecc,in_stack_fffffec8));
    return dVar23;
  }
  if (uVar6 == 0x49) {
    func_02132200(*(uint *)(uRam02140c0c & 0xfffffffc) >> (uRam02140c0c & 3) * 8 |
                  *(uint *)(uRam02140c0c & 0xfffffffc) << (uRam02140c0c & 3) * -8 + 0x20);
    dVar23 = copysign((double)CONCAT44(in_stack_fffffec4,in_stack_fffffec0),
                      (double)CONCAT44(in_stack_fffffecc,in_stack_fffffec8));
    return dVar23;
  }
  if (uVar6 == 0x4e) {
    local_130 = uRam02140c10;
    if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) != 0) {
      local_130 = uRam02140c10 | 0x80000000;
    }
    return (double)((ulonglong)local_130 << 0x20 | 0x8000000000000);
  }
  puVar12 = &local_10c;
  iVar8 = 9;
  do {
    puVar13 = param_1 + 1;
    uVar2 = *param_1;
    param_1 = param_1 + 2;
    uVar3 = *puVar13;
    iVar8 = iVar8 + -1;
    puVar13 = (undefined2 *)((int)puVar12 + 2);
    *(undefined2 *)puVar12 = uVar2;
    puVar12 = puVar12 + 1;
    *puVar13 = uVar3;
  } while (iVar8 != 0);
  puVar9 = (uint *)(local_108 + 1);
  *(undefined2 *)puVar12 = *param_1;
  puVar19 = (uint *)((int)puVar9 + (_local_108 & 0xff));
  for (; puVar9 < puVar19; puVar9 = (uint *)((int)puVar9 + 1)) {
    uVar5 = ((*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
             *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xff) - 0x30
            & 0xff | (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
                     *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) &
                     0xffffff00;
    uVar6 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
  }
  sVar4 = MKDS_SLICE_2(local_10c,2) + (((ushort)_local_108 & 0xff) - 1);
  local_10c = CONCAT22(sVar4,(undefined2)local_10c);
  iVar20 = (int)sVar4;
  func_02141b5c(auStack_e6,uRam02140c14,0x134);
  iVar8 = func_02141538(auStack_e6,&local_10c);
  if (iVar8 != 0) {
    func_02132200(*(uint *)(uRam02140c0c & 0xfffffffc) >> (uRam02140c0c & 3) * 8 |
                  *(uint *)(uRam02140c0c & 0xfffffffc) << (uRam02140c0c & 3) * -8 + 0x20);
    dVar23 = copysign((double)CONCAT44(in_stack_fffffec4,in_stack_fffffec0),
                      (double)CONCAT44(in_stack_fffffecc,in_stack_fffffec8));
    return dVar23;
  }
  puVar9 = (uint *)(local_108 + 2);
  uVar24 = func_02130304((_local_108 >> ((uint)(local_108 + 1) & 3) * 8 |
                         _local_108 << ((uint)(local_108 + 1) & 3) * -8 + 0x20) & 0xff);
  if (puVar9 < puVar19) {
    iVar27 = 8;
    iVar8 = 0;
    do {
      local_128 = (uint)((ulonglong)uVar24 >> 0x20);
      local_12c = (uint)uVar24;
      iVar17 = (int)puVar19 - (int)puVar9 >> 0x1f;
      iVar17 = ((uint)(((int)puVar19 - (int)puVar9) * 0x20000000 + iVar17) >> 0x1d | iVar17 << 3) -
               iVar17;
      if (iVar17 == 0) {
        iVar17 = iVar27;
      }
      iVar10 = iVar8;
      iVar18 = iVar8;
      if (0 < iVar17) {
        do {
          iVar10 = iVar10 + 1;
          iVar18 = iVar18 * 10 +
                   ((*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
                    *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xff);
          puVar9 = (uint *)((int)puVar9 + 1);
        } while (iVar10 < iVar17);
      }
      uVar6 = iRam02140c18 + (iVar17 + -1) * 8;
      uVar5 = uVar6 & 3;
      uVar11 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = iRam02140c18 + (iVar17 + -1) * 8 + 4;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar25 = func_02130380(local_12c,local_128,uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20,
                             uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
      uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
      uVar26 = func_02130304(iVar18);
      uVar26 = func_0212f884((int)uVar25,uVar7,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
    } while (((iVar18 == 0) ||
             (iVar10 = FUN_02131bfc((int)uVar25,uVar7,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20)),
             iVar10 == 0)) && (iVar20 = iVar20 - iVar17, uVar24 = uVar26, puVar9 < puVar19));
  }
  local_128 = (uint)((ulonglong)uVar24 >> 0x20);
  local_12c = (uint)uVar24;
  if (iVar20 < 0) {
    uVar24 = _dflt(-iVar20);
    uVar24 = func_02140490(0,uRam02140c1c,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
    uVar24 = FUN_021334a0(local_12c,local_128,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
  }
  else {
    uVar24 = _dflt(iVar20);
    uVar24 = func_02140490(0,uRam02140c1c,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
    uVar24 = func_02130380(local_12c,local_128,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
  }
  local_128 = (uint)((ulonglong)uVar24 >> 0x20);
  local_12c = (uint)uVar24;
  dVar23 = (double)func_021401ac(local_12c,local_128,iVar20);
  uVar6 = (uint)((ulonglong)dVar23 >> 0x20);
  if ((uVar6 & uRam02140c10) == 0) {
    if (((uVar6 & uRam02140c20) == 0) && (SUB84(dVar23,0) == 0)) {
      iVar8 = 3;
    }
    else {
      iVar8 = 5;
    }
  }
  else if ((uVar6 & uRam02140c10) == uRam02140c10) {
    if (((uVar6 & uRam02140c20) == 0) && (SUB84(dVar23,0) == 0)) {
      iVar8 = 2;
    }
    else {
      iVar8 = 1;
    }
  }
  else {
    iVar8 = 4;
  }
  if (iVar8 == 2) {
    dVar23 = (double)CONCAT44(uRam02140c24,0xffffffff);
  }
  local_128 = (uint)((ulonglong)dVar23 >> 0x20);
  local_12c = SUB84(dVar23,0);
  func_02140d74(auStack_c0,local_12c,local_128);
  iVar8 = func_0214166c(auStack_c0,&local_10c);
  if (iVar8 == 0) {
    iVar8 = func_02141538(auStack_c0,&local_10c);
    bVar21 = iVar8 != 0;
    local_120 = local_128;
    local_124 = local_12c;
    iVar8 = 4;
    while( true ) {
      uVar5 = local_120;
      uVar6 = local_124;
      dVar23 = (double)CONCAT44(local_120,local_124);
      if (bVar21) {
        bVar22 = 0xfffffffe < local_124;
        local_124 = local_124 + 1;
        local_120 = local_120 + bVar22;
        if ((local_120 & uRam02140c10) == 0) {
          if (((local_120 & uRam02140c20) == 0) && (local_124 == 0)) {
            iVar20 = 3;
          }
          else {
            iVar20 = 5;
          }
        }
        else {
          iVar20 = iVar8;
          if ((local_120 & uRam02140c10) == uRam02140c10) {
            if (((local_120 & uRam02140c20) == 0) && (local_124 == 0)) {
              iVar20 = 2;
            }
            else {
              iVar20 = 1;
            }
          }
        }
        if (iVar20 == 2) goto LAB_02140bc8;
      }
      else {
        bVar22 = local_124 == 0;
        local_124 = local_124 - 1;
        local_120 = local_120 - bVar22;
      }
      func_02140d74(auStack_9a,local_124,local_120);
      if ((bVar21) &&
         (iVar20 = func_02141538(auStack_9a,&local_10c), local_12c = uVar6, local_128 = uVar5,
         iVar20 == 0)) goto LAB_02140b44;
      if ((!bVar21) && (iVar20 = func_02141538(&local_10c,auStack_9a), iVar20 == 0)) break;
      puVar16 = auStack_9a;
      puVar13 = auStack_c0;
      iVar20 = 9;
      do {
        puVar14 = puVar16 + 1;
        uVar2 = *puVar16;
        puVar16 = puVar16 + 2;
        uVar3 = *puVar14;
        iVar20 = iVar20 + -1;
        puVar14 = puVar13 + 1;
        *puVar13 = uVar2;
        puVar13 = puVar13 + 2;
        *puVar14 = uVar3;
      } while (iVar20 != 0);
      *puVar13 = *puVar16;
    }
    puVar13 = auStack_c0;
    puVar16 = auStack_74;
    iVar8 = 9;
    do {
      puVar14 = puVar13 + 1;
      uVar2 = *puVar13;
      puVar13 = puVar13 + 2;
      uVar3 = *puVar14;
      iVar8 = iVar8 + -1;
      puVar14 = puVar16 + 1;
      *puVar16 = uVar2;
      puVar16 = puVar16 + 2;
      *puVar14 = uVar3;
    } while (iVar8 != 0);
    puVar14 = auStack_9a;
    puVar15 = auStack_c0;
    *puVar16 = *puVar13;
    iVar8 = 9;
    do {
      puVar13 = puVar14 + 1;
      uVar2 = *puVar14;
      puVar14 = puVar14 + 2;
      uVar3 = *puVar13;
      iVar8 = iVar8 + -1;
      puVar13 = puVar15 + 1;
      *puVar15 = uVar2;
      puVar15 = puVar15 + 2;
      *puVar13 = uVar3;
    } while (iVar8 != 0);
    puVar13 = auStack_74;
    puVar16 = auStack_9a;
    *puVar15 = *puVar14;
    iVar8 = 9;
    do {
      puVar14 = puVar13 + 1;
      uVar2 = *puVar13;
      puVar13 = puVar13 + 2;
      uVar3 = *puVar14;
      iVar8 = iVar8 + -1;
      puVar14 = puVar16 + 1;
      *puVar16 = uVar2;
      puVar16 = puVar16 + 2;
      *puVar14 = uVar3;
    } while (iVar8 != 0);
    local_12c = local_124;
    local_128 = local_120;
    *puVar16 = *puVar13;
    local_124 = uVar6;
    local_120 = uVar5;
LAB_02140b44:
    dVar23 = (double)CONCAT44(local_128,local_12c);
    func_021410bc(auStack_74,&local_10c,auStack_c0);
    func_021410bc(auStack_4e,auStack_9a,&local_10c);
    iVar8 = func_0214166c(auStack_74,auStack_4e);
    if (iVar8 == 0) {
      iVar8 = func_02141538(auStack_74,auStack_4e);
      dVar23 = (double)CONCAT44(local_128,local_12c);
      if (iVar8 == 0) {
        dVar23 = (double)CONCAT44(local_120,local_124);
      }
    }
    else if ((local_12c & 1) != 0) {
      dVar23 = (double)CONCAT44(local_120,local_124);
    }
  }
LAB_02140bc8:
  local_128 = (uint)((ulonglong)dVar23 >> 0x20);
  local_12c = SUB84(dVar23,0);
  if ((local_10c & 0xff) != 0) {
    dVar23 = (double)func_02130ccc(0,0,local_12c,local_128);
  }
  return dVar23;
}

