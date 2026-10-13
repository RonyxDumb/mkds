/* Decompiled C draft; module arm9_ov000; ROM address 02194cac. No matching claim. */
#include "types.h"
#include "deps/02194cac_FUN_02194cac.h"

/* WARNING: Removing unreachable block (ram,0x02196044) */
/* WARNING: Removing unreachable block (ram,0x0219604e) */
/* WARNING: Type propagation algorithm not settling */

void FUN_02194cac(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  code *UNRECOVERED_JUMPTABLE_00;
  int iStack_4d0;
  int aiStack_478 [2];
  code *pcStack_470;
  undefined4 uStack_46c;
  undefined1 auStack_468 [4];
  undefined1 auStack_464 [4];
  int iStack_460;
  undefined4 uStack_45c;
  int iStack_458;
  undefined4 uStack_454;
  int iStack_450;
  undefined4 uStack_44c;
  int iStack_448;
  undefined4 uStack_444;
  int iStack_440;
  undefined4 uStack_43c;
  int iStack_438;
  undefined4 uStack_434;
  int iStack_430;
  undefined4 uStack_42c;
  undefined4 uStack_428;
  int iStack_424;
  int iStack_420;
  int iStack_41c;
  undefined1 auStack_418 [512];
  char acStack_218 [516];
  
  iVar3 = *param_1;
  piVar10 = *(int **)(param_2 + 4);
  iVar4 = FUN_021906e4(param_1,piVar10[1],piVar10 + 6,auStack_464,1,DAT_02195084);
  if (iVar4 != 0) {
    FUN_02196054();
  }
  iVar4 = *(int *)(param_2 + 0x14);
  if (iVar4 == 1) {
    iVar4 = FUN_02196714(param_1,piVar10[1],aiStack_478);
    if (iVar4 != 0) {
      FUN_02196054();
    }
    if (aiStack_478[0] == 4) {
      FUN_021965a0(param_1,DAT_02195088,DAT_0219508c);
      FUN_02190f4c(param_1,4,0);
                    /* WARNING: Could not recover jumptable at 0x02194d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(4);
      return;
    }
    if (aiStack_478[0] != 3) {
      FUN_02196040();
    }
    iVar4 = *piVar10;
    if (iVar4 == 1) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_02195090);
      FUN_02190b80(param_1,piVar10 + 6,DAT_02195094);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_02195098));
      FUN_02190b80(param_1,piVar10 + 6,DAT_0219509c);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950a0));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950a4);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950a8));
      if ((char)piVar10[10] != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950ac);
        FUN_02190b80(param_1,piVar10 + 6,piVar10 + 10);
      }
      if (*(char *)((int)piVar10 + 0x47) != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950b0);
        FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0x47);
      }
      if ((char)piVar10[0x17] != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950b4);
        FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x17);
      }
      if (*(char *)((int)piVar10 + 0x8f) != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950b8);
        FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0x8f);
      }
      if (*(char *)((int)piVar10 + 0xae) != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950bc);
        FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0xae);
      }
      if (*(int *)((int)piVar10 + DAT_021950c0) != 0) {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950c4);
        FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)((int)piVar10 + DAT_021950c0));
      }
      if (0 < *(int *)((int)piVar10 + DAT_021950c8)) {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021950cc);
        FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)((int)piVar10 + DAT_021950c8));
      }
    }
    else if (iVar4 == 2) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950d0);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950b4);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x17);
    }
    else if (iVar4 == 3) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950d4);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950b4);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x17);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950d8);
      FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0xcd);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950a4);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950a8));
    }
    else if (iVar4 == 4) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950dc);
      FUN_02190b80(param_1,piVar10 + 6,DAT_02195094);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_02195098));
      FUN_02190b80(param_1,piVar10 + 6,DAT_0219509c);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950a0));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950e0);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)((int)piVar10 + DAT_021950e4));
    }
    else if (iVar4 == 5) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950e8);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950ac);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 10);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950b4);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x17);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950d8);
      FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0xcd);
    }
    else if (iVar4 == 6) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950ec);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950ac);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 10);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950b4);
      FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x17);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950d8);
      FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0xcd);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950f0);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950f4));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950a4);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021950a8));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021950b0);
      FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0x47);
      if ((char)piVar10[0x3b] != '\0') {
        FUN_02190b80(param_1,piVar10 + 6,DAT_021954a8);
        FUN_02190b80(param_1,piVar10 + 6,piVar10 + 0x3b);
      }
    }
    else if (iVar4 == 7) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954ac);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954b0);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021954b4));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954b8);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021954bc));
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954c0);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021954c4));
    }
    else if (iVar4 == 8) {
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954c8);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954cc);
      FUN_02190b80(param_1,piVar10 + 6,(int)piVar10 + 0x47);
      FUN_02190b80(param_1,piVar10 + 6,DAT_021954c0);
      FUN_02190b58(param_1,piVar10 + 6,*(undefined4 *)(iVar3 + DAT_021954c4));
    }
    else {
      func_0x0213442c(DAT_021954d0,DAT_021954d4,0,DAT_021954d8);
    }
    FUN_02190b80(param_1,piVar10 + 6,DAT_021954dc);
    FUN_02190b80(param_1,piVar10 + 6,DAT_021954e0);
    FUN_02190b80(param_1,piVar10 + 6,DAT_021954e4);
    *(undefined4 *)(param_2 + 0x14) = 4;
    iVar4 = FUN_02196040();
  }
  if (iVar4 != 4) {
    FUN_02196040();
  }
  iVar4 = FUN_021907e8(param_1,piVar10[1],piVar10 + 2,auStack_468,auStack_464,DAT_021954e8);
  if (iVar4 != 0) {
    if (iVar4 != 3) {
      FUN_02196054();
    }
    FUN_021965a0(param_1,DAT_021954ec,DAT_021954f0);
    FUN_02190f4c(param_1,3,0);
                    /* WARNING: Could not recover jumptable at 0x02195260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(3);
    return;
  }
  iVar4 = func_0x02139f70(piVar10[2],DAT_021954e4);
  if (iVar4 == 0) {
    FUN_02196040();
  }
  aiStack_478[1] = 0;
  *(undefined4 *)(param_2 + 0x14) = 5;
  iVar4 = FUN_02196870(param_1,piVar10[2],1);
  if (iVar4 != 0) {
    *(undefined4 *)((int)piVar10 + DAT_021954f4) = 1;
                    /* WARNING: Could not recover jumptable at 0x0219529c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(4);
    return;
  }
  iVar4 = *piVar10;
  if (iVar4 == 1) {
    bVar2 = false;
    uStack_428 = 0;
    iStack_424 = 0;
    iStack_41c = 0;
    iStack_420 = DAT_021954f8;
    do {
      iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
      if (iVar4 != 0) {
        FUN_02196054();
      }
      iVar4 = func_0x0213a074(auStack_418,DAT_021954fc);
      if (iVar4 == 0) {
        iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
        if (iVar4 != 0) {
          FUN_02196054();
        }
        iVar4 = func_0x0213a074(auStack_418,DAT_02195500);
        if ((iVar4 == 0) && (iVar4 = func_0x0213a074(acStack_218,DAT_021954d0), iVar4 != 0)) {
          iStack_420 = DAT_02195504;
        }
        bVar2 = true;
      }
      else {
        iVar4 = func_0x0213a074(auStack_418,DAT_02195508);
        if (iVar4 != 0) {
          FUN_021965a0(param_1,1,DAT_02195524);
          FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195464. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        iStack_424 = iStack_424 + 1;
        iVar4 = FUN_021a3678(iStack_41c,iStack_424 * 0xac);
        iStack_41c = iVar4;
        if (iVar4 == 0) {
          FUN_02196590(param_1,DAT_0219550c);
                    /* WARNING: Could not recover jumptable at 0x02195354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(1);
          return;
        }
        iVar9 = (iStack_424 + -1) * 0xac;
        iVar8 = iVar4 + iVar9;
        func_0x02134de0(iVar8,0,0xac);
        uVar7 = func_0x0213bf90(acStack_218);
        *(undefined4 *)(iVar4 + iVar9) = uVar7;
        bVar1 = false;
        do {
          iVar4 = aiStack_478[1];
          iVar9 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
          if (iVar9 != 0) {
            FUN_02196054();
          }
          iVar9 = func_0x0213a074(auStack_418,DAT_02195510);
          if (iVar9 == 0) {
            FUN_02196914(iVar8 + 4,acStack_218,0x1f);
          }
          else {
            iVar9 = func_0x0213a074(auStack_418,DAT_02195514);
            if (iVar9 == 0) {
              FUN_02196914(iVar8 + 0x23,acStack_218,0x15);
            }
            else {
              iVar9 = func_0x0213a074(auStack_418,DAT_02195518);
              if (iVar9 == 0) {
                FUN_02196914(iVar8 + 0x38,acStack_218,0x1f);
              }
              else {
                iVar9 = func_0x0213a074(auStack_418,DAT_0219551c);
                if (iVar9 == 0) {
                  FUN_02196914(iVar8 + 0x57,acStack_218,0x1f);
                }
                else {
                  iVar9 = func_0x0213a074(auStack_418,DAT_02195520);
                  if (iVar9 == 0) {
                    FUN_02196914(iVar8 + 0x76,acStack_218,0x33);
                  }
                  else {
                    iVar9 = func_0x0213a074(auStack_418,DAT_02195508);
                    if ((iVar9 == 0) ||
                       (iVar9 = func_0x0213a074(auStack_418,DAT_021954fc), iVar9 == 0)) {
                      bVar1 = true;
                      aiStack_478[1] = iVar4;
                    }
                  }
                }
              }
            }
          }
        } while (!bVar1);
      }
      iVar4 = iStack_420;
    } while (!bVar2);
    pcStack_470 = *(code **)(param_2 + 0xc);
    uStack_46c = *(undefined4 *)(param_2 + 0x10);
    if (pcStack_470 != (code *)0x0) {
      (*pcStack_470)(param_1,&uStack_428);
    }
    if (((iVar4 == DAT_02195504) && (iStack_420 == DAT_02195504)) &&
       (iVar4 = FUN_021960a4(param_1,piVar10 + 10,(int)piVar10 + 0x47,piVar10 + 0x17,
                             (int)piVar10 + 0x8f,(int)piVar10 + 0xae,
                             *(undefined4 *)((int)piVar10 + DAT_02195528),
                             iStack_424 + *(int *)((int)piVar10 + DAT_0219552c),
                             *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                             *(undefined4 *)(param_2 + 0x10)), iVar4 != 0)) {
      FUN_02196054();
    }
    FUN_021a3668(iStack_41c);
    iStack_41c = 0;
    iVar4 = FUN_02196038();
  }
  if (iVar4 == 2) {
    iStack_430 = *(int *)(param_2 + 0xc);
    uStack_42c = *(undefined4 *)(param_2 + 0x10);
    if (iStack_430 == 0) {
      FUN_02196038();
    }
    iVar3 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
    if (iVar3 != 0) {
      FUN_02196054();
    }
    iVar3 = func_0x0213a074(auStack_418,DAT_02195918);
    if (iVar3 == 0) {
      puVar5 = (undefined4 *)FUN_021a3690(0x3c);
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0;
        FUN_02196914(puVar5 + 1,piVar10 + 0x17,0x33);
        if (acStack_218[0] == '0') {
          puVar5[0xe] = 0;
        }
        else {
          puVar5[0xe] = 1;
        }
        iVar3 = FUN_02190ed4(param_1,iStack_430,uStack_42c,puVar5,param_2,0);
        if (iVar3 == 0) {
          FUN_02196038();
        }
                    /* WARNING: Could not recover jumptable at 0x02195636. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
      FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021955ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(1);
      return;
    }
    FUN_021965a0(param_1,1,DAT_0219591c);
    FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x021955ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(3);
    return;
  }
  if (iVar4 == 3) {
    iStack_438 = *(int *)(param_2 + 0xc);
    uStack_434 = *(undefined4 *)(param_2 + 0x10);
    if (iStack_438 == 0) {
      FUN_02196038();
    }
    puVar5 = (undefined4 *)FUN_021a3690(0x44);
    if (puVar5 == (undefined4 *)0x0) {
      FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x02195670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(1);
      return;
    }
    *puVar5 = 0;
    func_0x0213a2d0(puVar5 + 1,piVar10 + 0x17);
    puVar5[0xe] = 0;
    puVar5[0xf] = 0;
    puVar5[0x10] = 0;
    iVar3 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
    if (iVar3 != 0) {
      FUN_02196054();
    }
    iVar3 = func_0x0213a074(auStack_418,DAT_02195924);
    if (iVar3 == 0) {
      bVar2 = false;
      do {
        iVar3 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
        if (iVar3 != 0) {
          FUN_02196054();
        }
        iVar3 = func_0x0213a074(auStack_418,DAT_02195928);
        if (iVar3 == 0) {
          iVar3 = FUN_021a3678(puVar5[0xf],(puVar5[0xe] + 1) * 4);
          if (iVar3 == 0) {
            FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219571c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          puVar5[0xf] = iVar3;
          iVar3 = FUN_021a3690(0x1f);
          if (iVar3 == 0) {
            FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219573e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          *(int *)(puVar5[0xf] + puVar5[0xe] * 4) = iVar3;
          FUN_02196914(*(undefined4 *)(puVar5[0xf] + puVar5[0xe] * 4),acStack_218,0x1f);
          puVar5[0xe] = puVar5[0xe] + 1;
        }
        else {
          iVar3 = func_0x0213a074(auStack_418,DAT_0219592c);
          if (iVar3 == 0) {
            if (0 < (int)puVar5[0xe]) {
              iVar3 = FUN_021a3678(puVar5[0x10],puVar5[0xe] << 2);
              if (iVar3 == 0) {
                FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x02195792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (*UNRECOVERED_JUMPTABLE_00)(1);
                return;
              }
              puVar5[0x10] = iVar3;
              iVar3 = FUN_021a3690(0x15);
              if (iVar3 == 0) {
                FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021957b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                (*UNRECOVERED_JUMPTABLE_00)(1);
                return;
              }
              *(int *)(puVar5[0x10] + (puVar5[0xe] + -1) * 4) = iVar3;
              FUN_02196914(*(undefined4 *)(puVar5[0x10] + (puVar5[0xe] + -1) * 4),acStack_218,0x15);
            }
          }
          else {
            iVar3 = func_0x0213a074(auStack_418,DAT_02195930);
            if (iVar3 != 0) {
              FUN_021965a0(param_1,1,DAT_0219591c);
              FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*UNRECOVERED_JUMPTABLE_00)(3);
              return;
            }
            bVar2 = true;
          }
        }
        if (bVar2) {
          iVar3 = FUN_02190ed4(param_1,iStack_438,uStack_434,puVar5,param_2,3);
          if (iVar3 == 0) {
            FUN_02196038();
          }
                    /* WARNING: Could not recover jumptable at 0x02195836. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)();
          return;
        }
      } while( true );
    }
    FUN_021965a0(param_1,1,DAT_0219591c);
    FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x021956cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(3);
    return;
  }
  if (iVar4 == 4) {
    iStack_440 = *(int *)(param_2 + 0xc);
    uStack_43c = *(undefined4 *)(param_2 + 0x10);
    if (iStack_440 != 0) {
      puVar5 = (undefined4 *)FUN_021a3690(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219586e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      puVar5[1] = *(undefined4 *)((int)piVar10 + DAT_02195934);
      bVar2 = false;
      *puVar5 = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      do {
        iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
        if (iVar4 != 0) goto code_r0x02196054;
        iVar3 = func_0x0213a074(auStack_418,DAT_02195938);
        if (iVar3 == 0) {
          bVar2 = true;
        }
        else {
          iVar3 = func_0x0213a074(auStack_418,DAT_0219593c);
          if (iVar3 != 0) {
            FUN_021965a0(param_1,1,DAT_02195cf0);
            FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195a04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          puVar5[2] = puVar5[2] + 1;
          uVar7 = FUN_021a3678(puVar5[3],DAT_02195940 * puVar5[2]);
          puVar5[3] = uVar7;
          iVar3 = puVar5[3];
          if (iVar3 == 0) {
            FUN_02196590(param_1,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021958fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          iVar4 = DAT_02195940 * (puVar5[2] + -1);
          iVar9 = iVar3 + iVar4;
          func_0x02134de0(iVar9,0,DAT_02195940);
          *(undefined4 *)(iVar9 + 0x24) = 1;
          uVar7 = func_0x0213bf90(acStack_218);
          *(undefined4 *)(iVar3 + iVar4) = uVar7;
          bVar1 = false;
          do {
            iVar3 = aiStack_478[1];
            iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
            if (iVar4 != 0) goto code_r0x02196054;
            iVar4 = func_0x0213a074(auStack_418,DAT_02195cd8);
            if (iVar4 == 0) {
              FUN_02196914(iVar9 + 0x28,acStack_218,DAT_02195cdc);
            }
            else {
              iVar4 = func_0x0213a074(auStack_418,DAT_02195ce0);
              if (iVar4 == 0) {
                FUN_02196914(iVar9 + 4,acStack_218,0x1f);
              }
            }
            iVar4 = func_0x0213a074(auStack_418,DAT_02195ce4);
            if (iVar4 == 0) {
              uVar7 = func_0x0213bf90(acStack_218);
              *(undefined4 *)(iVar9 + 0x24) = uVar7;
            }
            else {
              iVar4 = func_0x0213a074(auStack_418,DAT_02195ce8);
              if ((iVar4 == 0) || (iVar4 = func_0x0213a074(auStack_418,DAT_02195cec), iVar4 == 0)) {
                bVar1 = true;
                aiStack_478[1] = iVar3;
              }
            }
          } while (!bVar1);
        }
      } while (!bVar2);
      iVar3 = FUN_02190ed4(param_1,iStack_440,uStack_43c,puVar5,param_2,4);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195a32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar4 == 5) {
    iStack_448 = *(int *)(param_2 + 0xc);
    uStack_444 = *(undefined4 *)(param_2 + 0x10);
    if (iStack_448 != 0) {
      iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
      if (iVar4 != 0) goto code_r0x02196054;
      iVar4 = func_0x0213a074(auStack_418,DAT_02195cf4);
      if (iVar4 != 0) {
        FUN_021965a0(param_1,1,DAT_02195cf0);
        FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195a8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      iVar4 = func_0x0213bf90(acStack_218);
      if (iVar4 == 0) {
        iVar3 = FUN_021967b4(piVar10[2],DAT_02195cfc,acStack_218,DAT_02195d00);
        if (iVar3 == 0) {
          FUN_021965a0(param_1,1,DAT_02195cf0);
          FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195ad2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        iVar3 = func_0x0213bf90(acStack_218);
      }
      else {
        *(int *)(iVar3 + DAT_02195cf8) = iVar4;
        iVar3 = 0;
      }
      piVar6 = (int *)FUN_021a3690(8);
      if (piVar6 == (int *)0x0) {
        FUN_02196590(param_1,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *piVar6 = iVar4;
      piVar6[1] = iVar3;
      iVar3 = FUN_02190ed4(param_1,iStack_448,uStack_444,piVar6,param_2,0);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar4 == 6) {
    iStack_450 = *(int *)(param_2 + 0xc);
    uStack_44c = *(undefined4 *)(param_2 + 0x10);
    if (iStack_450 != 0) {
      iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
      if (iVar4 != 0) goto code_r0x02196054;
      iVar4 = func_0x0213a074(auStack_418,DAT_02195d08);
      if (iVar4 != 0) {
        FUN_021965a0(param_1,1,DAT_02195cf0);
        FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195b7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      iVar4 = func_0x0213bf90(acStack_218);
      if (iVar4 != 0) {
        *(int *)(iVar3 + DAT_02195cf8) = iVar4;
      }
      iVar3 = FUN_021967b4(piVar10[2],DAT_02195cfc,acStack_218,DAT_02195d00);
      if (iVar3 == 0) {
        if (iVar4 == 0) {
          FUN_021965a0(param_1,1,DAT_02195cf0);
          FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195bc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        iVar3 = 0;
      }
      else {
        iVar3 = func_0x0213bf90(acStack_218);
      }
      piVar6 = (int *)FUN_021a3690(8);
      if (piVar6 == (int *)0x0) {
        FUN_02196590(param_1,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195bf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *piVar6 = iVar4;
      piVar6[1] = iVar3;
      iVar3 = FUN_02190ed4(param_1,iStack_450,uStack_44c,piVar6,param_2,0);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195c1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar4 == 7) {
    iStack_458 = *(int *)(param_2 + 0xc);
    uStack_454 = *(undefined4 *)(param_2 + 0x10);
    if (iStack_458 != 0) {
      puVar5 = (undefined4 *)FUN_021a3690(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195c52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
      if (iVar4 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(auStack_418,DAT_02195d0c);
      if (iVar3 != 0) {
        FUN_021965a0(param_1,1,DAT_02195cf0);
        FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195c9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      bVar2 = false;
      do {
        iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
        if (iVar4 != 0) goto code_r0x02196054;
        iVar3 = func_0x0213a074(auStack_418,DAT_02195d10);
        if (iVar3 == 0) {
          bVar2 = true;
        }
        else {
          iVar3 = func_0x0213a074(auStack_418,DAT_02195d14);
          if (iVar3 != 0) {
            FUN_021965a0(param_1,1,DAT_02196080);
            FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195e6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          iVar3 = FUN_021a3678(puVar5[2],(puVar5[1] + 1) * 0xac);
          if (iVar3 == 0) {
            FUN_02196590(param_1,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          puVar5[2] = iVar3;
          iVar3 = puVar5[2];
          iVar4 = puVar5[1];
          iVar9 = iVar3 + iVar4 * 0xac;
          func_0x02134de0(iVar9,0,0xac);
          puVar5[1] = puVar5[1] + 1;
          uVar7 = func_0x0213bf90(acStack_218);
          *(undefined4 *)(iVar3 + iVar4 * 0xac) = uVar7;
          bVar1 = false;
          do {
            iVar3 = aiStack_478[1];
            iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
            if (iVar4 != 0) goto code_r0x02196054;
            iVar4 = func_0x0213a074(auStack_418,DAT_02196064);
            if (iVar4 == 0) {
              FUN_02196914(iVar9 + 4,acStack_218,0x1f);
            }
            else {
              iVar4 = func_0x0213a074(auStack_418,DAT_02196068);
              if (iVar4 == 0) {
                FUN_02196914(iVar9 + 0x23,acStack_218,0x15);
              }
              else {
                iVar4 = func_0x0213a074(auStack_418,DAT_0219606c);
                if (iVar4 == 0) {
                  FUN_02196914(iVar9 + 0x38,acStack_218,0x1f);
                }
                else {
                  iVar4 = func_0x0213a074(auStack_418,DAT_02196070);
                  if (iVar4 == 0) {
                    FUN_02196914(iVar9 + 0x57,acStack_218,0x1f);
                  }
                  else {
                    iVar4 = func_0x0213a074(auStack_418,DAT_02196074);
                    if (iVar4 == 0) {
                      FUN_02196914(iVar9 + 0x76,acStack_218,0x33);
                    }
                    else {
                      iVar4 = func_0x0213a074(auStack_418,DAT_02196078);
                      if ((iVar4 == 0) ||
                         (iVar4 = func_0x0213a074(auStack_418,DAT_0219607c), iVar4 == 0)) {
                        bVar1 = true;
                        aiStack_478[1] = iVar3;
                      }
                    }
                  }
                }
              }
            }
          } while (!bVar1);
        }
      } while (!bVar2);
      iVar3 = FUN_02190ed4(param_1,iStack_458,uStack_454,puVar5,param_2,8);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195e9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar4 == 8) {
    iStack_460 = *(int *)(param_2 + 0xc);
    uStack_45c = *(undefined4 *)(param_2 + 0x10);
    if (iStack_460 != 0) {
      iStack_4d0 = 0;
      puVar5 = (undefined4 *)FUN_021a3690(0xc);
      if (puVar5 == (undefined4 *)0x0) {
        FUN_02196590(param_1,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
      if (iVar4 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(auStack_418,DAT_02196084);
      if (iVar3 != 0) {
        FUN_021965a0(param_1,1,DAT_02196080);
        FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      uVar7 = func_0x0213bf90(acStack_218);
      puVar5[1] = uVar7;
      uVar7 = FUN_021a3690(puVar5[1] << 2);
      puVar5[2] = uVar7;
      if (puVar5[2] == 0) {
        FUN_02196590(param_1,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195f52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      iVar3 = 0;
      bVar2 = false;
      do {
        iVar4 = FUN_021965c8(param_1,piVar10[2],aiStack_478 + 1,auStack_418,acStack_218);
        if (iVar4 != 0) goto code_r0x02196054;
        iVar4 = func_0x0213a074(auStack_418,DAT_02196064);
        if (iVar4 == 0) {
          uVar7 = FUN_021a3690(0x15);
          *(undefined4 *)(puVar5[2] + iVar3) = uVar7;
          if (*(int *)(puVar5[2] + iVar3) == 0) {
            FUN_02196590(param_1,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195fa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          FUN_02196914(*(int *)(puVar5[2] + iVar3),acStack_218,0x15);
          iVar3 = iVar3 + 4;
          iStack_4d0 = iStack_4d0 + 1;
        }
        else {
          iVar4 = func_0x0213a074(auStack_418,DAT_02196088);
          if (iVar4 != 0) {
            FUN_021965a0(param_1,1,DAT_02196080);
            FUN_02190f4c(param_1,3,1);
                    /* WARNING: Could not recover jumptable at 0x02196000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          if (iStack_4d0 != puVar5[1]) {
            func_0x0213442c(DAT_0219608c,DAT_02196090,0,DAT_02196094);
          }
          puVar5[1] = iStack_4d0;
          bVar2 = true;
        }
      } while (!bVar2);
      iVar3 = FUN_02190ed4(param_1,iStack_460,uStack_45c,puVar5,param_2,9);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0219602a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else {
    func_0x0213442c(DAT_02196098,DAT_02196090,0,DAT_0219609c);
  }
  *(undefined4 *)((int)piVar10 + DAT_021960a0) = 1;
  iVar4 = 0;
code_r0x02196054:
                    /* WARNING: Could not recover jumptable at 0x0219605e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(iVar4);
  return;
}

