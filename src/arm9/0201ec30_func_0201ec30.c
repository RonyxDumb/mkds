/* Decompiled C draft; module arm9; ROM address 0201ec30. No matching claim. */
#include "types.h"
#include "deps/0201ec30_func_0201ec30.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

char func_0201ec30(void)

{
  bool bVar1;
  char cVar2;
  byte *pbVar3;
  int *piVar4;
  int *piVar5;
  uint *puVar6;
  char *pcVar7;
  uint uVar8;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int local_54;
  int local_50;
  uint uStack_4c;
  uint local_48;
  int local_44;
  int local_40;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint uVar9;
  uint uVar18;
  
  iVar16 = 0;
  uVar8 = (*(uint *)(uRam0201fc08 & 0xfffffffc) >> (uRam0201fc08 & 3) * 8 |
          *(uint *)(uRam0201fc08 & 0xfffffffc) << (uRam0201fc08 & 3) * -8 + 0x20) + 8;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  local_54 = 0;
  iVar15 = 0;
  local_48 = uRam0201fc10;
  local_40 = 2;
  local_50 = 0;
  local_44 = 0;
  uVar8 = 0;
  iVar22 = 0;
  if (*(uint *)(uRam0201fc0c & 0xfffffffc) >> (uRam0201fc0c & 3) * 8 == 0 &&
      *(uint *)(uRam0201fc0c & 0xfffffffc) << (uRam0201fc0c & 3) * -8 + 0x20 == 0) {
    return '\0';
  }
  puVar10 = (undefined1 *)func_0214f1a0();
  uVar17 = (*(uint *)(uRam0201fc08 & 0xfffffffc) >> (uRam0201fc08 & 3) * 8 |
           *(uint *)(uRam0201fc08 & 0xfffffffc) << (uRam0201fc08 & 3) * -8 + 0x20) + 4;
  uVar18 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  uVar18 = uVar17 >> uVar18 * 8 | uVar17 << uVar18 * -8 + 0x20;
  iVar19 = (int)(uVar9 + ((uint)((int)uVar9 >> 2) >> 0x1d)) >> 3;
  uVar17 = (int)puVar10 - uVar18 & 0xffff;
  if ((int)uVar17 < iVar19) {
    iVar19 = uVar9 - (iVar19 - uVar17);
    DC_InvalidateRangeNoClean(uVar18 + iVar19,uVar9 & 0xffff);
    uVar21 = uRam0201fc08;
    for (; iVar19 < (int)uVar9; iVar19 = iVar19 + 1) {
      uVar13 = uVar21 & 3;
      uVar11 = *(uint *)(uVar21 & 0xfffffffc);
      uVar11 = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
      uVar13 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (uVar11 >> uVar13 * 8 == 0 && uVar11 << uVar13 * -8 + 0x20 == 0) {
        func_020204b4(*(undefined1 *)(uVar18 + iVar19));
        iVar12 = func_02020498();
      }
      else {
        iVar12 = (int)*(char *)(uVar18 + iVar19);
        if (iVar12 < 0) {
          iVar12 = -iVar12;
        }
      }
      if (0x7c < iVar12) {
        iVar22 = iVar22 + 1;
      }
      if (iVar15 < iVar12) {
        iVar15 = iVar12;
      }
    }
    DC_InvalidateRangeNoClean(uVar18,uVar17);
    uVar21 = uRam0201fc08;
    iVar19 = 0;
    if (uVar17 != 0) {
      do {
        uVar13 = uVar21 & 3;
        uVar11 = *(uint *)(uVar21 & 0xfffffffc);
        uVar11 = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
        uVar13 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        if (uVar11 >> uVar13 * 8 == 0 && uVar11 << uVar13 * -8 + 0x20 == 0) {
          func_020204b4(*(undefined1 *)(uVar18 + iVar19));
          iVar12 = func_02020498();
        }
        else {
          iVar12 = (int)*(char *)(uVar18 + iVar19);
          if (iVar12 < 0) {
            iVar12 = -iVar12;
          }
        }
        if (0x7c < iVar12) {
          iVar22 = iVar22 + 1;
        }
        if (iVar15 < iVar12) {
          iVar15 = iVar12;
        }
        iVar19 = iVar19 + 1;
      } while (iVar19 < (int)uVar17);
    }
  }
  else {
    iVar19 = uVar17 - iVar19;
    DC_InvalidateRangeNoClean(uVar18 + iVar19,uVar17);
    uVar21 = uRam0201fc08;
    for (; iVar19 < (int)uVar17; iVar19 = iVar19 + 1) {
      uVar13 = uVar21 & 3;
      uVar11 = *(uint *)(uVar21 & 0xfffffffc);
      uVar11 = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
      uVar13 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (uVar11 >> uVar13 * 8 == 0 && uVar11 << uVar13 * -8 + 0x20 == 0) {
        func_020204b4(*(undefined1 *)(uVar18 + iVar19));
        iVar12 = func_02020498();
      }
      else {
        iVar12 = (int)*(char *)(uVar18 + iVar19);
        if (iVar12 < 0) {
          iVar12 = -iVar12;
        }
      }
      if (0x7c < iVar12) {
        iVar22 = iVar22 + 1;
      }
      if (iVar15 < iVar12) {
        iVar15 = iVar12;
      }
    }
  }
  iVar19 = 0;
  pbVar14 = pbRam0201fc14;
  do {
    *pbVar14 = 0;
    pbVar3 = pbRam0201fc14;
    iVar19 = iVar19 + 1;
    pbVar14 = pbVar14 + 1;
  } while (iVar19 < 4);
  uStack_4c = uVar9;
  if ((int)uVar17 < (int)uVar9) {
    iStack_30 = 0;
    uVar21 = uVar17;
    do {
      uVar11 = *(uint *)(uRam0201fc08 & 0xfffffffc) >> (uRam0201fc08 & 3) * 8 |
               *(uint *)(uRam0201fc08 & 0xfffffffc) << (uRam0201fc08 & 3) * -8 + 0x20;
      uVar13 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      if (uVar11 >> uVar13 * 8 == 0 && uVar11 << uVar13 * -8 + 0x20 == 0) {
        iVar19 = func_020204b4(*(undefined1 *)(uVar18 + uVar21));
      }
      else {
        iVar19 = *(char *)(uVar18 + uVar21) + 0x7f;
      }
      iVar12 = local_50;
      if (((0x1e < iVar15) && (iVar12 = iVar19, 0x7f < iVar19)) && (local_50 < 0x80)) {
        local_44 = local_44 + 1;
        if ((local_48 == uRam0201fc10) || (local_44 < 3)) {
          iVar16 = iVar16 + 1;
          local_48 = uVar21;
        }
        else {
          uVar13 = uVar21 - local_48;
          if ((int)uVar8 < (int)uVar13) {
            uVar8 = uVar13;
          }
          if ((int)uVar13 < (int)uStack_4c) {
            uStack_4c = uVar13;
          }
          iVar16 = iVar16 + 1;
          iVar19 = iStack_30;
          do {
            if (iVar19 == 4) {
              if (100 < (int)uVar13) {
                pbVar3[4] = pbVar3[4] + 1;
                iVar19 = 4;
              }
            }
            else if ((uVar13 != iVar19 * 0x19 &&
                      (int)(uVar13 + iVar19 * -0x19) < 0 == SBORROW4(uVar13,iVar19 * 0x19)) &&
                    (uVar11 = (iVar19 + 1) * 0x19,
                    uVar13 == uVar11 ||
                    (int)(uVar13 + (iVar19 + 1) * -0x19) < 0 != SBORROW4(uVar13,uVar11))) {
              pbVar3[iVar19] = pbVar3[iVar19] + 1;
              iVar19 = 4;
            }
            iVar19 = iVar19 + 1;
            local_48 = uVar21;
          } while (iVar19 < 4);
        }
      }
      local_50 = iVar12;
      uVar21 = uVar21 + 1;
    } while ((int)uVar21 < (int)uVar9);
  }
  pbVar14 = pbRam0201fc14;
  iVar19 = 0;
  iStack_34 = local_48 - uVar9;
  if (uVar17 != 0) {
    iStack_2c = 0;
    do {
      uVar13 = *(uint *)(uRam0201fc08 & 0xfffffffc) >> (uRam0201fc08 & 3) * 8 |
               *(uint *)(uRam0201fc08 & 0xfffffffc) << (uRam0201fc08 & 3) * -8 + 0x20;
      uVar21 = uVar13 & 3;
      uVar13 = *(uint *)(uVar13 & 0xfffffffc);
      if (uVar13 >> uVar21 * 8 == 0 && uVar13 << uVar21 * -8 + 0x20 == 0) {
        iVar12 = func_020204b4(*(undefined1 *)(uVar18 + iVar19));
      }
      else {
        iVar12 = *(char *)(uVar18 + iVar19) + 0x7f;
      }
      iVar20 = local_50;
      if (((0x1e < iVar15) && (iVar20 = iVar12, 0x7f < iVar12)) && (local_50 < 0x80)) {
        uVar21 = iVar19 - iStack_34;
        if ((int)uVar8 < (int)uVar21) {
          uVar8 = uVar21;
        }
        if ((int)uVar21 < (int)uStack_4c) {
          uStack_4c = uVar21;
        }
        iVar16 = iVar16 + 1;
        iVar12 = iStack_2c;
        do {
          if (iVar12 == 4) {
            if (100 < (int)uVar21) {
              pbVar14[4] = pbVar14[4] + 1;
              iVar12 = 4;
            }
          }
          else if ((uVar21 != iVar12 * 0x19 &&
                    (int)(uVar21 + iVar12 * -0x19) < 0 == SBORROW4(uVar21,iVar12 * 0x19)) &&
                  (uVar13 = (iVar12 + 1) * 0x19,
                  uVar21 == uVar13 ||
                  (int)(uVar21 + (iVar12 + 1) * -0x19) < 0 != SBORROW4(uVar21,uVar13))) {
            pbVar14[iVar12] = pbVar14[iVar12] + 1;
            iVar12 = 4;
          }
          iVar12 = iVar12 + 1;
          iStack_34 = iVar19;
        } while (iVar12 < 4);
      }
      local_50 = iVar20;
      iVar19 = iVar19 + 1;
    } while (iVar19 < (int)uVar17);
  }
  iVar12 = _s32_div_f(0x400,(int)((longlong)iRam0201fc18 * (longlong)(int)uVar9 >> 0x22) -
                            ((int)uVar9 >> 0x1f));
  iVar19 = iRam0201fc18;
  iVar16 = iVar16 * 8 * iVar12;
  iVar22 = (int)((longlong)iRam0201fc18 * (longlong)(iVar22 * iVar12) >> 0x22) -
           (iVar22 * iVar12 >> 0x1f);
  iVar16 = (int)((longlong)iRam0201fc18 * (longlong)iVar16 >> 0x22) - (iVar16 >> 0x1f);
  iVar20 = 0;
  pbVar14 = pbRam0201fc14;
  do {
    iVar20 = iVar20 + 1;
    *pbVar14 = (char)(int)((longlong)iVar19 * (longlong)(int)((uint)*pbVar14 * iVar12) >> 0x22) -
               (char)((int)((uint)*pbVar14 * iVar12) >> 0x1f);
    pcVar7 = pcRam0201fc2c;
    puVar6 = piRam0201fc28;
    piVar5 = piRam0201fc24;
    piVar4 = piRam0201fc20;
    pbVar14 = pbVar14 + 1;
  } while (iVar20 < 4);
  bVar1 = false;
  *piRam0201fc1c = iVar15;
  *piVar4 = iVar16;
  *piVar5 = iVar22;
  *puVar6 = uVar8;
  *pcVar7 = '\0';
  if (99 < iVar16) {
    uVar17 = *(uint *)(uRam0201fc08 & 0xfffffffc) >> (uRam0201fc08 & 3) * 8 |
             *(uint *)(uRam0201fc08 & 0xfffffffc) << (uRam0201fc08 & 3) * -8 + 0x20;
    uVar9 = uVar17 & 3;
    uVar17 = *(uint *)(uVar17 & 0xfffffffc);
    if (uVar17 >> uVar9 * 8 == 0 && uVar17 << uVar9 * -8 + 0x20 == 0) {
      func_020204b4(*puVar10);
      func_02020498();
    }
    local_54 = iVar16;
    if (iRam0201fc30 < iVar16) {
      local_54 = iRam0201fc30;
    }
    cVar2 = *pcRam0201fc34;
    if (cVar2 == '\0') {
      local_40 = 1;
      if ((iVar16 < 100) || (199 < iVar16)) {
        if ((iVar16 < 200) || (299 < iVar16)) {
          if ((iVar16 < 300) || (399 < iVar16)) {
            if ((iVar16 < 400) || (499 < iVar16)) {
              if ((iVar16 < 500) || (599 < iVar16)) {
                if ((iVar16 < 600) || (699 < iVar16)) {
                  if ((iVar16 < 700) || (799 < iVar16)) {
                    if ((iVar16 < 800) || (899 < iVar16)) {
                      if ((iVar16 < 900) || (iRam0201fc38 <= iVar16)) {
                        if ((iVar16 < iRam0201fc38) || (iRam0201fc3c <= iVar16)) {
                          if ((iVar16 < iRam0201fc3c) || (iRam0201fc40 <= iVar16)) {
                            if ((iVar16 < iRam0201fc40) || (iRam0201fc30 <= iVar16)) {
                              if ((((((iVar15 == 0x7f) && (pbRam0201fc14[1] == 0)) &&
                                    (pbRam0201fc14[2] == 0)) &&
                                   ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x65)))) &&
                                  (0x1c < (int)uVar8)) && (0x1b < iVar22)) {
                                bVar1 = true;
                              }
                            }
                            else if ((((iVar15 == 0x7f) && (0xb3 < *pbRam0201fc14)) &&
                                     ((pbRam0201fc14[1] < 3 &&
                                      (((pbRam0201fc14[2] == 0 && (pbRam0201fc14[3] == 0)) &&
                                       ((int)uVar8 < 0x65)))))) && (0x1b < (int)uVar8)) {
                              bVar1 = 0x1b < iVar22;
                            }
                          }
                          else if (((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xbf)) &&
                                  ((((0x95 < *pbRam0201fc14 &&
                                     ((pbRam0201fc14[1] < 3 && (pbRam0201fc14[2] == 0)))) &&
                                    (pbRam0201fc14[3] == 0)) &&
                                   (((int)uVar8 < 0x65 && (0x1f < (int)uVar8)))))) {
                            bVar1 = 0xe < iVar22;
                          }
                        }
                        else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xaa)) &&
                                 (0x77 < *pbRam0201fc14)) &&
                                (((pbRam0201fc14[1] < 5 && (pbRam0201fc14[2] < 2)) &&
                                 ((pbRam0201fc14[3] == 0 &&
                                  (((int)uVar8 < 0x65 && (0x1f < (int)uVar8)))))))) {
                          bVar1 = 8 < iVar22;
                        }
                      }
                      else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xa1)) &&
                                (0x59 < *pbRam0201fc14)) &&
                               ((pbRam0201fc14[1] < 8 && (pbRam0201fc14[2] < 2)))) &&
                              ((pbRam0201fc14[3] == 0 &&
                               (((int)uVar8 < 0x74 && (0x13 < (int)uVar8)))))) {
                        bVar1 = 7 < iVar22;
                      }
                    }
                    else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x97)) &&
                              (0x4b < *pbRam0201fc14)) &&
                             ((pbRam0201fc14[1] < 10 && (pbRam0201fc14[1] != 0)))) &&
                            (((pbRam0201fc14[2] < 2 &&
                              ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x7e)))) &&
                             (0xe < (int)uVar8)))) {
                      bVar1 = 6 < iVar22;
                    }
                  }
                  else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x8f)) &&
                            (0x41 < *pbRam0201fc14)) &&
                           (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                            ((pbRam0201fc14[2] < 2 &&
                             ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0xc9)))))))) &&
                          (0xe < (int)uVar8)) {
                    bVar1 = 6 < iVar22;
                  }
                }
                else if ((((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x83)) && (0x3c < *pbRam0201fc14)
                           ) && ((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)))) &&
                         ((pbRam0201fc14[2] < 4 && ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x191)))
                          ))) && (0x1d < (int)uVar8)) {
                  bVar1 = 5 < iVar22;
                }
              }
              else if ((((iVar15 == 100) && (*pbRam0201fc14 < 0x6e)) && (0x28 < *pbRam0201fc14)) &&
                      (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                       (((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[3] < 2 && ((int)uVar8 < 0x191))))
                        && (0x1d < (int)uVar8)))))) {
                bVar1 = 0 < iVar22;
              }
            }
            else if ((((0x4f < iVar15) && (*pbRam0201fc14 < 0x5a)) && (0x15 < *pbRam0201fc14)) &&
                    (((pbRam0201fc14[1] < 0x13 && (5 < pbRam0201fc14[1])) &&
                     ((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[3] < 4 && ((int)uVar8 < 0x191))))))))
            {
              bVar1 = 0x22 < (int)uVar8;
            }
          }
          else if ((((((0x31 < iVar15) && (*pbRam0201fc14 < 0x29)) && (0x13 < *pbRam0201fc14)) &&
                    ((pbRam0201fc14[1] < 0x14 && (pbRam0201fc14[1] != 0)))) &&
                   (pbRam0201fc14[2] < 6)) && ((pbRam0201fc14[3] < 4 && ((int)uVar8 < 0x191)))) {
            bVar1 = 0x3c < (int)uVar8;
          }
        }
        else if ((((0x27 < iVar15) && (*pbRam0201fc14 < 0x15)) && (5 < *pbRam0201fc14)) &&
                (((pbRam0201fc14[1] < 0x12 && (pbRam0201fc14[1] != 0)) &&
                 ((pbRam0201fc14[2] < 7 && ((pbRam0201fc14[3] < 5 && ((int)uVar8 < 0x1f5)))))))) {
          bVar1 = 0x4e < (int)uVar8;
        }
      }
      else if (((((0x1d < iVar15) && (*pbRam0201fc14 < 0xe)) && (*pbRam0201fc14 != 0)) &&
               ((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)))) &&
              ((pbRam0201fc14[2] < 8 && ((pbRam0201fc14[3] < 8 && ((int)uVar8 < 0x259)))))) {
        bVar1 = 0x4f < (int)uVar8;
      }
    }
    else if (cVar2 == '\x01') {
      if ((iVar16 < 100) || (199 < iVar16)) {
        if ((iVar16 < 200) || (299 < iVar16)) {
          if ((iVar16 < 300) || (399 < iVar16)) {
            if ((iVar16 < 400) || (499 < iVar16)) {
              if ((iVar16 < 500) || (599 < iVar16)) {
                if ((iVar16 < 600) || (699 < iVar16)) {
                  if ((iVar16 < 700) || (799 < iVar16)) {
                    if ((iVar16 < 800) || (899 < iVar16)) {
                      if ((iVar16 < 900) || (iRam0201fc38 <= iVar16)) {
                        if ((iVar16 < iRam0201fc38) || (iRam0201fc3c <= iVar16)) {
                          if ((iVar16 < iRam0201fc3c) || (iRam0201fc40 <= iVar16)) {
                            if ((iVar16 < iRam0201fc40) || (iRam0201fc30 <= iVar16)) {
                              if (((((iVar15 == 0x7f) && (pbRam0201fc14[1] == 0)) &&
                                   (pbRam0201fc14[2] == 0)) &&
                                  ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x65)))) &&
                                 (0x1c < (int)uVar8)) {
                                bVar1 = 0x1b < iVar22;
                              }
                            }
                            else if ((((iVar15 == 0x7f) && (0xb3 < *pbRam0201fc14)) &&
                                     ((pbRam0201fc14[1] < 3 &&
                                      (((pbRam0201fc14[2] == 0 && (pbRam0201fc14[3] == 0)) &&
                                       ((int)uVar8 < 0x65)))))) && (0x1b < (int)uVar8)) {
                              bVar1 = 0x1b < iVar22;
                            }
                          }
                          else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xbf)) &&
                                   (((0x95 < *pbRam0201fc14 &&
                                     ((pbRam0201fc14[1] < 3 && (pbRam0201fc14[2] == 0)))) &&
                                    (pbRam0201fc14[3] == 0)))) &&
                                  (((int)uVar8 < 0x65 && (0x1f < (int)uVar8)))) {
                            bVar1 = 0xe < iVar22;
                          }
                        }
                        else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xaa)) &&
                                 (0x77 < *pbRam0201fc14)) &&
                                (((pbRam0201fc14[1] < 5 && (pbRam0201fc14[2] < 2)) &&
                                 ((pbRam0201fc14[3] == 0 &&
                                  (((int)uVar8 < 0x65 && (0x1f < (int)uVar8)))))))) {
                          bVar1 = 8 < iVar22;
                        }
                      }
                      else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xa1)) &&
                                (0x59 < *pbRam0201fc14)) &&
                               ((pbRam0201fc14[1] < 8 && (pbRam0201fc14[2] < 2)))) &&
                              ((pbRam0201fc14[3] == 0 &&
                               (((int)uVar8 < 0x74 && (0x13 < (int)uVar8)))))) {
                        bVar1 = 7 < iVar22;
                      }
                    }
                    else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x97)) &&
                              (0x4b < *pbRam0201fc14)) &&
                             (((pbRam0201fc14[1] < 10 && (pbRam0201fc14[1] != 0)) &&
                              ((pbRam0201fc14[2] < 2 &&
                               ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x7e)))))))) &&
                            (0xe < (int)uVar8)) {
                      bVar1 = 6 < iVar22;
                    }
                  }
                  else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x8f)) &&
                            (0x41 < *pbRam0201fc14)) &&
                           (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                            ((pbRam0201fc14[2] < 2 &&
                             ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0xc9)))))))) &&
                          (0xe < (int)uVar8)) {
                    bVar1 = 6 < iVar22;
                  }
                }
                else if ((((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x83)) && (0x3c < *pbRam0201fc14)
                           ) && ((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)))) &&
                         (pbRam0201fc14[2] < 4)) &&
                        (((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x191)) && (0x1d < (int)uVar8))))
                {
                  bVar1 = 5 < iVar22;
                }
              }
              else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x6e)) && (0x28 < *pbRam0201fc14)) &&
                      ((((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                        ((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[3] < 2 && ((int)uVar8 < 0x191)))))
                        ) && (0x1d < (int)uVar8)))) {
                bVar1 = 0 < iVar22;
              }
            }
            else if (((((0x72 < iVar15) && (*pbRam0201fc14 < 0x5a)) && (0x15 < *pbRam0201fc14)) &&
                     ((pbRam0201fc14[1] < 0x13 && (5 < pbRam0201fc14[1])))) &&
                    ((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[3] < 4 && ((int)uVar8 < 0x191)))))) {
              bVar1 = 0x22 < (int)uVar8;
            }
          }
          else if (((((99 < iVar15) && (*pbRam0201fc14 < 0x29)) && (0x13 < *pbRam0201fc14)) &&
                   ((pbRam0201fc14[1] < 0x14 && (1 < pbRam0201fc14[1])))) &&
                  (((pbRam0201fc14[2] < 6 && ((pbRam0201fc14[2] != 0 && (pbRam0201fc14[3] < 4)))) &&
                   ((int)uVar8 < 0x191)))) {
            bVar1 = 0x3c < (int)uVar8;
          }
        }
        else if ((((0x59 < iVar15) && (*pbRam0201fc14 < 0x21)) && (8 < *pbRam0201fc14)) &&
                ((((pbRam0201fc14[1] < 0xf && (1 < pbRam0201fc14[1])) &&
                  ((pbRam0201fc14[2] < 7 && ((pbRam0201fc14[2] != 0 && (pbRam0201fc14[3] < 5))))))
                 && ((int)uVar8 < 0x1f5)))) {
          bVar1 = 0x4e < (int)uVar8;
        }
      }
      else if ((((0x45 < iVar15) && (*pbRam0201fc14 < 10)) && (*pbRam0201fc14 != 0)) &&
              (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
               ((pbRam0201fc14[2] < 8 && ((pbRam0201fc14[3] < 8 && ((int)uVar8 < 0x259)))))))) {
        bVar1 = 0x4f < (int)uVar8;
      }
    }
    else if (cVar2 == '\x02') {
      if ((iVar16 < 100) || (199 < iVar16)) {
        if ((iVar16 < 200) || (299 < iVar16)) {
          if ((iVar16 < 300) || (399 < iVar16)) {
            if ((iVar16 < 400) || (499 < iVar16)) {
              if ((iVar16 < 500) || (599 < iVar16)) {
                if ((iVar16 < 600) || (699 < iVar16)) {
                  if ((iVar16 < 700) || (799 < iVar16)) {
                    if ((iVar16 < 800) || (899 < iVar16)) {
                      if ((iVar16 < 900) || (iRam0201fc38 <= iVar16)) {
                        if ((iVar16 < iRam0201fc38) || (iRam0201fc3c <= iVar16)) {
                          if ((iVar16 < iRam0201fc3c) || (iRam0201fc40 <= iVar16)) {
                            if ((iVar16 < iRam0201fc40) || (iRam0201fc30 <= iVar16)) {
                              if (((((iVar15 == 0x7f) && (pbRam0201fc14[1] == 0)) &&
                                   (pbRam0201fc14[2] == 0)) &&
                                  ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x65)))) &&
                                 (4 < (int)uVar8)) {
                                bVar1 = 0x1b < iVar22;
                              }
                            }
                            else if ((((iVar15 == 0x7f) && (0xb3 < *pbRam0201fc14)) &&
                                     ((pbRam0201fc14[1] < 3 &&
                                      (((pbRam0201fc14[2] == 0 && (pbRam0201fc14[3] == 0)) &&
                                       ((int)uVar8 < 0x65)))))) && (8 < (int)uVar8)) {
                              bVar1 = 0x1b < iVar22;
                            }
                          }
                          else if (((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xbf)) &&
                                  ((((0x95 < *pbRam0201fc14 &&
                                     ((pbRam0201fc14[1] < 3 && (pbRam0201fc14[2] == 0)))) &&
                                    (pbRam0201fc14[3] == 0)) &&
                                   (((int)uVar8 < 0x65 && (0xc < (int)uVar8)))))) {
                            bVar1 = 0xe < iVar22;
                          }
                        }
                        else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xaa)) &&
                                 (0x77 < *pbRam0201fc14)) &&
                                (((pbRam0201fc14[1] < 5 && (pbRam0201fc14[2] < 2)) &&
                                 ((pbRam0201fc14[3] == 0 &&
                                  (((int)uVar8 < 0x65 && (0xc < (int)uVar8)))))))) {
                          bVar1 = 8 < iVar22;
                        }
                      }
                      else if ((((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0xa1)) &&
                                 (0x59 < *pbRam0201fc14)) &&
                                ((pbRam0201fc14[1] < 8 && (pbRam0201fc14[2] == 0)))) &&
                               (pbRam0201fc14[3] == 0)) &&
                              (((int)uVar8 < 0x65 && (0xe < (int)uVar8)))) {
                        bVar1 = 7 < iVar22;
                      }
                    }
                    else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x97)) &&
                             (0x4b < *pbRam0201fc14)) &&
                            (((pbRam0201fc14[1] < 10 && (pbRam0201fc14[1] != 0)) &&
                             (((pbRam0201fc14[2] == 0 &&
                               ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x65)))) &&
                              (0xe < (int)uVar8)))))) {
                      bVar1 = 6 < iVar22;
                    }
                  }
                  else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x8f)) &&
                            (0x41 < *pbRam0201fc14)) &&
                           (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                            ((pbRam0201fc14[2] == 0 &&
                             ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0xc9)))))))) &&
                          (0xe < (int)uVar8)) {
                    bVar1 = 6 < iVar22;
                  }
                }
                else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x83)) && (0x41 < *pbRam0201fc14))
                         && ((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)))) &&
                        (((pbRam0201fc14[2] == 0 &&
                          ((pbRam0201fc14[3] == 0 && ((int)uVar8 < 0x191)))) && (0x1d < (int)uVar8))
                        )) {
                  bVar1 = 5 < iVar22;
                }
              }
              else if ((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x6e)) && (0x28 < *pbRam0201fc14)) &&
                      (((pbRam0201fc14[1] < 0xf && (pbRam0201fc14[1] != 0)) &&
                       (((pbRam0201fc14[2] < 2 && ((pbRam0201fc14[3] < 2 && ((int)uVar8 < 0x191))))
                        && (0x1d < (int)uVar8)))))) {
                bVar1 = 4 < iVar22;
              }
            }
            else if (((((iVar15 == 0x7f) && (*pbRam0201fc14 < 0x5a)) && (0x1e < *pbRam0201fc14)) &&
                     (((pbRam0201fc14[1] < 0x13 && (pbRam0201fc14[1] != 0)) &&
                      ((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[3] < 2 && ((int)uVar8 < 0x191)))))))
                     ) && (0x22 < (int)uVar8)) {
              bVar1 = 6 < iVar22;
            }
          }
          else if ((((((99 < iVar15) && (*pbRam0201fc14 < 0x29)) && (0x17 < *pbRam0201fc14)) &&
                    ((pbRam0201fc14[1] < 0x14 && (1 < pbRam0201fc14[1])))) &&
                   ((pbRam0201fc14[2] < 5 && ((pbRam0201fc14[2] != 0 && (pbRam0201fc14[3] < 3))))))
                  && ((int)uVar8 < 0x191)) {
            bVar1 = 0x40 < (int)uVar8;
          }
        }
        else if (((((0x59 < iVar15) && (*pbRam0201fc14 < 0x21)) && (0xd < *pbRam0201fc14)) &&
                 (((pbRam0201fc14[1] < 7 && (1 < pbRam0201fc14[1])) &&
                  ((pbRam0201fc14[2] < 6 && ((pbRam0201fc14[2] != 0 && (pbRam0201fc14[3] < 5))))))))
                && ((int)uVar8 < 0x1f5)) {
          bVar1 = 0x4e < (int)uVar8;
        }
      }
      else if (((((0x45 < iVar15) && (*pbRam0201fc14 < 10)) && (4 < *pbRam0201fc14)) &&
               (((pbRam0201fc14[1] < 0xf && (2 < pbRam0201fc14[1])) &&
                ((pbRam0201fc14[2] < 8 && ((pbRam0201fc14[2] != 0 && (pbRam0201fc14[3] < 8))))))))
              && ((pbRam0201fc14[3] != 0 && ((int)uVar8 < 0x259)))) {
        bVar1 = 0x4f < (int)uVar8;
      }
    }
  }
  if (bVar1) {
    uVar8 = *(uint *)((uint)piRam020203cc & 0xfffffffc) >> ((uint)piRam020203cc & 3) * 8 |
            *(uint *)((uint)piRam020203cc & 0xfffffffc) << ((uint)piRam020203cc & 3) * -8 + 0x20;
    if ((int)uVar8 < local_40) {
      *piRam020203cc = uVar8 + 1;
    }
    else if (local_54 < iRam0201fc30) {
      *pcRam0201fc2c =
           ((char)(local_54 +
                   (int)((ulonglong)((longlong)iRam020203d0 * (longlong)local_54) >> 0x20) >> 2) -
           (char)(local_54 >> 0x1f)) + -0xd;
    }
    else {
      *pcRam0201fc2c = -1;
    }
  }
  else {
    *piRam020203cc = 0;
  }
  return *pcRam0201fc2c;
}

