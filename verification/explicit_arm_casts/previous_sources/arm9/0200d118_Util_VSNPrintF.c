/* Decompiled C draft; module arm9; ROM address 0200d118. No matching claim. */
#include "types.h"
#include "deps/0200d118_Util_VSNPrintF.h"

int Util_VSNPrintF(undefined1 *param_1,int param_2,byte *param_3,ushort *param_4)

{
  byte bVar1;
  longlong lVar2;
  undefined1 uVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  uint uVar21;
  ushort *puVar22;
  ushort *puVar23;
  longlong lVar24;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_74;
  uint local_64;
  uint local_60;
  uint local_5c;
  char local_50 [28];
  int local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  
  local_34 = param_2;
  local_2c = param_1;
  local_30 = param_1;
  if (*param_3 != 0) {
    local_7c = 10;
    local_84 = 0;
    local_80 = 0xffffffff;
    local_74 = 8;
    local_64 = 0x10;
    local_60 = 1;
    local_5c = 2;
    do {
      if ((*param_3 ^ 0x20) - 0xa1 < 0x3c) {
        Util_PrintContext_ApppendChar(&local_34);
        pbVar18 = param_3 + 1;
        if (*pbVar18 != 0) {
          pbVar18 = param_3 + 2;
          Util_PrintContext_ApppendChar(&local_34);
        }
        goto LAB_0200d988;
      }
      if (*param_3 != 0x25) {
        pbVar18 = param_3 + 1;
        Util_PrintContext_ApppendChar(&local_34);
        goto LAB_0200d988;
      }
      cVar4 = 'W';
      uVar16 = local_84;
      pbVar18 = param_3;
      while( true ) {
        while( true ) {
          pbVar19 = pbVar18 + 1;
          bVar1 = *pbVar19;
          if (' ' < (char)bVar1) break;
          if (bVar1 != 0x20) goto LAB_0200d288;
          uVar16 = uVar16 | 1;
          pbVar18 = pbVar19;
        }
        if (('0' < (char)bVar1) || ((char)bVar1 < '+')) break;
        if (bVar1 == 0x2b) {
          if (*pbVar18 != 0x20) break;
          uVar16 = uVar16 | 2;
          pbVar18 = pbVar19;
        }
        else if (bVar1 == 0x2d) {
          uVar16 = uVar16 | 8;
          pbVar18 = pbVar19;
        }
        else {
          if (bVar1 != 0x30) break;
          uVar16 = uVar16 | 0x10;
          pbVar18 = pbVar19;
        }
      }
LAB_0200d288:
      uVar21 = local_84;
      if (bVar1 == 0x2a) {
        puVar22 = param_4 + 2;
        uVar21 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
                 *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20;
        pbVar19 = pbVar18 + 2;
        if ((int)uVar21 < 0) {
          uVar21 = -uVar21;
          uVar16 = uVar16 | 8;
        }
      }
      else {
        for (; (puVar22 = param_4, '/' < (char)*pbVar19 && ((char)*pbVar19 < ':'));
            pbVar19 = pbVar19 + 1) {
          uVar21 = (uVar21 * 10 + (int)(char)*pbVar19) - 0x30;
        }
      }
      uVar14 = local_80;
      pbVar20 = pbVar19;
      puVar23 = puVar22;
      if (*pbVar19 == 0x2e) {
        pbVar20 = pbVar19 + 1;
        uVar14 = local_84;
        if (*pbVar20 == 0x2a) {
          puVar23 = puVar22 + 2;
          uVar14 = *(uint *)((uint)puVar22 & 0xfffffffc) >> ((uint)puVar22 & 3) * 8 |
                   *(uint *)((uint)puVar22 & 0xfffffffc) << ((uint)puVar22 & 3) * -8 + 0x20;
          pbVar20 = pbVar19 + 2;
          if ((int)uVar14 < 0) {
            uVar14 = local_80;
          }
        }
        else {
          for (; ('/' < (char)*pbVar20 && ((char)*pbVar20 < ':')); pbVar20 = pbVar20 + 1) {
            uVar14 = (uVar14 * 10 + (int)(char)*pbVar20) - 0x30;
          }
        }
      }
      if (*pbVar20 == 0x68) {
        if (pbVar20[1] == 0x68) {
          uVar16 = uVar16 | 0x100;
          pbVar18 = pbVar20 + 2;
        }
        else {
          uVar16 = uVar16 | 0x40;
          pbVar18 = pbVar20 + 1;
        }
      }
      else {
        pbVar18 = pbVar20;
        if ((*pbVar20 == 0x6c) && (pbVar18 = pbVar20 + 1, pbVar20[1] == 0x6c)) {
          uVar16 = uVar16 | 0x80;
          pbVar18 = pbVar20 + 2;
        }
      }
      iVar7 = (int)(char)*pbVar18;
      uVar3 = 0x30;
      uVar11 = local_7c;
      param_4 = puVar23;
      if (iVar7 < 0x6a) {
        if (iVar7 < 99) {
          if (iVar7 < 0x26) {
            if ((iVar7 == 0x25) && (param_3 + 1 == pbVar18)) {
              pbVar18 = pbVar18 + 1;
              Util_PrintContext_ApppendChar(&local_34);
              goto LAB_0200d988;
            }
          }
          else if (iVar7 == 0x58) {
            cVar4 = '7';
            goto LAB_0200d5e0;
          }
        }
        else if (iVar7 == 99) {
          if ((int)uVar14 < 0) {
            bVar1 = (byte)(*(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8) |
                    (byte)(*(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20)
            ;
            if ((uVar16 & 8) == 0) {
              if ((uVar16 & 0x10) == 0) {
                uVar3 = 0x20;
              }
              Util_PrintContext_FillWith(&local_34,uVar3);
              Util_PrintContext_ApppendChar(&local_34,(int)(char)bVar1);
            }
            else {
              Util_PrintContext_ApppendChar(&local_34,(int)(char)bVar1);
              Util_PrintContext_FillWith(&local_34,0x20);
            }
            pbVar18 = pbVar18 + 1;
            param_4 = puVar23 + 2;
            goto LAB_0200d988;
          }
        }
        else if ((iVar7 == 100) || (iVar7 == 0x69)) goto LAB_0200d5e8;
        goto switchD_0200d3d8_default;
      }
      if (iVar7 < 0x6f) {
        if (iVar7 != 0x6e) goto switchD_0200d3d8_default;
        iVar7 = (int)local_30 - (int)local_2c;
        if ((uVar16 & 0x100) == 0) {
          if ((uVar16 & 0x40) == 0) {
            if ((uVar16 & 0x80) == 0) {
              param_4 = puVar23 + 2;
              *(int *)(*(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                      *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20) =
                   iVar7;
            }
            else {
              param_4 = puVar23 + 2;
              piVar5 = (int *)(*(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                              *(uint *)((uint)puVar23 & 0xfffffffc) <<
                              ((uint)puVar23 & 3) * -8 + 0x20);
              *piVar5 = iVar7;
              piVar5[1] = iVar7 >> 0x1f;
            }
          }
          else {
            param_4 = puVar23 + 2;
            *(short *)(*(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                      *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20) =
                 (short)iVar7;
          }
        }
        pbVar18 = pbVar18 + 1;
        goto LAB_0200d988;
      }
      switch(iVar7) {
      case 0x6f:
        uVar16 = uVar16 | 0x1000;
        uVar11 = local_74;
        goto LAB_0200d5e8;
      case 0x70:
        uVar16 = uVar16 | 4;
        uVar14 = local_74;
        goto LAB_0200d5e0;
      case 0x71:
        break;
      case 0x72:
        break;
      case 0x73:
        param_4 = puVar23 + 2;
        pcVar13 = (char *)(*(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                          *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20);
        uVar11 = local_84;
        if ((int)uVar14 < 0) {
          cVar4 = *pcVar13;
          while (cVar4 != '\0') {
            uVar11 = uVar11 + 1;
            cVar4 = pcVar13[uVar11];
          }
        }
        else {
          for (; ((int)uVar11 < (int)uVar14 && (pcVar13[uVar11] != '\0')); uVar11 = uVar11 + 1) {
          }
        }
        if ((uVar16 & 8) == 0) {
          if ((uVar16 & 0x10) == 0) {
            uVar3 = 0x20;
          }
          Util_PrintContext_FillWith(&local_34,uVar3,uVar21 - uVar11);
          Util_PrintContext_AppendString(&local_34,pcVar13);
        }
        else {
          Util_PrintContext_AppendString(&local_34,pcVar13,uVar11);
          Util_PrintContext_FillWith(&local_34,0x20);
        }
        pbVar18 = pbVar18 + 1;
        goto LAB_0200d988;
      case 0x74:
        break;
      case 0x75:
        uVar16 = uVar16 | 0x1000;
        goto LAB_0200d5e8;
      case 0x76:
        break;
      case 0x77:
        break;
      case 0x78:
LAB_0200d5e0:
        uVar16 = uVar16 | 0x1000;
        uVar11 = local_64;
LAB_0200d5e8:
        if ((uVar16 & 8) != 0) {
          uVar16 = uVar16 & 0xffffffef;
        }
        uVar15 = local_60;
        if (-1 < (int)uVar14) {
          uVar16 = uVar16 & 0xffffffef;
          uVar15 = uVar14;
        }
        uVar14 = local_84;
        if ((uVar16 & 0x1000) == 0) {
          if ((uVar16 & 0x100) == 0) {
            if ((uVar16 & 0x40) == 0) {
              if ((uVar16 & 0x80) == 0) {
                param_4 = puVar23 + 2;
                uVar12 = *(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                         *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20;
                uVar8 = (int)uVar12 >> 0x1f;
              }
              else {
                param_4 = puVar23 + 4;
                uVar12 = *(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                         *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20;
                uVar8 = (uint)(puVar23 + 2) & 3;
                uVar10 = *(uint *)((uint)(puVar23 + 2) & 0xfffffffc);
                uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
              }
            }
            else {
              param_4 = puVar23 + 2;
              uVar12 = (uint)(short)*puVar23;
              uVar8 = (int)uVar12 >> 0x1f;
            }
          }
          else {
            param_4 = puVar23 + 2;
            uVar12 = (uint)(char)(byte)*puVar23;
            uVar8 = (int)uVar12 >> 0x1f;
          }
          if ((uVar8 & 0x80000000) == 0) {
            if ((uVar8 != 0 || uVar12 != 0) || (uVar15 != 0)) {
              if ((uVar16 & 2) == 0) {
                if ((uVar16 & 1) != 0) {
                  local_50[0] = ' ';
                  uVar14 = local_60;
                }
              }
              else {
                local_50[0] = '+';
                uVar14 = local_60;
              }
            }
          }
          else {
            uVar14 = ~uVar12;
            local_50[0] = '-';
            uVar12 = uVar14 + 1;
            uVar8 = ~uVar8 + (uint)(0xfffffffe < uVar14);
            uVar14 = local_60;
          }
        }
        else {
          if ((uVar16 & 0x100) == 0) {
            if ((uVar16 & 0x40) == 0) {
              if ((uVar16 & 0x80) == 0) {
                param_4 = puVar23 + 2;
                uVar12 = *(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                         *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20;
                uVar8 = 0;
              }
              else {
                param_4 = puVar23 + 4;
                uVar8 = (uint)(puVar23 + 2) & 3;
                uVar12 = *(uint *)((uint)(puVar23 + 2) & 0xfffffffc);
                uVar8 = uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20;
                uVar12 = *(uint *)((uint)puVar23 & 0xfffffffc) >> ((uint)puVar23 & 3) * 8 |
                         *(uint *)((uint)puVar23 & 0xfffffffc) << ((uint)puVar23 & 3) * -8 + 0x20;
              }
            }
            else {
              param_4 = puVar23 + 2;
              uVar12 = (uint)*puVar23;
              uVar8 = 0;
            }
          }
          else {
            param_4 = puVar23 + 2;
            uVar12 = (uint)(byte)*puVar23;
            uVar8 = 0;
          }
          uVar17 = uVar16 & 0xfffffffc;
          uVar10 = uVar16 & 4;
          uVar16 = uVar17;
          if (uVar10 != 0) {
            if (uVar11 == 0x10) {
              if (uVar8 != 0 || uVar12 != 0) {
                local_50[1] = 0x30;
                local_50[0] = cVar4 + '!';
                uVar14 = local_5c;
              }
            }
            else {
              if (uVar11 == 8) {
                local_50[0] = '0';
              }
              uVar14 = (uint)(uVar11 == 8);
            }
          }
        }
        uVar10 = local_84;
        if (uVar11 == 8) {
          if (uVar8 != 0 || uVar12 != 0) {
            do {
              local_50[uVar10 + 2] = ((byte)uVar12 & 7) + 0x30;
              uVar11 = uVar8 >> 3;
              uVar12 = uVar12 >> 3 | uVar8 << 0x1d;
              uVar10 = uVar10 + 1;
              uVar8 = uVar11;
            } while (uVar11 != 0 || uVar12 != 0);
          }
        }
        else if (uVar11 == 10) {
          if (uVar8 == 0) {
            while (uVar12 != 0) {
              uVar11 = (uint)((ulonglong)DAT_0200d9dc * (ulonglong)uVar12 >> 0x23);
              local_50[uVar10 + 2] = (char)uVar12 + (char)uVar11 * -10 + '0';
              uVar12 = uVar11;
              uVar10 = uVar10 + 1;
            }
          }
          else {
            lVar2 = CONCAT44(uVar8,uVar12);
            if (uVar8 != 0 || uVar12 != 0) {
              do {
                lVar24 = _ll_udiv((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),10,0);
                local_50[uVar10 + 2] = (char)lVar2 + (char)lVar24 * -10 + '0';
                uVar10 = uVar10 + 1;
                lVar2 = lVar24;
              } while (lVar24 != 0);
            }
          }
        }
        else if ((uVar11 == 0x10) && (uVar8 != 0 || uVar12 != 0)) {
          do {
            uVar11 = uVar12 & 0xf;
            cVar9 = (char)uVar11;
            if (uVar11 < 10) {
              cVar9 = cVar9 + '0';
            }
            uVar17 = uVar8 >> 4;
            uVar12 = uVar12 >> 4 | uVar8 << 0x1c;
            if (9 < uVar11) {
              cVar9 = cVar9 + cVar4;
            }
            local_50[uVar10 + 2] = cVar9;
            uVar10 = uVar10 + 1;
            uVar8 = uVar17;
          } while (uVar17 != 0 || uVar12 != 0);
        }
        if ((uVar14 != 0) && (local_50[0] == '0')) {
          local_50[uVar10 + 2] = '0';
          uVar10 = uVar10 + 1;
          uVar14 = local_84;
        }
        iVar7 = uVar15 - uVar10;
        if (((uVar16 & 0x10) != 0) && (iVar6 = (uVar21 - uVar10) - uVar14, iVar7 < iVar6)) {
          iVar7 = iVar6;
        }
        if (0 < iVar7) {
          uVar21 = uVar21 - iVar7;
        }
        if ((uVar16 & 8) == 0) {
          Util_PrintContext_FillWith(&local_34,0x20,uVar21 - (uVar14 + uVar10));
        }
        if (uVar14 != 0) {
          pcVar13 = local_50 + uVar14;
          do {
            pcVar13 = pcVar13 + -1;
            uVar14 = uVar14 - 1;
            Util_PrintContext_ApppendChar(&local_34,(int)*pcVar13);
          } while (0 < (int)uVar14);
        }
        Util_PrintContext_FillWith(&local_34,0x30);
        if (0 < (int)uVar10) {
          pcVar13 = local_50 + uVar10 + 2;
          do {
            pcVar13 = pcVar13 + -1;
            uVar10 = uVar10 - 1;
            Util_PrintContext_ApppendChar(&local_34,(int)*pcVar13);
          } while (0 < (int)uVar10);
        }
        if ((uVar16 & 8) != 0) {
          Util_PrintContext_FillWith(&local_34,0x20);
        }
        pbVar18 = pbVar18 + 1;
        goto LAB_0200d988;
      }
switchD_0200d3d8_default:
      Util_PrintContext_AppendString(&local_34,param_3);
LAB_0200d988:
      param_3 = pbVar18;
    } while (*pbVar18 != 0);
  }
  if (local_34 == 0) {
    if (param_2 != 0) {
      local_2c[param_2 + -1] = 0;
    }
  }
  else {
    *local_30 = 0;
  }
  return (int)local_30 - (int)local_2c;
}

