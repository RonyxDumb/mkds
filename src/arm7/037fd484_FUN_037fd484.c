/* Decompiled C draft; module arm7; ROM address 037fd484. No matching claim. */
#include "types.h"
#include "deps/037fd484_FUN_037fd484.h"

undefined4 FUN_037fd484(byte *param_1,int param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  short *psVar11;
  uint uVar12;
  int iVar14;
  bool bVar15;
  int local_34;
  int local_30;
  uint uVar13;
  
  uVar13 = (uint)(param_1 + 0x3c) & 3;
  uVar12 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
  for (uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20; uVar13 != 0;
      uVar13 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) {
    uVar12 = uVar13 + 0x34 & 3;
    uVar5 = *(uint *)(uVar13 + 0x34 & 0xfffffffc);
    uVar12 = uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20;
    if (0 < (int)uVar12) {
      *(uint *)(uVar13 + 0x34) = uVar12 - 1;
    }
    if ((-1 < (int)((uint)*(byte *)(uVar13 + 3) << 0x1d)) &&
       (uVar12 = uVar13 + 0x14 & 3, uVar5 = *(uint *)(uVar13 + 0x14 & 0xfffffffc),
       uVar6 = uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20, uVar12 = uVar13 + 0x18 & 3,
       uVar5 = *(uint *)(uVar13 + 0x18 & 0xfffffffc),
       (int)uVar6 < (int)(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20))) {
      *(uint *)(uVar13 + 0x14) = uVar6 + 1;
    }
    uVar12 = uVar13 + 0x50 & 3;
    uVar13 = *(uint *)(uVar13 + 0x50 & 0xfffffffc);
  }
  if ((int)((uint)*param_1 << 0x1b) < 0) {
    uVar13 = (uint)(param_1 + 0x3c) & 3;
    uVar12 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
    if (uVar12 >> uVar13 * 8 != 0 || uVar12 << uVar13 * -8 + 0x20 != 0) {
      return 0;
    }
    *param_1 = *param_1 & 0xef;
  }
  uVar13 = (uint)(param_1 + 0x20) & 3;
  uVar12 = *(uint *)((uint)(param_1 + 0x20) & 0xfffffffc);
  uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
  if ((0 < (int)uVar13) &&
     (*(uint *)(param_1 + 0x20) = uVar13 - 1, uVar13 = (uint)(param_1 + 0x20) & 3,
     uVar12 = *(uint *)((uint)(param_1 + 0x20) & 0xfffffffc),
     0 < (int)(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20))) {
    return 0;
  }
  uVar13 = (uint)(param_1 + 0x28) & 3;
  uVar12 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
  FUN_037fe83c(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20);
  pbVar4 = param_1 + 0x28;
  local_34 = 0x7f;
  local_30 = -1;
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          uVar13 = (uint)(param_1 + 0x20) & 3;
          uVar12 = *(uint *)((uint)(param_1 + 0x20) & 0xfffffffc);
          if ((uVar12 >> uVar13 * 8 != 0 || uVar12 << uVar13 * -8 + 0x20 != 0) ||
             ((int)((uint)*param_1 << 0x1b) < 0)) {
            return 0;
          }
          uVar13 = 1;
          uVar12 = (uint)(param_1 + 0x28) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          uVar6 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
          uVar12 = (uint)(param_1 + 0x28) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          *(uint *)(param_1 + 0x28) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 1;
          if (uVar6 == 0xa2) {
            uVar13 = (uint)(param_1 + 0x28) & 3;
            uVar12 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            uVar6 = FUN_037fe7ec(uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20);
            uVar13 = (uint)(param_1 + 0x28) & 3;
            uVar12 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            *(uint *)(param_1 + 0x28) = (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + 1;
            uVar13 = ((uint)*param_1 << 0x19) >> 0x1f;
          }
          if (uVar6 == 0xa0) {
            uVar12 = (uint)(param_1 + 0x28) & 3;
            uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            uVar6 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
            uVar12 = (uint)(param_1 + 0x28) & 3;
            uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            *(uint *)(param_1 + 0x28) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 1;
          }
          if (uVar6 == 0xa1) {
            uVar12 = (uint)(param_1 + 0x28) & 3;
            uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            uVar6 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
            uVar12 = (uint)(param_1 + 0x28) & 3;
            uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
            *(uint *)(param_1 + 0x28) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 1;
          }
          if ((uVar6 & 0x80) != 0) break;
          uVar12 = (uint)(param_1 + 0x28) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          uVar7 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
          *(uint *)pbVar4 =
               (*(uint *)((uint)pbVar4 & 0xfffffffc) >> ((uint)pbVar4 & 3) * 8 |
               *(uint *)((uint)pbVar4 & 0xfffffffc) << ((uint)pbVar4 & 3) * -8 + 0x20) + 1;
          iVar8 = FUN_037fe634(param_1,param_2);
          iVar14 = uVar6 + (int)(char)param_1[0x13];
          if (uVar13 != 0) {
            if (iVar14 < 0) {
              iVar14 = 0;
            }
            else if (0x7f < iVar14) {
              iVar14 = local_34;
            }
            if ((-1 < (int)((uint)*param_1 << 0x1d)) && (param_4 != 0)) {
              iVar9 = iVar8;
              if (iVar8 < 1) {
                iVar9 = local_30;
              }
              FUN_037fde38(param_1,param_2,iVar14,uVar7,iVar9);
            }
            param_1[0x14] = (byte)iVar14;
            if (((int)((uint)*param_1 << 0x1e) < 0) &&
               (*(int *)(param_1 + 0x20) = iVar8, iVar8 == 0)) {
              *param_1 = *param_1 | 0x10;
            }
          }
        }
        uVar12 = uVar6 & 0xf0;
        if (uVar12 < 0xc1) break;
        if (uVar12 < 0xe1) {
          if (uVar12 < 0xe0) {
            if (uVar12 == 0xd0) goto code_r0x037fd880;
          }
          else {
            uVar2 = FUN_037fe634(param_1,param_2);
            if (uVar13 != 0) {
              if (uVar6 == 0xe0) {
                *(undefined2 *)(param_1 + 0x1c) = uVar2;
              }
              else if (uVar6 == 0xe1) {
                *(undefined2 *)(param_2 + 0x18) = uVar2;
              }
              else if (uVar6 == 0xe3) {
                *(undefined2 *)(param_1 + 0x16) = uVar2;
              }
            }
          }
        }
        else if ((uVar12 == 0xf0) && (uVar13 != 0)) {
          switch(uVar6) {
          case 0xfc:
            uVar13 = (uint)param_1[0x3b];
            if (uVar13 != 0) {
              bVar1 = param_1[uVar13 + 0x37];
              if ((bVar1 == 0) || (bVar1 = bVar1 - 1, bVar1 != 0)) {
                param_1[uVar13 + 0x37] = bVar1;
                uVar13 = (uint)(param_1 + (param_1[0x3b] - 1) * 4 + 0x2c) & 3;
                uVar12 = *(uint *)((uint)(param_1 + (param_1[0x3b] - 1) * 4 + 0x2c) & 0xfffffffc);
                *(uint *)(param_1 + 0x28) = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
              }
              else {
                param_1[0x3b] = param_1[0x3b] - 1;
              }
            }
            break;
          case 0xfd:
            if (param_1[0x3b] != 0) {
              param_1[0x3b] = param_1[0x3b] - 1;
              uVar13 = (uint)(param_1 + (uint)param_1[0x3b] * 4 + 0x2c) & 3;
              uVar12 = *(uint *)((uint)(param_1 + (uint)param_1[0x3b] * 4 + 0x2c) & 0xfffffffc);
              *(uint *)(param_1 + 0x28) = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
            }
            break;
          case 0xfe:
            break;
          case 0xff:
            return 0xffffffff;
          }
        }
      }
      if (0xbf < uVar12) break;
      if (uVar12 < 0x91) {
        if (uVar12 < 0x90) {
          if ((uVar12 == 0x80) && (iVar14 = FUN_037fe634(param_1,param_2), uVar13 != 0)) {
            if (uVar6 == 0x80) {
              *(int *)(param_1 + 0x20) = iVar14;
            }
            else if ((uVar6 == 0x81) && (iVar14 < 0x10000)) {
              *(short *)(param_1 + 2) = (short)iVar14;
            }
          }
        }
        else if (uVar6 == 0x93) {
          uVar12 = (uint)(param_1 + 0x28) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          uVar7 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
          uVar12 = (uint)(param_1 + 0x28) & 3;
          uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          *(uint *)(param_1 + 0x28) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 1;
          FUN_037fe73c((int)(uintptr_t)(param_1));
          if (((uVar13 != 0) &&
              (pbVar10 = (byte *)FUN_037fe2e4(param_2,uVar7), pbVar10 != (byte *)0x0)) &&
             (pbVar10 != param_1)) {
            FUN_037fe2c4((undefined4)(uintptr_t)(pbVar10),param_2);
            uVar13 = (uint)(param_1 + 0x24) & 3;
            uVar12 = *(uint *)((uint)(param_1 + 0x24) & 0xfffffffc);
            FUN_037fe52c(pbVar10,uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20);
          }
        }
        else if (uVar6 == 0x94) {
          iVar14 = FUN_037fe73c((int)(uintptr_t)(param_1));
          if (uVar13 != 0) {
            uVar13 = (uint)(param_1 + 0x24) & 3;
            uVar12 = *(uint *)((uint)(param_1 + 0x24) & 0xfffffffc);
            *(uint *)(param_1 + 0x28) =
                 (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + iVar14;
          }
        }
        else if (((uVar6 == 0x95) && (iVar14 = FUN_037fe73c((int)(uintptr_t)(param_1)), uVar13 != 0)) &&
                (param_1[0x3b] < 3)) {
          uVar13 = (uint)(param_1 + 0x28) & 3;
          uVar12 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          *(uint *)(param_1 + (uint)param_1[0x3b] * 4 + 0x2c) =
               uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
          param_1[0x3b] = param_1[0x3b] + 1;
          uVar13 = (uint)(param_1 + 0x24) & 3;
          uVar12 = *(uint *)((uint)(param_1 + 0x24) & 0xfffffffc);
          *(uint *)(param_1 + 0x28) = (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + iVar14
          ;
        }
      }
      else if (uVar12 == 0xb0) {
        uVar12 = (uint)(param_1 + 0x28) & 3;
        uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
        uVar7 = FUN_037fe7ec(uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20);
        uVar12 = (uint)(param_1 + 0x28) & 3;
        uVar5 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
        *(uint *)(param_1 + 0x28) = (uVar5 >> uVar12 * 8 | uVar5 << uVar12 * -8 + 0x20) + 1;
        sVar3 = FUN_037fe634(param_1,param_2);
        uVar12 = (uint)sVar3;
        psVar11 = (short *)FUN_037fd3c0(param_2,uVar7);
        if ((uVar13 != 0) && (psVar11 != (short *)0x0)) {
          switch(uVar6) {
          case 0xb0:
            *psVar11 = sVar3;
            break;
          case 0xb1:
            *psVar11 = *psVar11 + sVar3;
            break;
          case 0xb2:
            *psVar11 = *psVar11 - sVar3;
            break;
          case 0xb3:
            *psVar11 = *psVar11 * sVar3;
            break;
          case 0xb4:
            if (uVar12 != 0) {
              sVar3 = FUN_03806b2c((int)*psVar11,uVar12);
              *psVar11 = sVar3;
            }
            break;
          case 0xb5:
            if ((int)uVar12 < 0) {
              *psVar11 = (short)((int)*psVar11 >> (-uVar12 & 0xff));
            }
            else {
              *psVar11 = (short)((int)*psVar11 << (uVar12 & 0xff));
            }
            break;
          case 0xb6:
            bVar15 = (int)uVar12 < 0;
            if (bVar15) {
              uVar12 = (int)(uVar12 * -0x10000) >> 0x10;
            }
            iVar14 = FUN_037fbf70();
            sVar3 = (short)(iVar14 * (uVar12 + 1) >> 0x10);
            if (bVar15) {
              sVar3 = -sVar3;
            }
            *psVar11 = sVar3;
            break;
          case 0xb7:
            break;
          case 0xb8:
            *param_1 = *param_1 & 0xbf | ((int)*psVar11 == uVar12) << 6;
            break;
          case 0xb9:
            *param_1 = *param_1 & 0xbf | ((int)uVar12 <= (int)*psVar11) << 6;
            break;
          case 0xba:
            *param_1 = *param_1 & 0xbf | ((int)uVar12 < (int)*psVar11) << 6;
            break;
          case 0xbb:
            *param_1 = *param_1 & 0xbf | ((int)*psVar11 <= (int)uVar12) << 6;
            break;
          case 0xbc:
            *param_1 = *param_1 & 0xbf | ((int)*psVar11 < (int)uVar12) << 6;
            break;
          case 0xbd:
            *param_1 = *param_1 & 0xbf | ((int)*psVar11 != uVar12) << 6;
          }
        }
      }
    }
code_r0x037fd880:
    bVar1 = FUN_037fe634(param_1,param_2);
    if (uVar13 != 0) {
      switch(uVar6) {
      case 0xc0:
        param_1[8] = bVar1 - 0x40;
        break;
      case 0xc1:
        param_1[4] = bVar1;
        break;
      case 0xc2:
        *(byte *)(param_2 + 5) = bVar1;
        break;
      case 0xc3:
        param_1[0x13] = bVar1;
        break;
      case 0xc4:
        param_1[6] = bVar1;
        break;
      case 0xc5:
        param_1[7] = bVar1;
        break;
      case 0xc6:
        param_1[0x12] = bVar1;
        break;
      case 199:
        *param_1 = *param_1 & 0xfd | (byte)((bVar1 & 1) << 1);
        break;
      case 200:
        *param_1 = *param_1 & 0xf7 | (byte)((bVar1 & 1) << 3);
        FUN_037fe40c(param_1,param_2);
        FUN_037fe3d0((int)(uintptr_t)(param_1));
        break;
      case 0xc9:
        param_1[0x14] = bVar1 + param_1[0x13];
        *param_1 = *param_1 | 0x20;
        break;
      case 0xca:
        param_1[0x1a] = bVar1;
        break;
      case 0xcb:
        param_1[0x19] = bVar1;
        break;
      case 0xcc:
        param_1[0x18] = bVar1;
        break;
      case 0xcd:
        param_1[0x1b] = bVar1;
        break;
      case 0xce:
        *param_1 = *param_1 & 0xdf | (byte)((bVar1 & 1) << 5);
        break;
      case 0xcf:
        param_1[0x15] = bVar1;
        break;
      case 0xd0:
        param_1[0xe] = bVar1;
        break;
      case 0xd1:
        param_1[0xf] = bVar1;
        break;
      case 0xd2:
        param_1[0x10] = bVar1;
        break;
      case 0xd3:
        param_1[0x11] = bVar1;
        break;
      case 0xd4:
        if (param_1[0x3b] < 3) {
          uVar13 = (uint)(param_1 + 0x28) & 3;
          uVar12 = *(uint *)((uint)(param_1 + 0x28) & 0xfffffffc);
          *(uint *)(param_1 + (uint)param_1[0x3b] * 4 + 0x2c) =
               uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
          param_1[param_1[0x3b] + 0x38] = bVar1;
          param_1[0x3b] = param_1[0x3b] + 1;
        }
        break;
      case 0xd5:
        param_1[5] = bVar1;
        break;
      case 0xd6:
        if (*(uint *)(DAT_037fde34 & 0xfffffffc) >> (DAT_037fde34 & 3) * 8 != 0 ||
            *(uint *)(DAT_037fde34 & 0xfffffffc) << (DAT_037fde34 & 3) * -8 + 0x20 != 0) {
          FUN_037fd3c0(param_2,bVar1);
        }
      }
    }
  } while( true );
}

