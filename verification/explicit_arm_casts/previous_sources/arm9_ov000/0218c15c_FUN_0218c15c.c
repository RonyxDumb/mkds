/* Decompiled C draft; module arm9_ov000; ROM address 0218c15c. No matching claim. */
#include "types.h"
#include "deps/0218c15c_FUN_0218c15c.h"

undefined4 FUN_0218c15c(undefined4 *param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  ushort *puVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 local_20;
  uint local_1c;
  
  pbVar8 = (byte *)param_1[0x1f];
  iVar9 = param_1[0x20];
  switch(*(undefined4 *)((int)param_1 + DAT_0218c424)) {
  case 0:
    if (iVar9 < 1) goto switchD_0218c180_default;
    iVar3 = (*pbVar8 ^ 0xec) + 2;
    if ((iVar9 < iVar3) || (iVar7 = iVar3 + (pbVar8[(*pbVar8 ^ 0xec) + 1] ^ 0xea), iVar9 < iVar7))
    goto switchD_0218c180_default;
    FUN_0218c8e0(param_1,pbVar8 + iVar3);
    *(undefined4 *)((int)param_1 + DAT_0218c424) = 1;
    pbVar8 = pbVar8 + iVar7;
    iVar9 = iVar9 - iVar7;
    FUN_0218a6f4((int)param_1 + DAT_0218c428,pbVar8,iVar9);
    break;
  case 1:
    break;
  case 2:
    goto switchD_0218c180_caseD_2;
  case 3:
    goto switchD_0218c180_caseD_3;
  case 4:
    goto switchD_0218c180_caseD_4;
  default:
    goto switchD_0218c180_default;
  }
  if (iVar9 < 6) goto switchD_0218c180_default;
  pbVar1 = (byte *)((int)param_1 + DAT_0218c42c);
  *pbVar1 = *pbVar8;
  pbVar1[1] = pbVar8[1];
  pbVar1[2] = pbVar8[2];
  pbVar1[3] = pbVar8[3];
  (**(code **)((int)param_1 + DAT_0218c438))
            (param_1,6,*DAT_0218c430,*(undefined4 *)((int)param_1 + DAT_0218c434));
  puVar6 = (ushort *)((int)param_1 + DAT_0218c43c);
  *(byte *)puVar6 = pbVar8[4];
  *(byte *)((int)puVar6 + 1) = pbVar8[5];
  if (*puVar6 == DAT_0218c440) {
    iVar3 = FUN_0218d0c8(pbVar8 + 6,iVar9 + -6);
    if (iVar3 == -1) goto switchD_0218c180_default;
    FUN_0218c45c(param_1,pbVar8 + 6);
    (**(code **)((int)param_1 + DAT_0218c438))
              (param_1,5,*DAT_0218c430,*(undefined4 *)((int)param_1 + DAT_0218c434));
    if (param_1[0x1f] == 0) goto switchD_0218c180_default;
  }
  pbVar8 = pbVar8 + 6;
  iVar9 = iVar9 + -6;
  if (((*(uint *)((int)param_1 + DAT_0218c444) & 2) == 0) &&
     (*(ushort *)((int)param_1 + DAT_0218c43c) != DAT_0218c440)) {
    *(undefined4 *)((int)param_1 + DAT_0218c424) = 2;
    *(undefined4 *)((int)param_1 + DAT_0218c448) = 0xffffffff;
switchD_0218c180_caseD_2:
    puVar4 = (uint *)((int)param_1 + DAT_0218c448);
    if (*puVar4 == 0xffffffff) {
      if (iVar9 < 1) goto switchD_0218c180_default;
      *puVar4 = (uint)*pbVar8;
      uVar2 = FUN_0218dc94(8,*puVar4);
      param_1[2] = uVar2;
      if (param_1[2] == 0) {
        return 5;
      }
      pbVar8 = pbVar8 + 1;
      iVar9 = iVar9 + -1;
    }
    iVar3 = FUN_0218dc44(param_1[2]);
    if (iVar3 < *(int *)((int)param_1 + DAT_0218c448)) {
      do {
        if ((iVar9 < 2) || (iVar3 = FUN_0218d0c8(pbVar8 + 1,iVar9 + -1), iVar3 == -1)) break;
        local_1c = (uint)*pbVar8;
        local_20 = FUN_0218d134(param_1,pbVar8 + 1);
        FUN_0218dbc0(param_1[2],&local_20);
        pbVar8 = pbVar8 + iVar3 + 1;
        iVar9 = iVar9 - (iVar3 + 1);
        iVar3 = FUN_0218dc44(param_1[2]);
      } while (iVar3 < *(int *)((int)param_1 + DAT_0218c448));
    }
    iVar3 = FUN_0218dc44(param_1[2]);
    piVar5 = (int *)((int)param_1 + DAT_0218c448);
    if (*piVar5 <= iVar3) {
      *(undefined4 *)((int)param_1 + DAT_0218c424) = 3;
      *piVar5 = -1;
switchD_0218c180_caseD_3:
      if (*(uint *)((int)param_1 + DAT_0218c448) == 0xffffffff) {
        if (iVar9 < 1) goto switchD_0218c180_default;
        *(uint *)((int)param_1 + DAT_0218c448) = (uint)*pbVar8;
        *(undefined4 *)((int)param_1 + DAT_0218c44c) = 0;
        pbVar8 = pbVar8 + 1;
        iVar9 = iVar9 + -1;
      }
      if (*(int *)((int)param_1 + DAT_0218c44c) < *(int *)((int)param_1 + DAT_0218c448)) {
        do {
          iVar3 = FUN_0218d0c8(pbVar8,iVar9);
          if (iVar3 == -1) break;
          uVar2 = FUN_0218d134(param_1,pbVar8);
          iVar7 = *(int *)((int)param_1 + DAT_0218c44c);
          *(int *)((int)param_1 + DAT_0218c44c) = iVar7 + 1;
          param_1[iVar7 + 0x21] = uVar2;
          pbVar8 = pbVar8 + iVar3;
          iVar9 = iVar9 - iVar3;
        } while (*(int *)((int)param_1 + DAT_0218c44c) < *(int *)((int)param_1 + DAT_0218c448));
      }
      if (*(int *)((int)param_1 + DAT_0218c448) <= *(int *)((int)param_1 + DAT_0218c44c)) {
        *(undefined4 *)((int)param_1 + DAT_0218c424) = 4;
switchD_0218c180_caseD_4:
        if (4 < iVar9) {
          do {
            iVar3 = FUN_0218c468(param_1,pbVar8,iVar9);
            if (iVar3 == -2) {
              return 5;
            }
            if (iVar3 == -1) {
              iVar9 = iVar9 + -5;
              pbVar8 = pbVar8 + 5;
              *(undefined4 *)((int)param_1 + DAT_0218c424) = 5;
              *param_1 = 2;
              (**(code **)((int)param_1 + DAT_0218c438))
                        (param_1,3,*DAT_0218c430,*(undefined4 *)((int)param_1 + DAT_0218c434));
              break;
            }
            pbVar8 = pbVar8 + iVar3;
            iVar9 = iVar9 - iVar3;
            if (param_1[0x1f] == 0) {
              iVar3 = 0;
            }
          } while (iVar3 != 0);
        }
      }
    }
  }
  else {
    *(undefined4 *)((int)param_1 + DAT_0218c424) = 5;
    *param_1 = 2;
  }
switchD_0218c180_default:
  if (iVar9 < 0) {
    func_0x0213442c(DAT_0218c450,DAT_0218c454,0,DAT_0218c458);
  }
  if (param_1[0x1f] != 0) {
    if (iVar9 != 0) {
      func_0x02134df8(param_1[0x1f],pbVar8,iVar9);
    }
    param_1[0x20] = iVar9;
    return 0;
  }
  return 0;
}

