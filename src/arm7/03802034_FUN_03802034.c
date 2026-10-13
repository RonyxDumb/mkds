/* Decompiled C draft; module arm7; ROM address 03802034. No matching claim. */
#include "types.h"
#include "deps/03802034_FUN_03802034.h"

undefined4 FUN_03802034(ushort *param_1,int param_2,int param_3,undefined2 *param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_38 [6];
  
  puVar1 = DAT_03802218;
  if (param_3 == 0) {
    uVar4 = 0xd1;
    uVar5 = 1;
  }
  else {
    uVar4 = 0x91;
    uVar5 = 2;
  }
  do {
  } while ((*DAT_03802218 & 0x80) != 0);
  *DAT_03802218 = (ushort)DAT_0380221c;
  *DAT_03802220 = uVar4;
  uVar8 = DAT_03802224;
  puVar3 = DAT_03802220;
  puVar2 = DAT_03802218;
  do {
  } while ((*puVar1 & 0x80) != 0);
  iVar6 = 0;
  do {
    *puVar3 = 0;
    do {
    } while ((*puVar2 & 0x80) != 0);
    local_38[iVar6] = ((*puVar3 & 0xff) << 0x10) >> 8;
    *puVar3 = uVar4;
    do {
    } while ((*puVar2 & 0x80) != 0);
    local_38[iVar6] = local_38[iVar6] | *puVar3 & 0xff;
    local_38[iVar6] = (int)(local_38[iVar6] & uVar8) >> 3;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  *puVar2 = (ushort)DAT_03802228;
  *puVar3 = 0;
  do {
  } while ((*DAT_03802218 & 0x80) != 0);
  iVar6 = 0;
  iVar7 = 0;
  do {
    iVar9 = iVar7;
    while (iVar9 = iVar9 + 1, iVar9 < 5) {
      iVar10 = local_38[iVar7] - local_38[iVar9];
      if (iVar10 < 0) {
        iVar10 = -iVar10;
      }
      if (iVar6 < iVar10) {
        iVar6 = iVar10;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  *param_4 = (short)iVar6;
  iVar6 = 0;
  do {
    if (2 < iVar6) {
      *param_1 = (ushort)((int)(local_38[0] + local_38[4]) >> 1) & 0xfff8;
      return uVar5;
    }
    uVar8 = local_38[iVar6];
    iVar7 = iVar6;
    while (iVar7 = iVar7 + 1, iVar7 < 4) {
      iVar9 = uVar8 - local_38[iVar7];
      if (iVar9 < 0) {
        iVar9 = -iVar9;
      }
      iVar10 = iVar7;
      if (iVar9 <= param_2) {
        while (iVar10 = iVar10 + 1, iVar10 < 5) {
          iVar9 = uVar8 - local_38[iVar10];
          if (iVar9 < 0) {
            iVar9 = -iVar9;
          }
          if (iVar9 <= param_2) {
            *param_1 = (ushort)((int)(local_38[iVar10] + local_38[iVar7] + uVar8 * 2) >> 2) & 0xfff8
            ;
            return 0;
          }
        }
      }
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

