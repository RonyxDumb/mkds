/* Decompiled C draft; module arm9_ov000; ROM address 02194ccc. No matching claim. */
#include "types.h"
#include "deps/02194ccc_FUN_02194ccc.h"

/* WARNING: Removing unreachable block (ram,0x02196044) */
/* WARNING: Removing unreachable block (ram,0x0219604e) */

void FUN_02194ccc(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *unaff_r5;
  int iVar8;
  undefined4 unaff_r7;
  undefined1 *puStack00000000;
  int iStack00000004;
  undefined1 *in_stack_0000001c;
  int in_stack_00000028;
  int iStack00000038;
  int in_stack_00000090;
  undefined4 in_stack_00000094;
  code *in_stack_00000098;
  undefined4 in_stack_0000009c;
  int in_stack_000000a8;
  undefined4 in_stack_000000ac;
  int in_stack_000000b0;
  undefined4 in_stack_000000b4;
  int in_stack_000000b8;
  undefined4 in_stack_000000bc;
  int in_stack_000000c0;
  undefined4 in_stack_000000c4;
  int in_stack_000000c8;
  undefined4 in_stack_000000cc;
  int in_stack_000000d0;
  undefined4 in_stack_000000d4;
  int in_stack_000000d8;
  undefined4 in_stack_000000dc;
  undefined4 in_stack_000000e0;
  int in_stack_000000e4;
  int in_stack_000000e8;
  int in_stack_000000ec;
  char in_stack_000002f0;
  code *UNRECOVERED_JUMPTABLE_00;
  
  puStack00000000 = (undefined1 *)0x1;
  iStack00000004 = DAT_02195084;
  iVar3 = FUN_021906e4(unaff_r7,unaff_r5[1],unaff_r5 + 6,&stack0x000000a4);
  if (iVar3 != 0) {
    FUN_02196054();
  }
  iVar3 = *(int *)(in_stack_0000001c + 0x14);
  if (iVar3 == 1) {
    iVar3 = FUN_02196714(unaff_r7,unaff_r5[1],&stack0x00000090);
    if (iVar3 != 0) {
      FUN_02196054();
    }
    if (in_stack_00000090 == 4) {
      FUN_021965a0(unaff_r7,DAT_02195088,DAT_0219508c);
      FUN_02190f4c(unaff_r7,4,0);
                    /* WARNING: Could not recover jumptable at 0x02194d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(4);
      return;
    }
    if (in_stack_00000090 != 3) {
      FUN_02196040();
    }
    iVar3 = *unaff_r5;
    if (iVar3 == 1) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_02195090);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_02195094);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_02195098));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_0219509c);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950a0));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950a4);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950a8));
      if ((char)unaff_r5[10] != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950ac);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 10);
      }
      if (*(char *)((int)unaff_r5 + 0x47) != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b0);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0x47);
      }
      if ((char)unaff_r5[0x17] != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b4);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x17);
      }
      if (*(char *)((int)unaff_r5 + 0x8f) != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b8);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0x8f);
      }
      if (*(char *)((int)unaff_r5 + 0xae) != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950bc);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0xae);
      }
      if (*(int *)((int)unaff_r5 + DAT_021950c0) != 0) {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950c4);
        FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)((int)unaff_r5 + DAT_021950c0));
      }
      if (0 < *(int *)((int)unaff_r5 + DAT_021950c8)) {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950cc);
        FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)((int)unaff_r5 + DAT_021950c8));
      }
    }
    else if (iVar3 == 2) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950d0);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b4);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x17);
    }
    else if (iVar3 == 3) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950d4);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b4);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x17);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950d8);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0xcd);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950a4);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950a8));
    }
    else if (iVar3 == 4) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950dc);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_02195094);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_02195098));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_0219509c);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950a0));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950e0);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)((int)unaff_r5 + DAT_021950e4));
    }
    else if (iVar3 == 5) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950e8);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950ac);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 10);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b4);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x17);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950d8);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0xcd);
    }
    else if (iVar3 == 6) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950ec);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950ac);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 10);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b4);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x17);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950d8);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0xcd);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950f0);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950f4));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950a4);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021950a8));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021950b0);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0x47);
      if ((char)unaff_r5[0x3b] != '\0') {
        FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954a8);
        FUN_02190b80(unaff_r7,unaff_r5 + 6,unaff_r5 + 0x3b);
      }
    }
    else if (iVar3 == 7) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954ac);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954b0);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021954b4));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954b8);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021954bc));
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954c0);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021954c4));
    }
    else if (iVar3 == 8) {
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954c8);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954cc);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,(int)unaff_r5 + 0x47);
      FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954c0);
      FUN_02190b58(unaff_r7,unaff_r5 + 6,*(undefined4 *)(in_stack_00000028 + DAT_021954c4));
    }
    else {
      func_0x0213442c(DAT_021954d0,DAT_021954d4,0,DAT_021954d8);
    }
    FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954dc);
    FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954e0);
    FUN_02190b80(unaff_r7,unaff_r5 + 6,DAT_021954e4);
    *(undefined4 *)(in_stack_0000001c + 0x14) = 4;
    iVar3 = FUN_02196040();
  }
  if (iVar3 != 4) {
    FUN_02196040();
  }
  puStack00000000 = &stack0x000000a4;
  iStack00000004 = DAT_021954e8;
  iVar3 = FUN_021907e8(unaff_r7,unaff_r5[1],unaff_r5 + 2,&stack0x000000a0);
  if (iVar3 != 0) {
    if (iVar3 != 3) {
      FUN_02196054();
    }
    FUN_021965a0(unaff_r7,DAT_021954ec,DAT_021954f0);
    FUN_02190f4c(unaff_r7,3,0);
                    /* WARNING: Could not recover jumptable at 0x02195260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(3);
    return;
  }
  iVar3 = func_0x02139f70(unaff_r5[2],DAT_021954e4);
  if (iVar3 == 0) {
    FUN_02196040();
  }
  in_stack_00000094 = 0;
  *(undefined4 *)(in_stack_0000001c + 0x14) = 5;
  iVar3 = FUN_02196870(unaff_r7,unaff_r5[2],1);
  if (iVar3 != 0) {
    *(undefined4 *)((int)unaff_r5 + DAT_021954f4) = 1;
                    /* WARNING: Could not recover jumptable at 0x0219529c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(4);
    return;
  }
  iVar3 = *unaff_r5;
  if (iVar3 == 1) {
    bVar2 = false;
    in_stack_000000e0 = 0;
    in_stack_000000e4 = 0;
    in_stack_000000ec = 0;
    in_stack_000000e8 = DAT_021954f8;
    do {
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) {
        FUN_02196054();
      }
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_021954fc);
      if (iVar3 == 0) {
        puStack00000000 = &stack0x000002f0;
        iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
        if (iVar3 != 0) {
          FUN_02196054();
        }
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195500);
        if ((iVar3 == 0) && (iVar3 = func_0x0213a074(&stack0x000002f0,DAT_021954d0), iVar3 != 0)) {
          in_stack_000000e8 = DAT_02195504;
        }
        bVar2 = true;
      }
      else {
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195508);
        if (iVar3 != 0) {
          FUN_021965a0(unaff_r7,1,DAT_02195524);
          FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195464. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        in_stack_000000e4 = in_stack_000000e4 + 1;
        iVar3 = FUN_021a3678(in_stack_000000ec,in_stack_000000e4 * 0xac);
        in_stack_000000ec = iVar3;
        if (iVar3 == 0) {
          FUN_02196590(unaff_r7,DAT_0219550c);
                    /* WARNING: Could not recover jumptable at 0x02195354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(1);
          return;
        }
        iVar8 = (in_stack_000000e4 + -1) * 0xac;
        iVar7 = iVar3 + iVar8;
        func_0x02134de0(iVar7,0,0xac);
        uVar6 = func_0x0213bf90(&stack0x000002f0);
        *(undefined4 *)(iVar3 + iVar8) = uVar6;
        bVar1 = false;
        do {
          uVar6 = in_stack_00000094;
          puStack00000000 = &stack0x000002f0;
          iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
          if (iVar3 != 0) {
            FUN_02196054();
          }
          iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195510);
          if (iVar3 == 0) {
            FUN_02196914(iVar7 + 4,&stack0x000002f0,0x1f);
          }
          else {
            iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195514);
            if (iVar3 == 0) {
              FUN_02196914(iVar7 + 0x23,&stack0x000002f0,0x15);
            }
            else {
              iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195518);
              if (iVar3 == 0) {
                FUN_02196914(iVar7 + 0x38,&stack0x000002f0,0x1f);
              }
              else {
                iVar3 = func_0x0213a074(&stack0x000000f0,DAT_0219551c);
                if (iVar3 == 0) {
                  FUN_02196914(iVar7 + 0x57,&stack0x000002f0,0x1f);
                }
                else {
                  iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195520);
                  if (iVar3 == 0) {
                    FUN_02196914(iVar7 + 0x76,&stack0x000002f0,0x33);
                  }
                  else {
                    iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195508);
                    if ((iVar3 == 0) ||
                       (iVar3 = func_0x0213a074(&stack0x000000f0,DAT_021954fc), iVar3 == 0)) {
                      bVar1 = true;
                      in_stack_00000094 = uVar6;
                    }
                  }
                }
              }
            }
          }
        } while (!bVar1);
      }
      iVar3 = in_stack_000000e8;
    } while (!bVar2);
    in_stack_00000098 = *(code **)(in_stack_0000001c + 0xc);
    in_stack_0000009c = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_00000098 != (code *)0x0) {
      (*in_stack_00000098)(unaff_r7,&stack0x000000e0);
    }
    if ((iVar3 == DAT_02195504) && (in_stack_000000e8 == DAT_02195504)) {
      puStack00000000 = (undefined1 *)((int)unaff_r5 + 0x8f);
      iStack00000004 = (int)unaff_r5 + 0xae;
      iVar3 = FUN_021960a4(unaff_r7,unaff_r5 + 10,(int)unaff_r5 + 0x47,unaff_r5 + 0x17);
      if (iVar3 != 0) {
        FUN_02196054();
      }
    }
    FUN_021a3668(in_stack_000000ec);
    in_stack_000000ec = 0;
    iVar3 = FUN_02196038();
  }
  if (iVar3 == 2) {
    in_stack_000000d8 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000dc = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000d8 == 0) {
      FUN_02196038();
    }
    puStack00000000 = &stack0x000002f0;
    iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
    if (iVar3 != 0) {
      FUN_02196054();
    }
    iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195918);
    if (iVar3 != 0) {
      FUN_021965a0(unaff_r7,1,DAT_0219591c);
      FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x021955ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(3);
      return;
    }
    puVar4 = (undefined4 *)FUN_021a3690(0x3c);
    if (puVar4 == (undefined4 *)0x0) {
      FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021955ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(1);
      return;
    }
    *puVar4 = 0;
    FUN_02196914(puVar4 + 1,unaff_r5 + 0x17,0x33);
    if (in_stack_000002f0 == '0') {
      puVar4[0xe] = 0;
    }
    else {
      puVar4[0xe] = 1;
    }
    puStack00000000 = in_stack_0000001c;
    iStack00000004 = 0;
    iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000d8,in_stack_000000dc,puVar4);
    if (iVar3 == 0) {
      FUN_02196038();
    }
                    /* WARNING: Could not recover jumptable at 0x02195636. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
  if (iVar3 == 3) {
    in_stack_000000d0 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000d4 = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000d0 == 0) {
      FUN_02196038();
    }
    puVar4 = (undefined4 *)FUN_021a3690(0x44);
    if (puVar4 == (undefined4 *)0x0) {
      FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x02195670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(1);
      return;
    }
    *puVar4 = 0;
    func_0x0213a2d0(puVar4 + 1,unaff_r5 + 0x17);
    puVar4[0xe] = 0;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puStack00000000 = &stack0x000002f0;
    iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
    if (iVar3 != 0) {
      FUN_02196054();
    }
    iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195924);
    if (iVar3 != 0) {
      FUN_021965a0(unaff_r7,1,DAT_0219591c);
      FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x021956cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE_00)(3);
      return;
    }
    bVar2 = false;
    do {
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) {
        FUN_02196054();
      }
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195928);
      if (iVar3 == 0) {
        iVar3 = FUN_021a3678(puVar4[0xf],(puVar4[0xe] + 1) * 4);
        if (iVar3 == 0) {
          FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219571c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(1);
          return;
        }
        puVar4[0xf] = iVar3;
        iVar3 = FUN_021a3690(0x1f);
        if (iVar3 == 0) {
          FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219573e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(1);
          return;
        }
        *(int *)(puVar4[0xf] + puVar4[0xe] * 4) = iVar3;
        FUN_02196914(*(undefined4 *)(puVar4[0xf] + puVar4[0xe] * 4),&stack0x000002f0,0x1f);
        puVar4[0xe] = puVar4[0xe] + 1;
      }
      else {
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_0219592c);
        if (iVar3 == 0) {
          if (0 < (int)puVar4[0xe]) {
            iVar3 = FUN_021a3678(puVar4[0x10],puVar4[0xe] << 2);
            if (iVar3 == 0) {
              FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x02195792. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*UNRECOVERED_JUMPTABLE_00)(1);
              return;
            }
            puVar4[0x10] = iVar3;
            iVar3 = FUN_021a3690(0x15);
            if (iVar3 == 0) {
              FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021957b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*UNRECOVERED_JUMPTABLE_00)(1);
              return;
            }
            *(int *)(puVar4[0x10] + (puVar4[0xe] + -1) * 4) = iVar3;
            FUN_02196914(*(undefined4 *)(puVar4[0x10] + (puVar4[0xe] + -1) * 4),&stack0x000002f0,
                         0x15);
          }
        }
        else {
          iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195930);
          if (iVar3 != 0) {
            FUN_021965a0(unaff_r7,1,DAT_0219591c);
            FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          bVar2 = true;
        }
      }
      if (bVar2) {
        puStack00000000 = in_stack_0000001c;
        iStack00000004 = 3;
        iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000d0,in_stack_000000d4,puVar4);
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
  if (iVar3 == 4) {
    in_stack_000000c8 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000cc = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000c8 != 0) {
      puVar4 = (undefined4 *)FUN_021a3690(0x10);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x0219586e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      puVar4[1] = *(undefined4 *)((int)unaff_r5 + DAT_02195934);
      bVar2 = false;
      *puVar4 = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      do {
        puStack00000000 = &stack0x000002f0;
        iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
        if (iVar3 != 0) goto code_r0x02196054;
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195938);
        if (iVar3 == 0) {
          bVar2 = true;
        }
        else {
          iVar3 = func_0x0213a074(&stack0x000000f0,DAT_0219593c);
          if (iVar3 != 0) {
            FUN_021965a0(unaff_r7,1,DAT_02195cf0);
            FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195a04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          puVar4[2] = puVar4[2] + 1;
          uVar6 = FUN_021a3678(puVar4[3],DAT_02195940 * puVar4[2]);
          puVar4[3] = uVar6;
          iVar3 = puVar4[3];
          if (iVar3 == 0) {
            FUN_02196590(unaff_r7,DAT_02195920);
                    /* WARNING: Could not recover jumptable at 0x021958fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          iVar8 = DAT_02195940 * (puVar4[2] + -1);
          iVar7 = iVar3 + iVar8;
          func_0x02134de0(iVar7,0,DAT_02195940);
          *(undefined4 *)(iVar7 + 0x24) = 1;
          uVar6 = func_0x0213bf90(&stack0x000002f0);
          *(undefined4 *)(iVar3 + iVar8) = uVar6;
          bVar1 = false;
          do {
            uVar6 = in_stack_00000094;
            puStack00000000 = &stack0x000002f0;
            iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
            if (iVar3 != 0) goto code_r0x02196054;
            iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195cd8);
            if (iVar3 == 0) {
              FUN_02196914(iVar7 + 0x28,&stack0x000002f0,DAT_02195cdc);
            }
            else {
              iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195ce0);
              if (iVar3 == 0) {
                FUN_02196914(iVar7 + 4,&stack0x000002f0,0x1f);
              }
            }
            iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195ce4);
            if (iVar3 == 0) {
              uVar6 = func_0x0213bf90(&stack0x000002f0);
              *(undefined4 *)(iVar7 + 0x24) = uVar6;
            }
            else {
              iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195ce8);
              if ((iVar3 == 0) ||
                 (iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195cec), iVar3 == 0)) {
                bVar1 = true;
                in_stack_00000094 = uVar6;
              }
            }
          } while (!bVar1);
        }
      } while (!bVar2);
      puStack00000000 = in_stack_0000001c;
      iStack00000004 = 4;
      iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000c8,in_stack_000000cc,puVar4);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195a32. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar3 == 5) {
    in_stack_000000c0 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000c4 = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000c0 != 0) {
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195cf4);
      if (iVar3 != 0) {
        FUN_021965a0(unaff_r7,1,DAT_02195cf0);
        FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195a8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      iVar3 = func_0x0213bf90(&stack0x000002f0);
      if (iVar3 == 0) {
        iVar8 = FUN_021967b4(unaff_r5[2],DAT_02195cfc,&stack0x000002f0,DAT_02195d00);
        if (iVar8 == 0) {
          FUN_021965a0(unaff_r7,1,DAT_02195cf0);
          FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195ad2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        iVar8 = func_0x0213bf90(&stack0x000002f0);
      }
      else {
        *(int *)(in_stack_00000028 + DAT_02195cf8) = iVar3;
        iVar8 = 0;
      }
      piVar5 = (int *)FUN_021a3690(8);
      if (piVar5 == (int *)0x0) {
        FUN_02196590(unaff_r7,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *piVar5 = iVar3;
      piVar5[1] = iVar8;
      puStack00000000 = in_stack_0000001c;
      iStack00000004 = 0;
      iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000c0,in_stack_000000c4);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195b24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar3 == 6) {
    in_stack_000000b8 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000bc = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000b8 != 0) {
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195d08);
      if (iVar3 != 0) {
        FUN_021965a0(unaff_r7,1,DAT_02195cf0);
        FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195b7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      iVar3 = func_0x0213bf90(&stack0x000002f0);
      if (iVar3 != 0) {
        *(int *)(in_stack_00000028 + DAT_02195cf8) = iVar3;
      }
      iVar8 = FUN_021967b4(unaff_r5[2],DAT_02195cfc,&stack0x000002f0,DAT_02195d00);
      if (iVar8 == 0) {
        if (iVar3 == 0) {
          FUN_021965a0(unaff_r7,1,DAT_02195cf0);
          FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195bc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*UNRECOVERED_JUMPTABLE_00)(3);
          return;
        }
        iVar8 = 0;
      }
      else {
        iVar8 = func_0x0213bf90(&stack0x000002f0);
      }
      piVar5 = (int *)FUN_021a3690(8);
      if (piVar5 == (int *)0x0) {
        FUN_02196590(unaff_r7,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195bf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *piVar5 = iVar3;
      piVar5[1] = iVar8;
      puStack00000000 = in_stack_0000001c;
      iStack00000004 = 0;
      iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000b8,in_stack_000000bc);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195c1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar3 == 7) {
    in_stack_000000b0 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000b4 = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000b0 != 0) {
      puVar4 = (undefined4 *)FUN_021a3690(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_02196590(unaff_r7,DAT_02195d04);
                    /* WARNING: Could not recover jumptable at 0x02195c52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195d0c);
      if (iVar3 != 0) {
        FUN_021965a0(unaff_r7,1,DAT_02195cf0);
        FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195c9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      bVar2 = false;
      do {
        puStack00000000 = &stack0x000002f0;
        iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
        if (iVar3 != 0) goto code_r0x02196054;
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195d10);
        if (iVar3 == 0) {
          bVar2 = true;
        }
        else {
          iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02195d14);
          if (iVar3 != 0) {
            FUN_021965a0(unaff_r7,1,DAT_02196080);
            FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195e6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          iVar3 = FUN_021a3678(puVar4[2],(puVar4[1] + 1) * 0xac);
          if (iVar3 == 0) {
            FUN_02196590(unaff_r7,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          puVar4[2] = iVar3;
          iVar3 = puVar4[2];
          iVar8 = puVar4[1];
          iVar7 = iVar3 + iVar8 * 0xac;
          func_0x02134de0(iVar7,0,0xac);
          puVar4[1] = puVar4[1] + 1;
          uVar6 = func_0x0213bf90(&stack0x000002f0);
          *(undefined4 *)(iVar3 + iVar8 * 0xac) = uVar6;
          bVar1 = false;
          do {
            uVar6 = in_stack_00000094;
            puStack00000000 = &stack0x000002f0;
            iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
            if (iVar3 != 0) goto code_r0x02196054;
            iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196064);
            if (iVar3 == 0) {
              FUN_02196914(iVar7 + 4,&stack0x000002f0,0x1f);
            }
            else {
              iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196068);
              if (iVar3 == 0) {
                FUN_02196914(iVar7 + 0x23,&stack0x000002f0,0x15);
              }
              else {
                iVar3 = func_0x0213a074(&stack0x000000f0,DAT_0219606c);
                if (iVar3 == 0) {
                  FUN_02196914(iVar7 + 0x38,&stack0x000002f0,0x1f);
                }
                else {
                  iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196070);
                  if (iVar3 == 0) {
                    FUN_02196914(iVar7 + 0x57,&stack0x000002f0,0x1f);
                  }
                  else {
                    iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196074);
                    if (iVar3 == 0) {
                      FUN_02196914(iVar7 + 0x76,&stack0x000002f0,0x33);
                    }
                    else {
                      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196078);
                      if ((iVar3 == 0) ||
                         (iVar3 = func_0x0213a074(&stack0x000000f0,DAT_0219607c), iVar3 == 0)) {
                        bVar1 = true;
                        in_stack_00000094 = uVar6;
                      }
                    }
                  }
                }
              }
            }
          } while (!bVar1);
        }
      } while (!bVar2);
      puStack00000000 = in_stack_0000001c;
      iStack00000004 = 8;
      iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000b0,in_stack_000000b4,puVar4);
      if (iVar3 != 0) {
                    /* WARNING: Could not recover jumptable at 0x02195e9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)();
        return;
      }
    }
  }
  else if (iVar3 == 8) {
    in_stack_000000a8 = *(int *)(in_stack_0000001c + 0xc);
    in_stack_000000ac = *(undefined4 *)(in_stack_0000001c + 0x10);
    if (in_stack_000000a8 != 0) {
      iStack00000038 = 0;
      puVar4 = (undefined4 *)FUN_021a3690(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_02196590(unaff_r7,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195ed8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puStack00000000 = &stack0x000002f0;
      iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
      if (iVar3 != 0) goto code_r0x02196054;
      iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196084);
      if (iVar3 != 0) {
        FUN_021965a0(unaff_r7,1,DAT_02196080);
        FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02195f24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(3);
        return;
      }
      uVar6 = func_0x0213bf90(&stack0x000002f0);
      puVar4[1] = uVar6;
      uVar6 = FUN_021a3690(puVar4[1] << 2);
      puVar4[2] = uVar6;
      if (puVar4[2] == 0) {
        FUN_02196590(unaff_r7,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195f52. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE_00)(1);
        return;
      }
      iVar8 = 0;
      bVar2 = false;
      do {
        puStack00000000 = &stack0x000002f0;
        iVar3 = FUN_021965c8(unaff_r7,unaff_r5[2],&stack0x00000094,&stack0x000000f0);
        if (iVar3 != 0) goto code_r0x02196054;
        iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196064);
        if (iVar3 == 0) {
          uVar6 = FUN_021a3690(0x15);
          *(undefined4 *)(puVar4[2] + iVar8) = uVar6;
          if (*(int *)(puVar4[2] + iVar8) == 0) {
            FUN_02196590(unaff_r7,DAT_02196060);
                    /* WARNING: Could not recover jumptable at 0x02195fa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(1);
            return;
          }
          FUN_02196914(*(int *)(puVar4[2] + iVar8),&stack0x000002f0,0x15);
          iVar8 = iVar8 + 4;
          iStack00000038 = iStack00000038 + 1;
        }
        else {
          iVar3 = func_0x0213a074(&stack0x000000f0,DAT_02196088);
          if (iVar3 != 0) {
            FUN_021965a0(unaff_r7,1,DAT_02196080);
            FUN_02190f4c(unaff_r7,3,1);
                    /* WARNING: Could not recover jumptable at 0x02196000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE_00)(3);
            return;
          }
          if (iStack00000038 != puVar4[1]) {
            func_0x0213442c(DAT_0219608c,DAT_02196090,0,DAT_02196094);
          }
          puVar4[1] = iStack00000038;
          bVar2 = true;
        }
      } while (!bVar2);
      puStack00000000 = in_stack_0000001c;
      iStack00000004 = 9;
      iVar3 = FUN_02190ed4(unaff_r7,in_stack_000000a8,in_stack_000000ac,puVar4);
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
  *(undefined4 *)((int)unaff_r5 + DAT_021960a0) = 1;
  iVar3 = 0;
code_r0x02196054:
                    /* WARNING: Could not recover jumptable at 0x0219605e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE_00)(iVar3);
  return;
}

