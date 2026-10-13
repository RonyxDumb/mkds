/* Decompiled C draft; module arm9; ROM address 021253f8. No matching claim. */
#include "types.h"
#include "deps/021253f8_G2d_Text_SomeFn_3_from_thumb.h"

void G2d_Text_SomeFn_3_from_thumb
               (int param_1,int *param_2,int *param_3,int *param_4,byte *param_5,ushort *param_6,
               int param_7,int param_8)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  ushort *puVar13;
  int iVar14;
  int local_5c;
  int local_48;
  int local_44;
  byte *local_40;
  ushort local_3c [10];
  ushort local_28 [10];
  
  local_5c = 0;
  iVar8 = *(int *)(param_1 + 8);
  piVar12 = *(int **)(param_1 + 4);
  iVar10 = *(int *)(param_1 + 0xc);
  cVar3 = *(char *)(*piVar12 + 1);
  local_40 = param_5;
  *param_2 = -1;
  *param_3 = 0;
  *param_4 = (int)*(char *)(*piVar12 + 1);
  uVar5 = (*(code *)piVar12[1])(&local_40);
  if (uVar5 != 0) {
    iVar6 = param_8 + iVar8;
    piVar11 = param_3;
    do {
      if (uVar5 == 0x1a) {
        uVar5 = (uint)*local_40;
        uVar9 = (uint)*(ushort *)(local_40 + 2);
        bVar1 = local_40[1];
        if (bVar1 != 0) {
          if (bVar1 == 1) {
            if (uVar9 < 0xb) {
              if (uVar9 < 10) {
                if ((uVar9 < 2) && (-1 < (int)uVar9)) {
                  if (uVar9 == 0) {
                    iVar14 = 0;
                    do {
                      uVar2 = *(ushort *)(*(int *)*puRam0212578c + iVar14 * 2 + 0xc);
                      uVar9 = (uint)uVar2;
                      if (uVar9 == 0) {
                        iVar14 = 10;
                      }
                      else {
                        *param_6 = uVar2;
                        param_6 = param_6 + 1;
                        if (param_8 == -1) {
LAB_021254ea:
                          uVar9 = NFTR_GetTileIndexForCharacter(piVar12);
                          if (uVar9 == uRam02125798) {
                            uVar9 = (uint)*(ushort *)(*piVar12 + 2);
                          }
                          iVar7 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar12),uVar9);
                          *piVar11 = *piVar11 + *(char *)(iVar7 + 2) + iVar8;
                        }
                        else {
                          if (param_7 != 0) {
                            if ((((uVar9 < 0x30) || (0x39 < uVar9)) &&
                                ((uVar9 < uRam02125790 || (uRam02125794 < uVar9)))) &&
                               (uVar9 != 0x2d)) {
                              bVar4 = false;
                            }
                            else {
                              bVar4 = true;
                            }
                            if (!bVar4) goto LAB_021254ea;
                          }
                          *piVar11 = *piVar11 + iVar6;
                        }
                      }
                      iVar14 = iVar14 + 1;
                    } while (iVar14 < 10);
                  }
                  else if (uVar9 == 1) {
                    iVar14 = GetClampedString10LengthForFontIndex0_from_thumb
                                       (*(int *)*puRam0212578c + 0xc,(int)(uintptr_t)(local_3c));
                    local_44 = 0;
                    if (0 < iVar14) {
                      puVar13 = local_3c;
                      do {
                        *param_6 = *puVar13;
                        param_6 = param_6 + 1;
                        if (param_8 == -1) {
LAB_02125578:
                          uVar9 = NFTR_GetTileIndexForCharacter((uint)(uintptr_t)(piVar12),*puVar13);
                          if (uVar9 == uRam02125798) {
                            uVar9 = (uint)*(ushort *)(*piVar12 + 2);
                          }
                          iVar7 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar12),uVar9);
                          *piVar11 = *piVar11 + *(char *)(iVar7 + 2) + iVar8;
                        }
                        else {
                          if (param_7 != 0) {
                            uVar9 = (uint)*puVar13;
                            if ((((uVar9 < 0x30) || (0x39 < uVar9)) &&
                                ((uVar9 < uRam02125790 || (uRam02125794 < uVar9)))) &&
                               (uVar9 != 0x2d)) {
                              bVar4 = false;
                            }
                            else {
                              bVar4 = true;
                            }
                            if (!bVar4) goto LAB_02125578;
                          }
                          *piVar11 = *piVar11 + iVar6;
                        }
                        puVar13 = puVar13 + 1;
                        local_44 = local_44 + 1;
                      } while (local_44 < iVar14);
                    }
                    goto LAB_021255b8;
                  }
                }
              }
              else {
LAB_021255b8:
                iVar14 = 0;
                do {
                  uVar2 = *(ushort *)(*piRam0212579c + iVar14 * 2 + 0x2a);
                  uVar9 = (uint)uVar2;
                  if (uVar9 == 0) {
                    iVar14 = 10;
                  }
                  else {
                    *param_6 = uVar2;
                    param_6 = param_6 + 1;
                    if (param_8 == -1) {
LAB_02125602:
                      uVar9 = NFTR_GetTileIndexForCharacter(piVar12);
                      if (uVar9 == uRam02125798) {
                        uVar9 = (uint)*(ushort *)(*piVar12 + 2);
                      }
                      iVar7 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar12),uVar9);
                      *piVar11 = *piVar11 + *(char *)(iVar7 + 2) + iVar8;
                    }
                    else {
                      if (param_7 != 0) {
                        if ((((uVar9 < 0x30) || (0x39 < uVar9)) &&
                            ((uVar9 < uRam02125790 || (uRam02125794 < uVar9)))) && (uVar9 != 0x2d))
                        {
                          bVar4 = false;
                        }
                        else {
                          bVar4 = true;
                        }
                        if (!bVar4) goto LAB_02125602;
                      }
                      *piVar11 = *piVar11 + iVar6;
                    }
                  }
                  iVar14 = iVar14 + 1;
                } while (iVar14 < 10);
              }
            }
            else if (uVar9 == 0xb) {
              iVar14 = GetClampedString10LengthForFontIndex0_from_thumb
                                 (*piRam0212579c + 0x2a,(int)(uintptr_t)(local_28));
              local_48 = 0;
              if (0 < iVar14) {
                puVar13 = local_28;
                do {
                  *param_6 = *puVar13;
                  param_6 = param_6 + 1;
                  if (param_8 == -1) {
LAB_0212568e:
                    uVar9 = NFTR_GetTileIndexForCharacter((uint)(uintptr_t)(piVar12),*puVar13);
                    if (uVar9 == uRam02125798) {
                      uVar9 = (uint)*(ushort *)(*piVar12 + 2);
                    }
                    iVar7 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar12),uVar9);
                    *piVar11 = *piVar11 + *(char *)(iVar7 + 2) + iVar8;
                  }
                  else {
                    if (param_7 != 0) {
                      uVar9 = (uint)*puVar13;
                      if ((((uVar9 < 0x30) || (0x39 < uVar9)) &&
                          ((uVar9 < uRam02125790 || (uRam02125794 < uVar9)))) && (uVar9 != 0x2d)) {
                        bVar4 = false;
                      }
                      else {
                        bVar4 = true;
                      }
                      if (!bVar4) goto LAB_0212568e;
                    }
                    *piVar11 = *piVar11 + iVar6;
                  }
                  puVar13 = puVar13 + 1;
                  local_48 = local_48 + 1;
                } while (local_48 < iVar14);
              }
            }
          }
          else if ((bVar1 == 0xff) && (uVar9 == 0)) {
            Mem_CpuCopy8((ushort *)(void *)(local_40 + -2),(uint *)(void *)(param_6),uVar5);
            param_6 = param_6 + ((int)uVar5 >> 1);
          }
        }
        local_40 = local_40 + (uVar5 - 2);
      }
      else {
        *param_6 = (ushort)uVar5;
        param_6 = param_6 + 1;
        if (uVar5 == 10) {
          *param_4 = *param_4 + iVar10 + cVar3;
          if (*param_2 < *piVar11) {
            *param_2 = *piVar11;
          }
          piVar11 = piVar11 + 1;
          local_5c = local_5c + 1;
          *piVar11 = 0;
        }
        else {
          if ((*(short *)local_40 == 0) || (iVar14 = iVar8, *(short *)local_40 == 10)) {
            iVar14 = 0;
          }
          if (param_8 == -1) {
LAB_02125764:
            uVar5 = NFTR_GetTileIndexForCharacter(piVar12);
            if (uVar5 == uRam02125798) {
              uVar5 = (uint)*(ushort *)(*piVar12 + 2);
            }
            iVar7 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar12),uVar5);
            *piVar11 = *piVar11 + *(char *)(iVar7 + 2) + iVar14;
          }
          else {
            if (param_7 != 0) {
              if ((((uVar5 < 0x30) || (0x39 < uVar5)) &&
                  ((uVar5 < uRam02125790 || (uRam02125794 < uVar5)))) && (uVar5 != 0x2d)) {
                bVar4 = false;
              }
              else {
                bVar4 = true;
              }
              if (!bVar4) goto LAB_02125764;
            }
            *piVar11 = *piVar11 + param_8 + iVar14;
          }
        }
      }
      uVar5 = (*(code *)piVar12[1])(&local_40);
    } while (uVar5 != 0);
  }
  *param_6 = 0;
  if (*param_2 < param_3[local_5c]) {
    *param_2 = param_3[local_5c];
  }
  return;
}

